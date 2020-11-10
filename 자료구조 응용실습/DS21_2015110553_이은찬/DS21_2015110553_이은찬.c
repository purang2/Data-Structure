#include <stdio.h>
#include <stdlib.h>
#define INDEX 200

void swap(int* a, int* b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

void quickSort_a(int a[], int b[], int left, int right)
{
	int pivot, i, j, cnt = 0;
	if (left < right) {
		i = left; j = right + 1;
		pivot = a[left];
		do {
			do i++; while (a[i] < pivot);
			do j--; while (a[j] > pivot);
			if (i < j) {
				swap(&a[i], &a[j]);
				swap(&b[i], &b[j]);
			}
		} while (i < j);
		swap(&a[left], &a[j]);
		swap(&b[left], &b[j]);
		quickSort_a(a, b, left, j - 1);
		quickSort_a(a, b, j + 1, right);
	}
}
void quickSort_b(int a[], int b[], int left, int right)
{
	int pivot, i, j, cnt = 0;
	if (left < right) {
		i = left; j = right + 1;
		pivot = b[left];
		do {
			do i++; while (b[i] < pivot);
			do j--; while (b[j] > pivot);
			if (i < j) {
				swap(&a[i], &a[j]);
				swap(&b[i], &b[j]);
			}
		} while (i < j);
		swap(&a[left], &a[j]);
		swap(&b[left], &b[j]);
		quickSort_b(a, b, left, j - 1);
		quickSort_b(a, b, j + 1, right);
	}
}


void adjust(int a[], int b[], int root, int n) {
	int child, rootkey, temp, temp2;
	temp = a[root];
	temp2 = b[root];
	rootkey = a[root];
	child = 2 * root;
	while (child <= n) {
		if ((child < n) && (a[child] < a[child + 1]))
			child++;
		if (rootkey > a[child]) break;
		else {
			a[child / 2] = a[child];
			b[child / 2] = b[child];
			child *= 2;
		}
	}
	a[child / 2] = temp;
	b[child / 2] = temp2;

}
void heapSort(int a[], int b[], int n) {
	int i, j;
	for (i = n / 2; i > 0; i--) {
		adjust(a, b, i, n);
	}
	for (i = n - 1; i > 0; i--) {
		swap(&a[1], &a[i + 1]);
		swap(&b[1], &b[i + 1]);
		adjust(a, b, 1, i);
	}
}

int main() {
	int k1[INDEX]; int k2[INDEX];
	int arr1_qs1[INDEX]; int arr2_qs1[INDEX];
	int arr1_qs2[INDEX]; int arr2_qs2[INDEX];
	int arr1_hs1[INDEX]; int arr2_hs1[INDEX];
	int arr1_hs2[INDEX]; int arr2_hs2[INDEX];
	int n, i, x; int temp = 0;
	FILE *f; fopen_s(&f, "input.txt", "r");
	fscanf_s(f, "%d", &n);
	for (i = 0; i < n; i++) {
		fscanf_s(f, "%d", &k1[i]); fscanf_s(f, "%d", &k2[i]);
		arr1_qs1[i] = k1[i]; arr2_qs1[i] = k2[i];
		arr1_qs2[i] = k1[i]; arr2_qs2[i] = k2[i];
		arr1_hs1[i+1] = k1[i]; arr2_hs1[i+1] = k2[i];
		arr1_hs2[i+1] = k1[i]; arr2_hs2[i+1] = k2[i];

	}

	//Quick Sort
	quickSort_a(arr1_qs1, arr2_qs1, 0, n - 1);
	quickSort_b(arr1_qs2, arr2_qs2, 0, n - 1);
	printf("Quick Sort\nKey: K1\n");
	for (i = 0; i < n; i++)
		printf("%d %d\n", arr1_qs1[i], arr2_qs1[i]);
	printf("\nKey: K2\n");
	for (i = 0; i < n; i++)
		printf("%d %d\n", arr1_qs2[i], arr2_qs2[i]);
	//QS END

	//HS
	heapSort(arr1_hs1, arr2_hs1, n);
	printf("\nHeap Sort\nKey: K1\n");
	for (i = 1; i <= n; i++)
		printf("%d %d\n", arr1_hs1[i], arr2_hs1[i]);
	heapSort(arr2_hs2, arr1_hs2, n );
	printf("\nKey: K2\n");
	for (i = 1; i <= n; i++)
		printf("%d %d\n", arr1_hs2[i], arr2_hs2[i]);

}
