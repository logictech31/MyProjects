#include <stdio.h>
#include <stdlib.h>
#define MAX 10

int sayHi() {
    printf("Hi!");
    return 56;
}

int main() {
    int (*ptr_to_func[MAX])() = {&sayHi};
    int ret;

    ret = (*ptr_to_func[0])();
    printf("ret = %d\n",ret);
    
    union CharInt {
        char a;
        int b;
    }v1;

    v1.a = 'A';

    printf("%d = %c (%ld)", v1.b, v1.a, sizeof(v1));
    printf("\n");
    
    
    return 0;
}