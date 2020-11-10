#include <stdio.h>
#include <stdlib.h>
#define MAX 200

typedef struct node *nodePointer;
typedef struct node {
	int vertex;
	nodePointer link;
}node;

typedef struct {
	int count;
	nodePointer link;
}hdnodes;
hdnodes graph[MAX];
void topSort(hdnodes graph[], int n) {
	int i, j, k, top;
	nodePointer ptr;

	top = -1;

	for (i = 0; i< n; i++)
		if (!graph[i].count) {
			graph[i].count = top;
			top = i;
		}

	for (i = 0;i<n; i++)
		if (top == -1) {
			fprintf(stderr, "\nNetwork has a cycle. Sort terminated. \n");
			exit(1);
		}
		else {
			j = top;
			top = graph[top].count;
			printf("%d, ", j);
			for (ptr = graph[j].link; ptr; ptr = ptr->link) {
				k = ptr->vertex;
				graph[k].count--;
				if (!graph[k].count) {
					graph[k].count = top;
					top = k;
				}
			}
		}
}

nodePointer root[MAX];
int main() {

	FILE *f;
	int n, i, j, x, start, cnt = 0;
	int arr[MAX] = { 0, };
	int ax[MAX][MAX];
	for (i = 0; i < MAX; i++) {
		root[i] = (nodePointer)malloc(sizeof(*root[i]));
	}


	fopen_s(&f, "input.txt", "r");
	fscanf_s(f, "%d", &n);

	//initi
	for (i = 0; i < n; i++) {
		graph[i].count = 0;
		graph[i].link = NULL;
	}
	//counting  -> [Ãß°¡] arr[i] :³ëµå iÀÇ ¿§Áö °¹¼ö
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			fscanf_s(f, "%d", &x);
			ax[i][j] = x;
			if (x != 0) {
				graph[j].count++;
				arr[i]++;
			}
		}
	}
	//
	for (i = 0; i < n; i++) {
		start = -1;
		for (j = 0; j < n; j++) {

			if (ax[i][j] != 0) {
				root[cnt]->vertex = j;
				root[cnt]->link = NULL;
				if (start == -1) {
					graph[i].link = root[cnt];
					start++;
					cnt++;
				}
				else {
					root[cnt - 1]->link = root[cnt];
					cnt++;
				}
			}
		}

	}
	
	topSort(graph, n);
}