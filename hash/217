#include <stdbool.h>
#include <stdlib.h>

// Helper comparison function required by qsort
int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

// Main function to check for duplicates
bool containsDuplicate(int* nums, int numsSize) {
    // 1. Sort the array using the built-in qsort function from stdlib.h
    qsort(nums, numsSize, sizeof(int), compare);
    
    // 2. Loop through the array to check if any adjacent numbers are identical
    for (int i = 0; i < numsSize - 1; i++) {
        if (nums[i] == nums[i + 1]) {
            return true; // Duplicate found immediately
        }
    }
    
    // 3. If the loop finishes with no matches, all numbers are unique
    return false;
}

