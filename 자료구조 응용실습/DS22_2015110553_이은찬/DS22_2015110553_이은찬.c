#include <stdio.h>
#include <stdlib.h>
#define MAX 200
int main() {
	FILE *f; int d, n, m, i, j, x, rem, cnt;
	int arr[MAX] = { 0, };
	int num_search[MAX] = { 0, };
	fopen_s(&f, "input.txt", "r");

	fscanf_s(f, "%d", &d);
	fscanf_s(f, "%d", &n);
	fscanf_s(f, "%d", &m);

	for (i = 0; i < n; i++) {
		fscanf_s(f, "%d", &x);
		rem = x%d;
		if (arr[rem] == 0) { arr[rem] = x; }
		else {
			cnt = 0;
			while (arr[rem] != 0) {
				cnt++;
				rem++;
				if (rem > d) rem -= d;
			}
			arr[rem] = x; num_search[rem] = cnt;
		}
	}

	printf("Search:\n");
	for (i = 0; i < m; i++) {
		fscanf_s(f, "%d", &x);
		rem = x%d;
		if (arr[rem] == 0) { printf("F"); continue; }
		if (arr[rem] == x) { printf("S"); continue; }
		else {
			cnt = 0;
			for (j = rem; j <= d; j++) {
				cnt++;
				if (arr[j] == x) { printf("S"); continue; }
			}
		}
	}

	printf("\n");
}