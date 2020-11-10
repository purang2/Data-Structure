#include <stdio.h>
#include <stdlib.h>
#define MAX 1001
typedef struct listNode *listPointer;
typedef struct listNode{
	int data;
	listPointer link;
};


void main() {
	int n, k,i, cnt,ans;
	
	printf("Sample Run---------\n\n\n");
	printf("Number of Friends: ");
	scanf_s("%d", &n);
	printf("Words in Rhyme: ");
	scanf_s("%d", &k);
	cnt = n;
	listPointer friends[MAX];
	listPointer pt;
	listPointer temp;
	
	for (i = 0; i < n; i++) {
		friends[i] = malloc(sizeof(*friends[i]));
		friends[i]->data = (i + 1);
	}
	
	for (i = 0; i < n; i++) {
	friends[i]->link = friends[(i + 1) % n];
	}

	pt = friends[n - 1];
	while (cnt > 1) {

		for (i = 0; i < k-1; i++) {
			pt = pt->link;
		}
		
		cnt--;

		if (cnt != 1) {
			temp = pt->link;
			pt->link = temp->link;
		}
	}

	ans = pt->data;
	

	printf("NUMBER %d is LEFT and I will go home now\n", ans);


}