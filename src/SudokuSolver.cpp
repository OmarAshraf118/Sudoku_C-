#include "../include/SudokuSolver.hpp"

constexpr int SIZE = 9; // Size of the Sudoku board
constexpr int EMPTY = 0; // Empty cell representation

bool SudokuSolver::solveSudoku(SudokuBoard &gameBoard, int row, int col)
{
            // If we've reached the end, return true
            if (row == SIZE - 1 && col == SIZE)
            return true;
    
        // Move to next row if at end of current row
        if (col == SIZE) {
            row++;
            col = 0;
        }
    
        // Skip already filled cells
        if (gameBoard.board[row][col] != EMPTY)
            return solveSudoku(gameBoard, row, col + 1);
    
        // Try numbers 1 through 9
        for (int num = 1; num <= SIZE; num++) {
            if (gameBoard.checkAppliedGameConstraints(row, col, num)) {
                gameBoard.board[row][col] = num;
                if (solveSudoku(gameBoard, row, col + 1))
                    return true;
                gameBoard.board[row][col] = EMPTY; // Backtrack
            }
        }
        return false; // Trigger backtracking
}