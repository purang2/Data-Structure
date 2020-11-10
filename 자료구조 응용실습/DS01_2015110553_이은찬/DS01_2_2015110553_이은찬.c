#include <stdio.h>

#define NUM 100

int main(void){

	int max, min;
	int arr[NUM];
	int i, k;

	FILE *fp = NULL;
	fp = fopen_s(&fp,"input.txt", "r");

	if (fp == NULL) {
		printf("compile error\n");
		return 1;
	}//예외 처리

	k = 0;

	while (fscanf_s(fp, "%d", &i) != EOF) {
		arr[k] = i;
		k++;
	}

	fclose(fp);

	max = arr[0];
	min = arr[0];

	for (i = 0;i < k;i++) {
		if (max < arr[i]) max = arr[i];
		if (min > arr[i]) min = arr[i];
	}

	printf("Min: %d\n", min);
	printf("Max: %d\n", max);


	return 0;

}