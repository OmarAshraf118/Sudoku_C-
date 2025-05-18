cmake_minimum_required(VERSION 3.10...3.28)
project(SudokuProject)

# Use C++17 (adjust if you need a different standard)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Create options for optional features
option(BUILD_GENERATOR "Build the SudokuGenerator module for puzzle generation" ON)
option(BUILD_ADVANCED "Build the SudokuAdvancedChecks module for advanced Sudoku logic" ON)

# Set source and include directories
set(SOURCE_DIR src)
set(INCLUDE_DIR include)

# List all source files with correct paths
set(SOURCES
    ${SOURCE_DIR}/main.cpp
    ${SOURCE_DIR}/SudokuBoard.cpp
    ${SOURCE_DIR}/SudokuGame.cpp
    ${SOURCE_DIR}/SudokuSolver.cpp
    ${SOURCE_DIR}/SudokuAdvancedChecks.cpp
    ${SOURCE_DIR}/SudokuGenerator.cpp
)

# Header files (not strictly required for add_executable, but good for clarity)
set(HEADERS
    ${INCLUDE_DIR}/SudokuBoard.hpp
    ${INCLUDE_DIR}/SudokuGame.hpp
    ${INCLUDE_DIR}/SudokuSolver.hpp
    ${INCLUDE_DIR}/SudokuAdvancedChecks.hpp
    ${INCLUDE_DIR}/SudokuGenerator.hpp
)

# If building puzzle generator, include its source/header
if(BUILD_GENERATOR)
    list(APPEND SOURCES src/SudokuGenerator.cpp)
    list(APPEND HEADERS include/SudokuGenerator.hpp)
endif()

# If building advanced checks, include those source/header
if(BUILD_ADVANCED)
    list(APPEND SOURCES src/SudokuAdvancedChecks.cpp)
    list(APPEND HEADERS include/SudokuAdvancedChecks.hpp)
endif()

# Create the final executable
add_executable(SudokuProject ${SOURCES} ${HEADERS})

# For example usage, you might do:
#    cmake -S . -B build -DBUILD_GENERATOR=OFF -DBUILD_ADVANCED=OFF
#    cmake --build build
#
# In that case, the project will build without the optional modules.
