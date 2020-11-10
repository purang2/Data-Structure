#include <stdio.h>
#include <stdlib.h>
#define MAX 100

int cycle[MAX] ;

void run(int i, int j,int n,int count) {
	int max,min,x;
	if (cycle[i] == 0 && cycle[j] == 0) {
		cycle[i] = count; cycle[j] = count;		
	}
	
	else {
		max = cycle[i] > cycle[j] ? cycle[i] : cycle[j]; //큰 값
		min= cycle[i] > cycle[j] ? cycle[j] : cycle[i]; //작은 값
		for (x = 0; x < n; x++) {
			 if (cycle[x] == min) cycle[x] = max; 
		}
	}
}

//cycle이면 1
int isCycle(int i, int j) {
	if (cycle[i] == cycle[j]&&cycle[i]!=0) return 1;
	return 0;
}

int main() {
	FILE *f; int n, i, j,min=123456789; 
	int cnt = 0,ans=0,mini=-1,minj=-1,count=1;
	int arr[MAX][MAX];
	int ban[MAX][MAX] = { 0 ,};
	
	fopen_s(&f, "input.txt", "r");
	fscanf_s(f, "%d", &n);
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
			fscanf_s(f, "%d", &arr[i][j]);

	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			if (isCycle(i, j) == 0 && arr[i][j] != 0) {
				if (arr[i][j] < min) { min = arr[i][j]; mini = i; minj = j; }
			}}}
	
	printf("Selected Edges: ");
	run(mini, minj, n, count++);
	printf(" (%d, %d),", mini, minj);
	ban[mini][minj] = 1;
	ban[minj][mini] = 1;
	ans += arr[mini][minj];
	cnt++;

	while (cnt != n - 1) {
		min = 123456789; mini = 0; minj = 0;
		for (i = 0; i < n; i++) {
			for (j = 0; j < n; j++) {
				if (ban[i][j]!=1&&isCycle(i,j)==0 &&arr[i][j]!=0) {
					if (arr[i][j] < min) { min = arr[i][j]; mini = i; minj = j; }
				}
					
			}
		}
		run(mini,minj,n,count++);

		if(cnt!=n-2)printf(" (%d, %d),",mini,minj);
		else printf(" (%d, %d)", mini, minj);
		ban[mini][minj] = 1;
		ban[minj][mini] = 1;
		ans += arr[mini][minj];
		cnt++;
	}

	printf("\nCost: %d", ans);
}