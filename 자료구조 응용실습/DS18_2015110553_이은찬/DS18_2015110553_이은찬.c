#include <stdio.h>
#include <stdlib.h>
#define MAX 100


typedef struct adjlist *adjPointer;
typedef struct adjlist{
	int data;
	adjPointer link;
}adjlist ;
int visited[MAX];
int visited2[MAX];
adjPointer adjLists[MAX][MAX];
void dfs(int v) {

	adjPointer w;
	visited[v] = 1;
	printf("%d ", v);
	for (w = adjLists[v][0]; w; w = w->link)
		if (!visited[w->data])
			dfs(w->data);
}

int q[MAX] = { 0, };
int front=-1,rear = -1;
void bfs(int v) {
	adjPointer w;
	front = rear = -1;
	printf("%d ", v);
	visited2[v] = 1;
	q[++rear] = v;//add
	while (front!=rear) {
		v = q[++front];
		for (w = adjLists[v][0]; w; w = w->link) {
			if (!visited2[w->data]) {
				printf("%d ", w->data);
				q[++rear] = w->data;
				visited2[w->data] = 1;
			}
		}
	}
}
int main() {
	FILE *f; int n=0,i,j;
	fopen_s(&f, "input.txt", "r");
	int arr[MAX][MAX];
	int cnt = 0;
	//adjPointer adjLists[MAX][MAX];
	adjPointer temp,temp2;
	for(i=0;i<MAX;i++)
		for (j = 0; j < MAX; j++) {
			adjLists[i][j] = (adjPointer)malloc(sizeof(adjlist));
		}
	fscanf_s(f, "%d", &n);

	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
			fscanf_s(f, "%d", &arr[i][j]);
 
	for (i = 0; i < n; i++) {
		cnt = 0;
		for (j = 0; j < n; j++) {
			if (arr[i][j] == 1) {
				if (cnt >= 1) adjLists[i][cnt - 1]->link = adjLists[i][cnt];
				adjLists[i][cnt]->data = j;
				adjLists[i][cnt]->link = NULL;
				cnt++;
	   }
		}
	}

	//VERTEX Ãâ·Â 
	for (i = 0; i < n; i++)
	{
		temp= (adjPointer)malloc(sizeof(adjlist));
		temp = adjLists[i][0];
		printf("Vertex %d:", i);
		while (temp) {
			printf(" %d", temp->data);
			temp = temp->link;
		}
		printf("\n");
	}

	//SEARCH*****

	//DFS
	printf("DFS: "); dfs(0);
	printf("\nBFS: "); bfs(0);

}