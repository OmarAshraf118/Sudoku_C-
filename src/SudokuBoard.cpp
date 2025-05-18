// SudokuBoard 
// o Stores and manipulates the 9×9 grid. 
// o Validates row/column/box constraints. 
// o Prints the board. 
// o (Optional) Loads and saves puzzle data to a file. 
#include "../include/SudokuBoard.hpp"
#include <iostream>

// initialize the board with empty cells if no board is inputed
SudokuBoard::SudokuBoard(): board(9, std::vector<int>(9,0)){}
// initialize the board with values from an inputed puzzle 
SudokuBoard::SudokuBoard(const std::vector<std::vector<int>>& initial_board): board(initial_board){}

void SudokuBoard::setValueOnBoard(const int& row, const int& col, const int& value) 
{
    if(board[row-1][col-1] == 0)
    {
        board[row-1][col-1] = value;
    }
    else // if board position already has a number set
    {
        std::cout<<"This board location isn't empty"<<std::endl;
    }
}

bool SudokuBoard::checkAppliedGameConstraints(const int& row, const int& col, const int& value) const
{
    if(checkRowConstraints(row, value) && checkColConstraints(col, value) && checkBoxConstraints(row, col, value))
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool SudokuBoard::checkRowConstraints(const int& row, const int& value) const
{
    for(int i = 0; i < 9; i++)
    {
        if(board[row-1][i] == value)
        {
            return false;
        }
    }

    return true;
}

bool SudokuBoard::checkColConstraints(const int& col, const int& value) const
{
    for(int i = 0; i < 9; i++)
    {
        if(board[i][col-1] == value)
        {
            return false;
        }
    }

    return true;
}

bool SudokuBoard::checkBoxConstraints(const int& row, const int& col, const int& value) const
{
    int boxRowStart;
    int boxColStart;

    /*
    using switch cases map the sudoku boxes location by locating the correct
    starting point of the box where the value needs to be set
    */
    switch (row-1)
    {
    case 0:
    case 1:
    case 2:
        boxRowStart = 0;
        break;

    case 3:
    case 4:
    case 5:
        boxRowStart = 3;
        break;

    case 6:
    case 7:
    case 8:
        boxRowStart = 6;
        break;

    
    default:
        boxRowStart = -1;
        break;
    }

    switch (col-1)
    {
    case 0:
    case 1:
    case 2:
        boxColStart = 0;
        break;

    case 3:
    case 4:
    case 5:
        boxColStart = 3;
        break;

    case 6:
    case 7:
    case 8:
        boxColStart = 6;
        break;

    
    default:
        boxColStart = -1;
        break;
    }

    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            if(board[boxRowStart+i][boxColStart+j] == value)
            {
                return false;
            } 
        }
    }

    return true;

}

void SudokuBoard::displayBoard() const
{
    for(int i = 0; i < 9; i++)
    {
        if(i == 0 || i == 3 || i == 6)
        {
            std::cout<<"-------------------------"<<std::endl;   
        }

        
        for(int j = 0; j < 9; j++)
        {
            if(j == 0 || j == 3 || j == 6)
            {
                std::cout<<"| ";
            }

            if(board[i][j] == 0)
            {
                std::cout<<". ";
            }
            else
            {
                std::cout<<board[i][j]<<" ";
            }

            if(j == 8)
            {
                std::cout<<"|";
            }
        }
        std::cout<<std::endl;
    }
    std::cout<<"-------------------------"<<std::endl;
}