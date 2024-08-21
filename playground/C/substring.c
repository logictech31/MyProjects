#include <string.h>
#include <stdio.h>
#include <stdbool.h>
int lengthOfLongestSubstring(char* s) {
    int len = strlen(s);
    int substrLen = 0, i = 0, j = 0, k = 0, max = 0;
    char substr[len+1];
    bool unique = true;

    memset(substr, '\0', len + 1);

    while (s[i] != '\0') {
        // Check if the character is unique
        for(j = 0; j < substrLen; j ++) {
            if (substr[j] == s[i]) {
                unique = false;
                break;
            } else {
                unique = true;
            }
        }
        // If the entry is unique then we add it to substring
        // else we reset
        if (unique == false) {
            memset(substr, '\0', j);
            k = 0;
            substr[k++] = s[i];
            substrLen = strlen(substr);
        } else {
            substr[k++] = s[i];
            substrLen++;
        }
        max = (max < substrLen) ? substrLen : max;
        i++;
    }


    return max;
}

int main() {
    printf("%d", lengthOfLongestSubstring("pwwkew"));
}
