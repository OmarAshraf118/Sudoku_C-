#include "../include/SudokuGame.hpp"
#include "../include/SudokuSolver.hpp"
#include <iostream>

typedef enum
{
    dummy_value , Enter_a_move, Solve_automatically,
    Load_puzzle_from_file, Save_current_puzzle_to_file,
    Exit
}menuOptions;

void SudokuGame::gameLoop(SudokuBoard &gameBoard)
{
    int userChoice = dummy_value;
    while (userChoice!=Exit)
    {
        gameBoard.displayBoard();
        displayMenu();
        std::cin>>userChoice;   //get user choice

        if(checkValidMenuOption(userChoice))
        {
            applyUserChoice(userChoice, gameBoard);
        }
        else
        {
            std::cout<<"Invalide input. choose a correct number."<<std::endl;
            userChoice = dummy_value; //reset user choice variable
        }

    }
}

void SudokuGame::displayMenu()
{
    std::cout<<"1) Enter a move"<<std::endl;
    std::cout<<"2) Solve automatically"<<std::endl;
    std::cout<<"3) Load puzzle from file"<<std::endl;
    std::cout<<"4) Save current puzzle to file"<<std::endl;
    std::cout<<"5) Exit" << std::endl;
    std::cout<<"Choice: ";
}

bool SudokuGame::checkValidMenuOption(const int& userChoice)
{
    //if choice is within menu options
    if(userChoice>=1 && userChoice<=5)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void SudokuGame::applyUserChoice(int &userChoice, SudokuBoard& gameBoard)
{
    switch (userChoice)
    {
    case Enter_a_move:
        getUserMove(gameBoard);
        break;
    case Solve_automatically:
        solvePuzzleAutomatically(gameBoard);
        break;
    case Load_puzzle_from_file:
        //loadPuzzleFromFile();
        break;
    case Save_current_puzzle_to_file:
        //savePuzzleToFile();
        break;
    case Exit:
        break;
    default:
        break;
    }
}

void SudokuGame::getUserMove(SudokuBoard &gameBoard)
{
    int row, col, val;
    std::cout<<"Enter row (1-9), column (1-9), and value (1-9): ";
    std::cin>>row>>col>>val;

    if(row < 1 || row > 9)
    {
        std::cout<<"Row must be between 1 and 9"<<std::endl;
        return;
    }

    if(col < 1 || col > 9)
    {
        std::cout<<"Column must be between 1 and 9"<<std::endl;
        return;
    }

    if(val < 1 || val > 9)
    {
        std::cout<<"Value must be between 1 and 9"<<std::endl;
        return;
    }

    if(gameBoard.checkAppliedGameConstraints(row,col,val))
    {
        std::cout<<"Move accepted!"<<std::endl;
        gameBoard.setValueOnBoard(row,col,val);
    }

    return;

}

void SudokuGame::solvePuzzleAutomatically(SudokuBoard &gameBoard)
{
    std::cout << "Attempting to solve the puzzle..." << std::endl;
    
    bool solved = SudokuSolver::solveSudoku(gameBoard);
    
    if (solved) 
    {
        std::cout << "Puzzle solved successfully!" << std::endl;
        gameBoard.displayBoard(); // Show the solved board
    } 
    else 
    {
        std::cout << "Could not solve the puzzle. It may be unsolvable." << std::endl;
    }
}