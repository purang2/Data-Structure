#include<stdio.h>
int main(void) {

	int n1, n2;
    int i1, i2;
	int sum1, sum2;

	printf("Sample run: \n");

	printf("First number: \n");
	scanf_s("%d", &n1);

	printf("Second number: \n");
	scanf_s("%d", &n2);

	sum1 = 0;

	for (i1 = 1; i1 <= n1 / 2; i1++) {
		if (n1 % i1 == 0) {
			sum1 += i1;
		}
	}

	sum2 = 0;
	for (i2 = 1; i2 <= n2 / 2; i2++) {
		if (n2 % i2 == 0) {
			sum2 += i2;
		}
	}

	if (sum1 == n2 && sum2 == n1) printf("AMICABLE");

	else printf("NOT AMICABLE");

	return 0;
}