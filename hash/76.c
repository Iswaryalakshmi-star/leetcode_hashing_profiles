#include <stdio.h>
#include <string.h>
#include <limits.h>

char* minWindow(char* s, char* t) {
    int m = strlen(s);
    int n = strlen(t);
    
    // Edge case: if s is shorter than t, a valid window is impossible
    if (m < n || m == 0 || n == 0) {
        return "";
    }

    // Frequency arrays for ASCII characters
    int t_count[128] = {0};
    int window_count[128] = {0};

    // Count unique characters needed from t
    int required = 0;
    for (int i = 0; i < n; i++) {
        if (t_count[(int)t[i]] == 0) {
            required++;
        }
        t_count[(int)t[i]]++;
    }

    int left = 0, right = 0;
    int formed = 0;
    
    // Variables to track the minimum window
    int min_len = INT_MAX;
    int start_idx = 0;

    while (right < m) {
        char c = s[right];
        window_count[(int)c]++;

        // Check if the current character satisfies the frequency requirement
        if (t_count[(int)c] > 0 && window_count[(int)c] == t_count[(int)c]) {
            formed++;
        }

        // Try to contract the window from the left
        while (left <= right && formed == required) {
            char left_c = s[left];

            // Update the minimum window data
            if (right - left + 1 < min_len) {
                min_len = right - left + 1;
                start_idx = left;
            }

            // Remove the leftmost character from the window
            window_count[(int)left_c]--;
            if (t_count[(int)left_c] > 0 && window_count[(int)left_c] < t_count[(int)left_c]) {
                formed--;
            }
            left++;
        }
        right++;
    }

    // If min_len was never updated, no valid window exists
    if (min_len == INT_MAX) {
        return "";
    }

    // Null-terminate the string at the end of the minimum window
    s[start_idx + min_len] = '\0';
    return &s[start_idx];
}
