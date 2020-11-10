#include <stdio.h>
#include <string.h>
#define MAX 200

int pmatch(char *string,char *pat) {
	int i, j = 0;
	int lens = strlen(string);
	int lenp = strlen(pat);
	while (i < lens&&j < lenp) {
		if (string[i] == pat[j]) {
			i++; j++;
		}
		else if (j == 0) i++;
		else j = failure[j - 1] + 1;
	}
	return ((j == lenp) ? (i - lenp) : -1);

};
void fail(char *pat) {
	int n = strlen(pat);
	failure[0] = -1;
	for (j = 1; j < n; j++) {
		i = failure[j - 1];
		while ((pat[j] != pat[i + 1]) && (i >= 0))
			i = failure[i];
		if (pat[j] = pat[i + 1])
			failure[j] = i + 1;
		else failure[j] = -1;
	}
};


int failure[MAX];
char string[MAX];
char pat[MAX];

void main() {
	int i = 0;
	//입력에 대한 처리
	char str1[MAX];
	char str2[MAX];
	int ans;
	FILE *f;
	f= fopen("input.txt", "r");
	
	
	fgets(str1, sizeof(str1), f);
	fgets(str2, sizeof(str2), f);
	fclose(f);
	//
	ans = pmatch(str1, str2);
	fail(str2);
	printf("Failure Function:\n")
	
	printf("j       ");
	for (i = 0; i < strlen(str2); i++) {
		printf("%d ", i);
	}printf("\n");

	printf("pat     ");
	for (i = 0; i < strlen(str2); i++) {
		printf("%c ", str2[i]);
	}printf("\n");


	printf("f     ");
	for (i = 0; i < strlen(str2); i++) {
		printf("%c ", failure[i]);
	}printf("\n");



	//결과값 출력
	
	if(ans==-1)
	printf("Pattern is never found\n");
	else
	printf("The pattern test is found at the position %d\n", ans);
	//

}