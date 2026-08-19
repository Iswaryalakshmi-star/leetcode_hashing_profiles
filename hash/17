#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Global keypad mapping array
const char* KEYPAD[] = {
    "",     // 0
    "",     // 1
    "abc",  // 2
    "def",  // 3
    "ghi",  // 4
    "jkl",  // 5
    "mno",  // 6
    "pqrs", // 7
    "tuv",  // 8
    "wxyz"  // 9
};

// Helper function to perform backtracking DFS
void backtrack(const char* digits, int index, char* current, char** result, int* returnSize) {
    // Base Case: If we have processed all digits, store the combination
    if (digits[index] == '\0') {
        result[*returnSize] = strdup(current);
        (*returnSize)++;
        return;
    }

    int digit = digits[index] - '0';
    const char* letters = KEYPAD[digit];

    // Loop through all letters mapped to the current digit
    for (int i = 0; letters[i] != '\0'; i++) {
        current[index] = letters[i];
        current[index + 1] = '\0'; // Temporarily terminate string
        
        backtrack(digits, index + 1, current, result, returnSize);
    }
}

char** letterCombinations(char* digits, int* returnSize) {
    *returnSize = 0;
    int len = strlen(digits);
    
    // Edge case: empty input string
    if (len == 0) {
        return NULL;
    }

    // Step 1: Calculate max possible combinations to allocate enough memory
    int maxCombinations = 1;
    for (int i = 0; i < len; i++) {
        int digit = digits[i] - '0';
        if (digit == 7 || digit == 9) {
            maxCombinations *= 4;
        } else {
            maxCombinations *= 3;
        }
    }

    // Step 2: Allocate memory for results array and working buffer
    char** result = (char**)malloc(maxCombinations * sizeof(char*));
    char* current = (char*)malloc((len + 1) * sizeof(char));

    // Step 3: Run backtracking
    backtrack(digits, 0, current, result, returnSize);

    // Free the temporary workspace string buffer
    free(current);
    
    return result;
}
