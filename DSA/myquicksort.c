#include "myheaders.h"
#define MAX 5

// Global declerations
int iarr[MAX] = {3, 1, 2, 6, 5};
int partition(int, int);
void swap(int*, int*);
int quicksort(int, int);

int main(void) {
    int i = 0;
    quicksort(0, MAX-1);
    while(i < MAX) {
        printf("%d ", *(iarr+i++));
    }

    printf("\n");
    return 0;
}

void swap(int *a, int *b) {
    *a ^= *b;
    *b ^= *a;
    *a ^= *b;
}

int partition(int low, int high) {
    int leftwall, pivot;

    pivot = iarr[low];
    leftwall = low;

    for(int i = low + 1; i <= high; i ++) {
        if(pivot > iarr[i]) {
            swap(&iarr[leftwall], &iarr[i]);
            ++leftwall;
        }
    }

    swap(&iarr[leftwall], &pivot);

    return leftwall;
}

int quicksort(int low, int high) {
    int pivot;

    if (low < high) {
        pivot = partition(low, high);
        quicksort(low, pivot);
        quicksort(pivot+1, high);
    }
}