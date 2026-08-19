#include <string.h>

int lengthOfLongestSubstring(char* s) {
    int last_seen[128];
    memset(last_seen, -1, sizeof(last_seen));
    
    int left = 0;
    int max_len = 0;
    
    for (int right = 0; s[right] != '\0'; right++) {
        unsigned char current_char = s[right];
        
        if (last_seen[current_char] >= left) {
            left = last_seen[current_char] + 1;
        }
        
        last_seen[current_char] = right;
        
        int current_len = right - left + 1;
        if (current_len > max_len) {
            max_len = current_len;
        }
    }
    
    return max_len;
}
