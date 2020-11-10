#include <stdio.h>


int main(void) {

	int val1 = 0;
	int val2 = 0;
	printf("숫자 1 입력!\n");
	scanf_s("%d", &val1);

	printf("숫자 2 입력!\n");
	scanf_s("%d", &val2);

	printf("%d + %d = %d\n", val1, val2, val1 + val2);
	printf("%d - %d = %d\n", val1, val2, val1 - val2);
	printf("%d * %d = %d\n", val1, val2, val1 * val2);
	printf("%d / %d = %d\n", val1, val2, val1 / val2);



	return 0;
}