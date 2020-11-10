#include <stdio.h>
#include <stdlib.h>
#define MAX 100
void main() {
	char* arr;
	int i;
	int top = -1;

	arr = (char*)malloc(MAX * sizeof(char));
	FILE *f = NULL;
	char ca;
	int isBalance = 0;
	fopen_s(&f, "input.txt", "r");

	fscanf_s(f, "%c", &ca, sizeof(char));
	while (!feof(f)){

		//¿©´Â °ýÈ£ ½Ã °ýÈ£¸¦ Çª½¬
		if (ca == '(' || ca == '{' || ca == '[') {
			arr[++top] = ca; 
			}
		//´Ý´Â °ýÈ£ ½Ã °ýÈ£ Â¦ ÆÇº°
		else if (ca == ')' || ca == '}' || ca == ']') {
			if ( (arr[top] == '(' && ca==')' )||
				(arr[top] == '{' && ca == '}')||
				(arr[top] == '[' && ca == ']')
				) {
				/*pop */
			 //arr[top--] = NULL; 
				top--;		 
			}
			else
			{
				top = 100;
				break;
			}

		}
		fscanf_s(f, "%c", &ca, sizeof(char));
	}

	if (top== -1) 
		printf("balanced\n"); 
	else 
		printf("NOT balanced\n");

	free(arr);
	fclose(f);


}