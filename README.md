# Sudoku Game in C++

## Overview
This project is a console-based implementation of the classic Sudoku puzzle game, developed using C++ with object-oriented programming principles and the C++ Standard Template Library (STL). The game features a modular design that separates core logic from user interface, allowing for future extensions.

## Features
- **Game Board**: 9×9 grid representation with empty cells marked as '.'
- **User Interaction**:
  - Place numbers on the board with validation
  - Automatic puzzle solving using backtracking algorithm
  - Load and save puzzles from/to files
- **Validation System**: Checks for row, column, and 3×3 box constraints
- **Optional Advanced Features**:
  - Puzzle generation with varying difficulty
  - Advanced solving techniques (locked candidates, naked pairs)

## Project Structure
```
.
├── CMakeLists.txt          # Build configuration
├── src/
│   ├── SudokuBoard.hpp     # Board representation & basic I/O
│   ├── SudokuBoard.cpp
│   ├── SudokuSolver.hpp    # Backtracking solver
│   ├── SudokuSolver.cpp
│   ├── SudokuGame.hpp      # Console interface/game loop
│   ├── SudokuGame.cpp
│   └── main.cpp            # Entry point
├── include/                # Header files
├── data/                   # Sample puzzle files
└── README.md               # This file
```

## Requirements
- C++17 compatible compiler
- CMake (version 3.10 or higher)

## Building the Project
1. Clone the repository
2. Create a build directory:
   ```
   mkdir build && cd build
   ```
3. Run CMake:
   ```
   cmake ..
   ```
4. Build the project:
   ```
   cmake --build .
   ```

## Usage
Run the compiled executable:
```
./SudokuGame
```

The program will display a menu with the following options:
1. Enter a move (row, column, value)
2. Solve automatically
3. Load puzzle from file
4. Save current puzzle to file
5. Exit

## File Format
Puzzle files should contain 9 lines with 9 characters each, where:
- Numbers 1-9 represent filled cells
- '.' or '0' represent empty cells

Example:
```
53..7....
6..195...
.98....6.
8...6...3
4..8.3..1
7...2...6
.6....28.
....419..5
....8..79
```

## Future Improvements
- Implement GUI using Qt or similar framework
- Add difficulty levels for puzzle generation
- Include more advanced solving techniques
- Add timer and scoring system

## License
This project is open-source and available under the MIT License.
