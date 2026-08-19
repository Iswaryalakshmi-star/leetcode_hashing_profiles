#include <stdbool.h>

#define N 9

// Checks if it's legal to assign num to the given row, col
bool isValid(char** grid, int row, int col, char num) {
    // Check row
    for (int x = 0; x < N; x++) {
        if (grid[row][x] == num) {
            return false;
        }
    }

    // Check column
    for (int x = 0; x < N; x++) {
        if (grid[x][col] == num) {
            return false;
        }
    }

    // Check 3x3 sub-box
    int startRow = row - row % 3;
    int startCol = col - col % 3;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (grid[i + startRow][j + startCol] == num) {
                return false;
            }
        }
    }

    return true;
}

// Backtracking function to solve Sudoku
bool solve(char** grid) {
    int row = -1;
    int col = -1;
    bool isEmpty = false;

    // Find the first empty cell
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (grid[i][j] == '.') {
                row = i;
                col = j;
                isEmpty = true;
                break;
            }
        }
        if (isEmpty) {
            break;
        }
    }

    // No empty cell left, puzzle solved
    if (!isEmpty) {
        return true;
    }

    // Try digits '1' through '9'
    for (char num = '1'; num <= '9'; num++) {
        if (isValid(grid, row, col, num)) {
            grid[row][col] = num; // Tentative assignment

            if (solve(grid)) {
                return true;
            }

            grid[row][col] = '.'; // Backtrack
        }
    }

    return false; // Triggers backtracking
}

// The standard entry function required by LeetCode / competitive platforms
void solveSudoku(char** board, int boardSize, int* boardColSize) {
    solve(board);
}
