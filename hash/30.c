#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int* findSubstring(char* s, char** words, int wordsSize, int* returnSize) {
    *returnSize = 0;
    if (!s || wordsSize == 0 || !words) return NULL;

    int sLen = strlen(s);
    int wordLen = strlen(words[0]); // Fixed: words[0] length
    int totalLen = wordsSize * wordLen;

    if (sLen < totalLen) return NULL;

    int* result = (int*)malloc(sLen * sizeof(int));
    
    // Allocate count tables based on unique words
    int* targetCounts = (int*)calloc(wordsSize, sizeof(int));
    int* currentCounts = (int*)calloc(wordsSize, sizeof(int));
    
    // Track unique words to deduplicate and speed up comparison
    bool* isUniqueHead = (bool*)calloc(wordsSize, sizeof(bool));
    for (int i = 0; i < wordsSize; i++) {
        isUniqueHead[i] = true;
        for (int j = 0; j < i; j++) {
            if (strcmp(words[i], words[j]) == 0) {
                targetCounts[j]++;
                isUniqueHead[i] = false;
                break;
            }
        }
        if (isUniqueHead[i]) {
            targetCounts[i] = 1;
        }
    }

    char* tempWord = (char*)malloc((wordLen + 1) * sizeof(char));

    // Slide window with wordLen different starting offsets
    for (int i = 0; i < wordLen; i++) {
        int left = i;
        int right = i;
        int wordsUsed = 0;
        memset(currentCounts, 0, wordsSize * sizeof(int));

        while (right + wordLen <= sLen) {
            strncpy(tempWord, s + right, wordLen);
            tempWord[wordLen] = '\0';
            right += wordLen;

            // Find match in original words array
            int wordIdx = -1;
            for (int j = 0; j < wordsSize; j++) {
                if (isUniqueHead[j] && strcmp(words[j], tempWord) == 0) {
                    wordIdx = j;
                    break;
                }
            }

            if (wordIdx != -1) {
                currentCounts[wordIdx]++;
                wordsUsed++;

                // If word count exceeds target, shrink from left
                while (currentCounts[wordIdx] > targetCounts[wordIdx]) {
                    char* leftWord = (char*)malloc((wordLen + 1) * sizeof(char));
                    strncpy(leftWord, s + left, wordLen);
                    leftWord[wordLen] = '\0';

                    for (int j = 0; j < wordsSize; j++) {
                        if (isUniqueHead[j] && strcmp(words[j], leftWord) == 0) {
                            currentCounts[j]--;
                            break;
                        }
                    }
                    free(leftWord);
                    wordsUsed--;
                    left += wordLen;
                }

                if (wordsUsed == wordsSize) {
                    result[(*returnSize)++] = left;
                }
            } else {
                // Invalid word: reset the current window entirely
                memset(currentCounts, 0, wordsSize * sizeof(int));
                wordsUsed = 0;
                left = right;
            }
        }
    }

    free(tempWord);
    free(targetCounts);
    free(currentCounts);
    free(isUniqueHead);
    
    return result;
}
