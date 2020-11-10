#include <stdio.h>
#include <stdlib.h>
#define MAX_VALUE 300


typedef struct listNode *listPointer;
typedef struct listNode {
	int data;
	listPointer link;
};
listPointer concatenate(listPointer ptr1, listPointer ptr2) {
	listPointer temp;

	if (!ptr1) return ptr2;
	if (!ptr2) return ptr1;

	for (temp = ptr1; temp->link; temp = temp->link);

	temp->link = ptr2;
}
listPointer invert(listPointer lead) {

	listPointer middle, trail;
	middle = NULL;

	while (lead) {
		trail = middle;
		middle = lead;
		lead = lead->link;
		middle->link = trail;

	}
	return middle;
}


void main() {
	int x, i;
	int cnt = 0;
	int cnt2 = 0;
	int c3nt = 0;
	
	FILE *f1 = fopen("input1.txt", "r");
	

	listPointer a[MAX_VALUE];
	listPointer b[MAX_VALUE];


	for (i = 0; i < MAX_VALUE; i++) {
	a[i] = malloc(sizeof(a[i]));
}
	while (!feof(f1)) {

		fscanf_s(f1, "%d", &x, sizeof(int));
		

		a[cnt]->data = x;

		if (cnt < MAX_VALUE - 1)
			a[cnt]->link = a[cnt + 1];
		else
			a[cnt]->link = NULL;

		cnt++;
	}
	a[cnt - 1]->link = NULL;
	

	printf("First: \n\n");
	for (i = 0; i < cnt; i++) {

		printf("(%p, %d, %p)   ", a[i], a[i]->data, a[i]->link);
		c3nt++;
		if (c3nt % 3 == 0 && c3nt != 0) printf("\n");
		
	} printf("\n\n");

	fclose(f1);

	FILE *f2 = fopen("input2.txt", "r");

	c3nt = 0;

	for (i = 0; i < MAX_VALUE; i++) {
		b[i] = malloc(sizeof(b[i]));
	}
	while (!feof(f2)) {
		fscanf_s(f2, "%d", &x, sizeof(int));
		b[cnt2]->data = x;

		if (cnt2 < MAX_VALUE - 1)
			b[cnt2]->link = b[cnt2 + 1];
		else
			b[cnt2]->link = NULL;
		cnt2++;
	}
	b[cnt2 - 1]->link = NULL;

	printf("Second: \n\n");
	for (i = 0; i < cnt2; i++) {
		printf("(%p, %d, %p)   ", b[i], b[i]->data, b[i]->link);
		c3nt++;
		if (c3nt % 3 == 0 && c3nt != 0) printf("\n");

	} printf("\n\n");

	fclose(f2);

	c3nt = 0;


	concatenate(a[cnt-1], b[0]);
	
	
	printf("Concatenate:\n\n");
	for (i = 0; i < cnt; i++) {
		printf("(%p, %d, %p)   ", a[i], a[i]->data, a[i]->link);
		c3nt++;
		if (c3nt % 3 == 0 && c3nt != 0) printf("\n");
	}
	for (i = 0; i < cnt2; i++) {
		printf("(%p, %d, %p)   ", b[i], b[i]->data, b[i]->link);
		c3nt++;
		if (c3nt % 3 == 0 && c3nt != 0) printf("\n");
	}
	printf("\n\n");


	listPointer p = invert(a[0]);
	printf("Invert:\n");
	
	for (i = 0; i < cnt + cnt2 + 1; i++) {
		printf("(%p, %d, %p)   ", p, p->data, p->link);
		c3nt++;
		p = p->link;
		if (c3nt % 3 == 0 && c3nt != 0) printf("\n");
	}


	fclose(f2);
}