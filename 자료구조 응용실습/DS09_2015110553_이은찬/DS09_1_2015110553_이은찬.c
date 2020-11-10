#include <stdio.h>
#include <stdlib.h>
#define MAX 100
void main() {
	//variables
	int i;
	int top = -1;
	int top2 = -1;
	char ca;
	char *ans;
	char * arr;
	FILE *f;
	//create array(uses like stack)
	arr = (char *)malloc(MAX*sizeof(char));
	//create answer array
	ans = (char *)malloc(MAX*sizeof(char));
	//file IO
	fopen_s(&f, "input.txt", "r");

	while (!feof(f)) {
		fscanf_s(f, "%c", &ca, sizeof(char));

		if (ca == '+' || ca == '-' ||
			ca == '*' || ca == '/' || ca == '%')
		{ //0. ��ȣ ���� ������

			if (arr[top] == '+' || arr[top] == '-' ||
				arr[top] == '*' || arr[top] == '/' || arr[top] == '%') 
			{
				ans[++top2] = arr[top--];
				arr[++top] = ca;
			}
			else arr[++top] = ca;
		}

		else if (ca == '(') {
			//1.���� ��ȣ�� ���
			arr[++top] = ca;
		}

		else if (ca == ')') {
			//2.�ݴ°�ȣ�� ���
			while (arr[top] != '(') {
				ans[++top2] = arr[top--];
			}
			top--;
			//��ȣ ¦�� ã�� ������ top�� ������ ���鼭 
			//���ÿ� �ִ� �����ڸ� ans string�� �߰��Ѵ�
		}

		else { //3. ������ ���� ��
			ans[++top2] = ca;
			
		}
	}
	//while�� Ż�� �� ���� ���� �� �ܾ��ƾ��Ѵ�!(��� ó��)
	if (top == 0) {
		ans[top2++] = arr[top];
	}

	//��� ���
	for (i = 0; i < top2; i++) {
		printf("%c", ans[i]);
	}

	free(arr);
	free(ans);
	fclose(f);
}

