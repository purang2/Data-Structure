#include <stdio.h>
#include <string.h>
#define MAX 200

int failure[MAX] = { 0 };
char string[MAX];
char pat[MAX];


void fail(char *pat) {
	int i, j;
	int n = strlen(pat);
	failure[0] = -1;
	for (j = 1; j < n; j++) {
		i = failure[j - 1];
		while ((pat[j] != pat[i + 1]) && (i >= 0))
			i = failure[i];
		if (pat[j] == pat[i + 1])
			failure[j] = i + 1;
		else failure[j] = -1;
	}
}

int pmatch(char *string, char *pat) {
	
	int m = 0, n = 0;
	int lens = strlen(string);
	int lenp = strlen(pat);
	while (m < lens && n < lenp) {
		if (string[m] == pat[n]) {
			m++; n++;
		}
		else if (n == 0) m++;
		else n = failure[n - 1] + 1;
	}
	return ((n == lenp) ? (m - lenp) : -1);

}



void main() {
	int z, ans;
	//입력에 대한 처리
	char str1[MAX];
	char str2[MAX];


	FILE *f;
	f = fopen("input.txt", "r");

	fgets(str1, sizeof(str1), f);
	fgets(str2, sizeof(str2), f);
	fclose(f);
	//

	fail(str2);
	ans = pmatch(str1, str2);
	
	
	
	printf("Failure Function:\n");

	printf("j      ");
	for (z = 0; z <strlen(str2)-1; z++) {
		printf("%d ", z);
	}printf("\n");

	printf("pat     ");
	for (z = 0; z <strlen(str2)-1; z++) {
		printf("%c ", str2[z]);
	}printf("\n");


	printf("f     ");
	for (z = 0; z <strlen(str2)-1; z++) {
		printf("%d ", failure[z]);
	}printf("\n");



	//결과값 출력

	if (ans == -1)
		printf("Pattern is never found\n");
	else
		printf("The pattern test is found at the position %d\n", ans);
	//

}

