#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define SWAP(x,y,t) ((t) = (x), (x) = (y), (y) = (t))

void sort(int list[], int n)
{
	int i,j,t;
	for (i = 0; i < n - 1; i++) {
		for (j = i + 1; j < n; j++) {
			if (list[i] < list[j]) {
				SWAP(list[i], list[j], t);
			}
		}
	}
}


void main() {
	FILE *fp, *fp2;
	int i,n;
	
	printf("N: ");
	scanf_s("%d", &n);
	
	int *arr1 = malloc(sizeof(int)*n);

	if (n < 1) {
		fprintf(stderr, "Improper value of n\n");
		exit(1);
	}
	
	for (i = 0; i < n; i++) {
		arr1[i] = rand();
	}

	fopen_s(&fp, "unsorted.txt", "w");

	if (fp == NULL) {		
		perror("파일 열기 실패");
		exit(1);
	}

	for (i = 0; i < n; i++) {
		fprintf(fp, "%d, ", arr1[i]);
	}

	
	sort(arr1,n);
	
	fopen_s(&fp2, "sorted.txt", "w");

	for (i = 0; i < n; i++) {
		fprintf(fp2, "%d, ", arr1[i]);
	}


	free(arr1);

}

