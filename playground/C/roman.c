#include <stdio.h>
#include <stdlib.h>

int intOfRoman(char x) {
    switch(x) {
        case 'I':
            return 1;
        case 'V':
            return 5;
        case 'X':
            return 10;
        case 'L':
            return 50;
        case 'C':
            return 100;
        case 'D':
            return 500;
        case 'M':
            return 1000;
        default:
            return 0;
    }
}

int romanToInt(char* s) {
    int sum = 0, iter = 0;
    while(s[iter] != '\0')
        sum += handle_roman(&s[iter++], iter);

    return sum;
}


int main(void) {
    char s[] = {'M', 'C', 'M', 'X', 'C', 'I', 'V'};

    int sum = romanToInt(s);
    printf("%d", sum);
    return 0;
}