#include <stdio.h>
#include <stdlib.h>

void main() {
	char arr[20];
	int i;
	int sum = 0;
	int qMark = 0;
	int missing;
	printf("ISBN: ");
	scanf("%s", arr);

	for (i = 1; i <= 10; i++) {
		if (arr[i-1] == 'X') sum += (10 * (11 - i));
		else if (arr[i-1] == '?') qMark = 11 - i;
		else sum += (arr[i-1] - '0')*(11 - i);
	}

	sum = sum % 11;
	for (i = 1; i < 11; i++) {
		
		sum += qMark;
		if (sum % 11 == 0) {
			missing = i;
			break;
		}
	}

	printf("Missing Digit: %d\n", missing);
}