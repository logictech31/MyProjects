#include "myheaders.h"
#define MAX 8

int iarr[MAX];
int partition(int, int);
void quicksort(int, int);
void swap(int*, int*);

int main() {
	int i = 0;

	printf("Enter an array: ");
	while (i <= MAX-1) {
		scanf("%d", &iarr[i++]);
	}

	quicksort(0, MAX-1);

	printf("\nResult: ");
	i = 0;
	while (i <= MAX-1) {
		printf("%d ", *(iarr+i++));
	}

	printf("\n");

	return 0;
}

void swap(int* a, int* b) {
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

int partition(int low, int high) {
	int leftwall, pivot;
	
	leftwall = low;
	pivot = iarr[low];

	for(int i = low+1; i <= high; i++) {
		if(pivot > iarr[i]) {
			swap(&iarr[leftwall], &iarr[i]);
			++leftwall;
		}
	}

	swap(&iarr[leftwall], &pivot);

	return leftwall;
}

void quicksort(int low, int high) {
	int p;
	
	if(low < high) {
		p = partition(low, high);
		quicksort(low, p);
		quicksort(p+1, high);
	}
}