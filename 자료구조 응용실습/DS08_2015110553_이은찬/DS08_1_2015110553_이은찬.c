#include <stdio.h>
#include <stdlib.h>
#define MAX 100
void main() {
	int* arr;
	int i;
	int top = -1;

	arr = (int*)malloc(MAX * sizeof(int));
	FILE *f;
	char ca;
	int n;
	fopen_s(&f, "input.txt", "r");
	
	while (!feof(f)){
		
		fscanf_s(f, "%c", &ca);
		if (ca == 'I') {
			fscanf_s(f, "%d", &n);
			arr[++top] = n;
		}
		else if (ca == 'D') {
			
			top--;
		}

	}
	
	if (ca == 'D') {
		for (i = 0; i <= top + 1; i++)
			printf("%d ", arr[i]);
	}
	
	else {
		for (i = 0; i <= top; i++)
			printf("%d ", arr[i]);
	}

	free(arr);
	fclose(f);


}