#include <stdio.h>
#define MAX_TERMS 1001
#define MAX_COL 1001
typedef struct {
	int row;
	int col;
	int value;
} sparseM;
sparseM a[MAX_TERMS];
sparseM b[MAX_TERMS];
void fastTranspose(sparseM a[], sparseM b[]) {
	int rowTerms[MAX_COL], startingPos[MAX_COL];
	int i, j, numCols = a[0].col, numTerms = a[0].value;
	b[0].row = numCols;
	b[0].col = a[0].row;
	b[0].value = numTerms;
	if (numTerms > 0) {
		for (i = 0; i < numCols; i++)
			rowTerms[i] = 0;
		for (i = 1; i <= numTerms; i++)
			rowTerms[a[i].col]++;
		startingPos[0] = 1;
		for (i = 1; i < numCols; i++)
			startingPos[i] = startingPos[i - 1] + rowTerms[i - 1];

		for (i = 1; i <= numTerms; i++) {
			j = startingPos[a[i].col]++;
			b[j].row = a[i].col;
			b[j].value = a[i].value;
		}
	}

}

void main() {
	int **arr1;
	int **arr2;
	int **arr;
	int i, j, x, rowSizeA, rowSizeB, colSizeA, colSizeB;
	int pvt = 1;
	FILE *f1, *f2;


	f1 = fopen("mat1.txt", "r");
	fscanf(f1, "%d %d", &rowSizeA, &colSizeA);

	arr1 = (int**)malloc(rowSizeA * sizeof(int *));
	for (i = 0; i < rowSizeA; ++i) {
		arr1[i] = (int*)malloc(colSizeA * sizeof(int));
		for (j = 0; j < colSizeA; ++j) arr1[i][j] = 0;
	}

	arr2 = (int**)malloc(rowSizeA * sizeof(int *));
	for (i = 0; i < rowSizeA; ++i) {
		arr2[i] = (int*)malloc(colSizeA * sizeof(int));
		for (j = 0; j < colSizeA; ++j) arr2[i][j] = 0;
	}


		for (i = 0; i < rowSizeA; i++) {
		for (j = 0; j < colSizeA; j++) {
			fscanf(f1, "%d", &x);
			arr1[i][j] = x;
		}
	}

	fclose(f1);


	f2 = fopen("mat2.txt", "r");
	fscanf(f2, "%d %d", &rowSizeB, &colSizeB);

	for (i = 0; i < rowSizeB; i++) {
		for (j = 0; j < colSizeB; j++) {
			fscanf(f2, "%d", &x);
			arr2[i][j] = x;
		}
	}
	fclose(f2);




	//arr2차원 동적할당 
	arr = (int**)malloc(rowSizeA * sizeof(int *));
	for (i = 0; i < rowSizeA; ++i) {
		arr[i] = (int*)malloc(colSizeA * sizeof(int));
		for (j = 0; j < colSizeA; ++j) arr[i][j] = 0;
	}
	//

	for (i = 0; i < rowSizeA; i++) {
		for (j = 0; j < colSizeA; j++) {
			arr[i][j] += arr1[i][j];
			arr[i][j] += arr2[i][j];
		}
	}


	a[0].row = rowSizeA;
	a[0].col = colSizeA;


	for (i = 0; i < rowSizeA; i++) {
		for (j = 0; j < colSizeA; j++) {
			if (arr[i][j] != 0) {
				a[pvt].row = i;
				a[pvt].col = j;
				a[pvt].value = arr[i][j];
				pvt++;
			}
		}
	}
	a[0].value = pvt - 1;



	printf("Matrix Addition:\n");
	for (i = 0; i < pvt; i++) {
		printf("%d %d %d\n", a[i].row, a[i].col, a[i].value);
	}

	fastTranspose(a, b);



	printf("Transpose Matrix:\n");
	for (i = 0; i < pvt; i++) {
		printf("%d %d %d\n", b[i].row, b[i].col, b[i].value);
	}


}





