#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 30

typedef struct listNode *listPointer;
typedef struct listNode{
	int val;
	int exp;
	listPointer link;
};


void main() {
	int n1, n2, cnt = 0, cnt2 = 0 , arrcnt = 0;
	int x, y, i;

	listPointer arr[MAX_SIZE];
	listPointer a[MAX_SIZE];
	listPointer b[MAX_SIZE];

	FILE *f1 = fopen("a.txt", "r");

	for (i = 0; i < MAX_SIZE; i++) {
		arr[i] = malloc(sizeof(arr[i]));
		a[i] = malloc(sizeof(a[i]));
		b[i] = malloc(sizeof(b[i]));

	}
	fscanf_s(f1, "%d", &n1, sizeof(int));


	//arr[] ->val , arr[] -> exp  arr[] ->link  
	while (!feof(f1)) {

		fscanf_s(f1, "%d", &x, sizeof(int));
		fscanf_s(f1, "%d", &y, sizeof(int));

		a[cnt]->val = x;
		a[cnt]->exp = y;

		if (cnt < MAX_SIZE - 1)
			a[cnt]->link = a[cnt + 1];
		else
			a[cnt]->link = NULL;

		cnt++;
	}
	a[cnt]->link = NULL;
	fclose(f1);

	FILE *f2 = fopen("b.txt", "r");
	fscanf_s(f2, "%d", &n2, sizeof(int));

	while (!feof(f2)) {
		fscanf_s(f2, "%d", &x, sizeof(int));
		fscanf_s(f2, "%d", &y, sizeof(int));


		b[cnt2]->val = x;
		b[cnt2]->exp = y;

		if (cnt2 < MAX_SIZE - 1)
			b[cnt2]->link = b[cnt2 + 1];
		else
			b[cnt2]->link = NULL;
		cnt2++;
	}

	b[cnt2]->link = NULL;
	fclose(f2);


	cnt=0, cnt2 = 0;
	
	while (!(cnt == n1&& cnt2 == n2))
	{  //a , b 저장된 데이터 모두 체크 할 때 까지
		//exp a>b -> a를 먼저 저장		
		if (a[cnt]->exp > b[cnt2]->exp) {
			arr[arrcnt]->exp = a[cnt]->exp;
			arr[arrcnt]->val = a[cnt]->val;
			arr[arrcnt]->link = arr[arrcnt + 1];

			arrcnt++;
			cnt++;
			continue;
		}
		//      a<b -> b를 먼저 저장
		else if (a[cnt]->exp < b[cnt2]->exp) {
			arr[arrcnt]->exp = b[cnt2]->exp;
			arr[arrcnt]->val = b[cnt2]->val;
			arr[arrcnt]->link = arr[arrcnt + 1];

			arrcnt++; cnt2++;

			continue;
		}
		else //same exp
		{
			i = a[cnt]->val + b[cnt2]->val;
			arr[arrcnt]->exp = a[cnt]->exp;
			arr[arrcnt]->val = i;
			arr[arrcnt]->link = arr[arrcnt + 1];

			cnt++; cnt2++;  arrcnt++;
			continue;
		}

	}
	//while end
	arr[arrcnt]->link = NULL;

	//출력

	for (i = 0; i < arrcnt; i++) {

		printf("%dx^%d", arr[i]->val, arr[i]->exp);

		if (i != arrcnt - 1)printf(" + ");
	}


}