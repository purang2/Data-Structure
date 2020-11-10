#include <stdio.h>
#include <stdlib.h>
void main(){
	int n, k, i,j, p;
	int *pt;
	pt = &p;
	printf("Number of friends:");
	scanf_s("%d", &n);
	printf("Words in rhyme: ");
	scanf_s("%d", &k);

	int *arr = malloc(sizeof(int)*n);
	for (i = 0;i < n;i++) arr[i] = 0;
	; p = 0;
	
	
	for(j=0;j<n-1;j++){

		for (i = 0;i < k;i++) {
			if (p >= n) p -= n;

			if (arr[p] == 0) {
				p++; 
				if (p > n) p -= n; 	
			}
			else {
				do {
					p++; if (p >n) p -= n;
					
				} while (arr[p-1] != 0||(p==n&&arr[n-1]!=0));
				//if (p > n) p -= n;
			}
		}
		
		 arr[p-1] = 1;
		*pt = p;

	}


	for (i = 0; i < n; i++) {
		if (arr[i] == 0) printf("Number %d is left", i + 1);
	}
}