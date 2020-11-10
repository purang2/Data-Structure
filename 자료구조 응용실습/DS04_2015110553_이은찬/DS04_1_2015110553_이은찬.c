#include <stdio.h>
#include <stdlib.h>

void main() {
	int size = 0;
	int i;
	//임의로 맥스 자리수를 5000까지로 지정했습니다!
	char arr[2][5000] = { 0 };
	int ans[5001] = { 0 , };
	printf("First Number (less than 10^5000) : ");
	scanf("%s", arr[0]);

	printf("Second Number (less than 10^5000) : ");
	scanf("%s", arr[1]);

	size = (strlen(arr[0]) > strlen(arr[1])) ? strlen(arr[0]) : strlen(arr[1]);


	for (i = 0; i < strlen(arr[0]); i++) {
		ans[i] += (arr[0][strlen(arr[0]) - i - 1] - '0');
	}
	for (i = 0; i < strlen(arr[1]); i++) {
		ans[i] += (arr[1][strlen(arr[1]) - i - 1] - '0');
	}

	for (i = 0; i < size; i++) {
		if (ans[i] >= 10) { ans[i] -= 10; ans[i + 1]++; }
	}

	for (i = 0; i < size; i++) {
		printf("%d", ans[size - i - 1]);

	}

}