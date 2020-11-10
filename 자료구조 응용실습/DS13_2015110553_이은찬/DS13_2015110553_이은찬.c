#include <stdio.h>
#include <stdlib.h>
#define MAX 101

typedef struct listNode *listPointer;
typedef struct listNode{
	int data;
	listPointer link;
};

void main() {
	int n, m, i, j,x,y;
	listPointer arr,top,arr2;
	listPointer seq[MAX];
	int out[MAX];

	int cnt = 0;
	FILE *f = fopen("input.txt", "r");
	fscanf_s(f,"%d", &n);
	fscanf_s(f,"%d", &m);
	
	for (i = 0; i < n; i++) {
		out[i] = 1;
		seq[i] = NULL;
	}

	//input
	for (i = 0; i < m; i++) {
		fscanf_s(f,"%d", &x);
		fscanf_s(f,"%d", &y);
		arr = malloc(sizeof(*arr));
		arr->data = y; arr->link = seq[x]; seq[x] = arr;
		arr = malloc(sizeof(*arr));
		arr->data = x; arr->link = seq[y]; seq[y] = arr;
	}

	
	for (i = 0; i < n; i++) 
		if (out[i] == 1) {
			printf("\nNew Class: %d", i);
			out[i] = 0;
			arr = seq[i]; top = NULL;
			for ( ; ;) {
				while (arr) {
					j = arr->data;
					if (out[j]==1) {
						printf("%3d", j); out[j] = 0;
						arr2 = arr->link; arr->link = top; top = arr; arr = arr2;
					}
					else arr = arr->link;
				}
				if (!top) break;
				arr = seq[top->data]; top = top->link;
			}
		}
	


	
}