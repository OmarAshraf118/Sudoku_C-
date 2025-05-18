#ifndef SUDOKU_GAME_HPP
#define SUDOKU_GAME_HPP

#include "SudokuBoard.hpp"

class SudokuGame
{
    //present menu
    //read user input
    //write user output
    //coordinate SudokuBoard and SudokuSolver
    //handle error-checking for moves and file operations
public:
    void gameLoop(SudokuBoard &gameBoard);
    bool checkValidMenuOption(const int &userChoice);
    void applyUserChoice(int &userChoice, SudokuBoard &gameBoard);
    void displayMenu();
    void getUserMove(SudokuBoard &gameBoard);
    void solvePuzzleAutomatically(SudokuBoard &gameBoard);
    // void loadPuzzleFromFile();
    // void savePuzzleToFile();
};
#endif