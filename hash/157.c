#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Helper function to map DNA characters to 2-bit values
int charToBits(char c) {
    switch (c) {
        case 'A': return 0; // 00
        case 'C': return 1; // 01
        case 'G': return 2; // 10
        case 'T': return 3; // 11
        default:  return 0;
    }
}

char** findRepeatedDnaSequences(char* s, int* returnSize) {
    int len = strlen(s);
    *returnSize = 0;

    // Edge case: if string is shorter than 10, no sequence can repeat
    if (len < 10) {
        return NULL;
    }

    // Direct mapping array for all possible 20-bit combinations (4^10 = 1048576)
    // 0 = unseen, 1 = seen once, 2 = already added to results
    unsigned char* bit_map = (unsigned char*)calloc(1048576, sizeof(unsigned char));
    
    // Allocate initial space for results memory dynamically
    int capacity = 16;
    char** result = (char**)malloc(capacity * sizeof(char*));

    int bit_mask = 0xFFFFF; // Mask to keep only the lowest 20 bits
    int current_hash = 0;

    // Initialize the rolling hash window for the first 9 characters
    for (int i = 0; i < 9; i++) {
        current_hash = (current_hash << 2) | charToBits(s[i]);
    }

    // Slide the 10-letter window across the remaining characters
    for (int i = 9; i < len; i++) {
        // Shift left, insert new 2 bits, and mask out anything beyond 20 bits
        current_hash = ((current_hash << 2) | charToBits(s[i])) & bit_mask;

        if (bit_map[current_hash] == 1) {
            // Sequence seen exactly once before -> It is a duplicate!
            if (*returnSize >= capacity) {
                capacity *= 2;
                result = (char**)realloc(result, capacity * sizeof(char*));
            }
            
            // Extract the 10-letter substring
            result[*returnSize] = (char*)malloc(11 * sizeof(char));
            strncpy(result[*returnSize], &s[i - 9], 10);
            result[*returnSize][10] = '\0'; // Null-terminate
            (*returnSize)++;

            // Mark as 2 so we don't add it again if it appears a 3rd or 4th time
            bit_map[current_hash] = 2;
        } else if (bit_map[current_hash] == 0) {
            // First time seeing this sequence
            bit_map[current_hash] = 1;
        }
    }

    free(bit_map);
    return result;
}
