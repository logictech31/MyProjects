#include <stdio.h>

union CharInt {
    int i;
    float f;
    char c;
}; 
union CharInt func() {
    union CharInt v1;

    printf("Works!\n");
    scanf("%d", &v1.i);

    return v1;
}

int main() {
    union CharInt ret = func();
}