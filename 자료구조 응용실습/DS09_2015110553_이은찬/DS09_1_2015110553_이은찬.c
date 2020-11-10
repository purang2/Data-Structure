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
		{ //0. 괄호 제외 연산자

			if (arr[top] == '+' || arr[top] == '-' ||
				arr[top] == '*' || arr[top] == '/' || arr[top] == '%') 
			{
				ans[++top2] = arr[top--];
				arr[++top] = ca;
			}
			else arr[++top] = ca;
		}

		else if (ca == '(') {
			//1.여는 괄호일 경우
			arr[++top] = ca;
		}

		else if (ca == ')') {
			//2.닫는괄호일 경우
			while (arr[top] != '(') {
				ans[++top2] = arr[top--];
			}
			top--;
			//괄호 짝을 찾을 때까지 top을 감소해 가면서 
			//스택에 있는 연산자를 ans string에 추가한다
		}

		else { //3. 데이터 값일 때
			ans[++top2] = ca;
			
		}
	}
	//while문 탈출 시 스택 남은 값 긁어모아야한다!(찌꺼기 처리)
	if (top == 0) {
		ans[top2++] = arr[top];
	}

	//결과 출력
	for (i = 0; i < top2; i++) {
		printf("%c", ans[i]);
	}

	free(arr);
	free(ans);
	fclose(f);
}

