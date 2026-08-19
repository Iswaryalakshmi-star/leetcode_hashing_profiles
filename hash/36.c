#include <stdbool.h>

bool isValidSudoku(char** board, int boardSize, int* boardColSize) {
    // 9 rows, 9 columns, and 9 sub-boxes
    // Using bitmasks (ints) to track numbers 1-9 for O(1) space and speed
    int rows[9] = {0};
    int cols[9] = {0};
    int boxes[9] = {0};

    for (int r = 0; r < 9; r++) {
        for (int c = 0; c < 9; c++) {
            char val = board[r][c];

            // Skip empty cells
            if (val == '.') {
                continue;
            }

            // Convert character digit '1'-'9' to integer bit position 0-8
            int num = val - '1';
            int mask = 1 << num;
            
            // Map the row and column index to a unique 3x3 box index (0 to 8)
            int box_idx = (r / 3) * 3 + (c / 3);

            // Check if the number already exists in the row, column, or sub-box
            if ((rows[r] & mask) || (cols[c] & mask) || (boxes[box_idx] & mask)) {
                return false;
            }

            // Place the number in the respective trackers
            rows[r] |= mask;
            cols[c] |= mask;
            boxes[box_idx] |= mask;
        }
    }

    return true;
}
