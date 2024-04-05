#include <stdio.h>
#include <stdlib.h>

static int size_arr;
static long *iarr;
static void quicksort(int, int);
static int partition(int, int);
static int swap(long*, long*);

int main() {
    int i = 0;

    (void)printf("What is the size of array?");
    (void)scanf("%d", &size_arr);

    iarr = (long*) malloc(size_arr * sizeof(long int));
    if(iarr == NULL) {
        exit(EXIT_FAILURE);
    }

    *iarr = 0;    


    (void)printf("Array Input: ");
    while(i < size_arr) {
        (void)scanf("%ld", (iarr+i++));
    }

    quicksort(0, size_arr-1);

    (void)printf("Array Sorted: ");
    i = 0;
    while(i < size_arr) {
        (void)printf("%ld ", *(iarr+i++));
    }

    (void)printf("\n");
    free(iarr);

    return 0;
}

int swap(long *a, long *b) {
    if(a == NULL || b == NULL) {
            return 1;
    }
    *a = *a ^ *b;
    *b = *a ^ *b;
    *a = *a ^ *b;

    return 0;
}

int partition(int low, int high) {
    long pivot = iarr[low];
    int leftwall = (int)low;
    int i;

    for(i = low + 1; i <= high; i++) {
        if(pivot > iarr[i]) {
            swap(&iarr[i], &iarr[leftwall]);
            ++leftwall;
        }
    }
    
    int retval = swap(&iarr[leftwall], &pivot);
    
    if(retval == 1) {
        exit(1);
    }

    return leftwall;
}

void quicksort(int low, int high) {
    if(low < high) {
        int pivot = partition(low, high);
        quicksort(low, pivot);
        quicksort(pivot+1, high);
    }
}
