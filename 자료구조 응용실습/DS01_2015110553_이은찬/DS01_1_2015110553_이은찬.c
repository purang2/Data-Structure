#include <stdio.h>


int main(void) {

	int val1 = 0;
	int val2 = 0;
	printf("���� 1 �Է�!\n");
	scanf_s("%d", &val1);

	printf("���� 2 �Է�!\n");
	scanf_s("%d", &val2);

	printf("%d + %d = %d\n", val1, val2, val1 + val2);
	printf("%d - %d = %d\n", val1, val2, val1 - val2);
	printf("%d * %d = %d\n", val1, val2, val1 * val2);
	printf("%d / %d = %d\n", val1, val2, val1 / val2);



	return 0;
}