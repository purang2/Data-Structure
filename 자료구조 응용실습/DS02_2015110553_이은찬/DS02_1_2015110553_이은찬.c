#include <stdio.h>

void main() {

	int i, n;
	int true=0;

	printf("숫자를 입력하세요: ");
	scanf_s("%d", &n);

	for (i = 2; i < n; i++) {
		if (n%i == 0) break;

		if (i == n - 1) true = 1;

	}

	true = 1 ? printf("Prime") : printf("Not Prime");
}