#include <stdio.h>
#include <math.h>

long long reverse(long long x);

long long reverse(long long x){
    long long rev = 0, iter = 0;
    while(x) {
        rev *= 10;
        rev += x % 10;
        x = x / 10;
    }

    return rev;
}

int main(void) {
    long long rev = reverse(1534236469);

    printf("%lld", rev);

    return 0;
}