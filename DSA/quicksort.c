/*
    File Name: quicksort.c
    Description: Implementation of Quicksort
    Author: Hrushikesh Pandit
*/
#include "myheaders.h"
#define MAX 8

// Global Declarations
int iarr[MAX];
int quicksort(int, int);
void swap(int *, int *);
int partition(int, int);
void printArray(void);

// Main Function
int main(int argc, char *argv[]) {
    // Local variables
    int mode, i;

    if(argc > 2 || argc < 2) {
        printf("Invalid number of arguments!\n");
        return -1;
    }

    switch (*(argv[1]+1))
    {
    case 'a':
        printf("Ascending order chosen!\n");
        mode = 1;
        break;
    
    case 'd':
        printf("Descending order chosen!\n");
        mode = -1;
        break;
    default:
        printf("Invalid option!\n");
        return -1;
    }

    printf("Enter %d numbers: ", MAX);
    // While 12 inputs aren't reached
    // i is the offset here
    i = 0;
    while(i < MAX) {
        scanf("%d", iarr+i++);
    }
    // bringing offset back to 0
    printArray();

    quicksort(0, MAX-1);

    printf("\nAfter quick sort: ");
    printArray();

    // mandatory escape
    printf("\n");

    return 0;
}

// Print Array
void printArray() {
    int i = 0;
    while(i < MAX) {
        printf("%d ", *(iarr+i++));
    }
}

/*
    Swap function

    Uses XOR logic to swap
*/
void swap(int *a, int *b) {
    *a = *a ^ *b; // a = a xor b
    *b = *a ^ *b; // b = a xor b
    *a = *a ^ *b; // a = a xor b
}

// Partition Function
int partition(int low, int high) {
    int leftwall;
    int pivot;

    pivot = iarr[low];
    leftwall = low;

    for(int i = low + 1; i <= high; i++) {
        if(iarr[i] < pivot) {
            swap(&iarr[i], &iarr[leftwall]);
            ++leftwall;
        }
    }
    swap(&pivot, &iarr[leftwall]);
    return leftwall;
}
/*
    The main idea behind quicksort is that
    All the elements to the left must be lesser than pivot and all the elements to the right
    must be greater than pivot

    i.e. pivot > ele[left] && pivot < ele[right]
*/
int quicksort(int low, int high) {
    int pivot;
    if(sizeof(iarr[MAX]) == 0) {
        return -1;
    }

    if(low < high) {
        pivot = partition(low, high);
        quicksort(low, pivot);
        quicksort(pivot+1, high);
    }

    return 0;
}