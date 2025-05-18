#ifndef SUDOKU_SOLVER_HPP
#define SUDOKU_SOLVER_HPP

#include "SudokuBoard.hpp"
#include <vector>


class SudokuSolver
{
public:
    static bool solveSudoku(SudokuBoard &gameBoard, int row = 0, int col = 0);
    
};

#endif 