#include <string.h>

// 1. Helper function must be declared first
int getRomanValue(char c) {
    switch (c) {
        case 'I': return 1;
        case 'V': return 5;
        case 'X': return 10;
        case 'L': return 50;
        case 'C': return 100;
        case 'D': return 500;
        case 'M': return 1000;
        default:  return 0;
    }
}

// 2. The main solution function called by LeetCode/HackerRank
int romanToInt(char* s) {
    int total = 0;
    int len = strlen(s);
    
    for (int i = 0; i < len; i++) {
        int current = getRomanValue(s[i]);
        
        // If a smaller value precedes a larger value, subtract it
        if (i + 1 < len && getRomanValue(s[i + 1]) > current) {
            total -= current;
        } else {
            total += current;
        }
    }
    
    return total;
}
