#include <stdlib.h>
#include <string.h>

char* intToRoman(int num) {
    // Arrays representing values and their corresponding Roman symbols
    int values[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
    char* symbols[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
    
    // Allocate memory for the longest possible Roman representation (e.g., 3888 -> "MMMDCCCLXXXVIII")
    char* roman = (char*)malloc(20 * sizeof(char));
    roman[0] = '\0'; // Start with an empty string

    for (int i = 0; i < 13; i++) {
        // Append the symbol while the number is greater than or equal to its value
        while (num >= values[i]) {
            strcat(roman, symbols[i]);
            num -= values[i];
        }
    }
    
    return roman;
}
