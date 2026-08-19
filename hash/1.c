#include <stdlib.h>
#include <string.h>

// Simple hash map entry structure
typedef struct {
    int key;
    int value;
} HashEntry;

int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    *returnSize = 2;
    int* result = (int*)malloc(2 * sizeof(int));
    
    // Create a hash table size proportional to input size
    int tableSize = numsSize * 2;
    HashEntry* hashTable = (HashEntry*)malloc(tableSize * sizeof(HashEntry));
    
    // Initialize map table keys with a safe default flag value
    // Using a separate flag or loop initialization ensures we can track unassigned indices safely
    for(int i = 0; i < tableSize; i++) {
        hashTable[i].value = -1; 
    }

    for (int i = 0; i < numsSize; i++) {
        int complement = target - nums[i];
        
        // Find complement in the hash table
        int hashIdx = abs(complement) % tableSize;
        while (hashTable[hashIdx].value != -1) {
            if (hashTable[hashIdx].key == complement) {
                result[0] = hashTable[hashIdx].value;
                result[1] = i;
                free(hashTable);
                return result;
            }
            hashIdx = (hashIdx + 1) % tableSize; // Linear probing
        }
        
        // Insert current number into hash table
        int currentHashIdx = abs(nums[i]) % tableSize;
        while (hashTable[currentHashIdx].value != -1) {
            currentHashIdx = (currentHashIdx + 1) % tableSize;
        }
        hashTable[currentHashIdx].key = nums[i];
        hashTable[currentHashIdx].value = i;
    }
    
    free(hashTable);
    return result;
}
