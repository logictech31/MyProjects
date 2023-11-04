#include "myheaders.h"

int size_arr;
long *iarr;
void quicksort(int, int);
int partition(int, int);
void swap(long*, long*);

int main() {
    int i = 0;

    printf("What is the size of array?");
    scanf("%d", &size_arr);

    iarr = (long*) malloc(size_arr * sizeof(long));

    if(iarr == NULL) {
        return -1;
    }

    printf("Array Input: ");
    while(i < size_arr) {
        scanf("%d", (iarr+i++));
    }

    quicksort(0, size_arr-1);

    printf("Array Sorted: ");
    i = 0;
    while(i < size_arr) {
        printf("%d ", *(iarr+i++));
    }

    printf("\n");
    free(iarr);

    return 0;
}

void swap(long *a, long *b) {
    long temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int low, int high) {
    long pivot = iarr[low];
    long leftwall = (long)low;
    int i;

    for(i = low + 1; i <= high; i++) {
        if(pivot > iarr[i]) {
            swap(&iarr[i], &iarr[leftwall]);
            ++leftwall;
        }
    }
    
    swap(&iarr[leftwall], &pivot);

    return leftwall;
}

void quicksort(int low, int high) {
    if(low < high) {
        int pivot = partition(low, high);
        quicksort(low, pivot);
        quicksort(pivot+1, high);
    }
}