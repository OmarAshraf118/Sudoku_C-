#ifndef SUDOKU_BOARD_HPP
#define SUDOKU_BOARD_HPP

#include <vector>

class SudokuBoard
{
private:
    std::vector< std::vector<int> > board;

public:
    SudokuBoard();
    SudokuBoard(const std::vector< std::vector<int> >& initial_board);

    void setValueOnBoard(const int& row, const int& col, const int& value);

    // void checkRowValidity(int row); 
    // void checkColValidity(int col);
    // void checkValueValidity(int value);

    bool checkAppliedGameConstraints(const int& row, const int& col, const int& value) const;
    bool checkRowConstraints(const int& row, const int& value) const;
    bool checkColConstraints(const int& col, const int& value) const;
    bool checkBoxConstraints(const int& row, const int& col, const int& value) const;

    void displayBoard() const;
    // stores and manipulates 9 * 9 grid
        // load a puzzle into the 9 * 9 matrix
        // set value in the puzzle if valid
    // (check that each no. from 1~9 appears only once)
        // validates row constraints 
        // validates col constraints
        // validates box constraints
    // prints the board

    friend class SudokuSolver; // Allow SudokuSolver to access private members
    
};

#endif