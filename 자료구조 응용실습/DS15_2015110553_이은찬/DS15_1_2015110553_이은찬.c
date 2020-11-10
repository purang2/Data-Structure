#include <stdio.h>
#include <stdlib.h>
#define MAX_ELEMENTS 200
#define HEAP_FULL(n) (n == MAX_ELEMENTS-1)
#define HEAP_EMPTY(n) (!n)
typedef struct {
	int key;
}element;
typedef struct node *treePointer;

typedef struct node{
	int data;
	treePointer left, right;
};
treePointer tree[MAX_ELEMENTS];
element heap[MAX_ELEMENTS];
int n = 0;

void push(element item, int n) {
	int i;
	if (HEAP_FULL(n)) {
		fprintf(stderr, "The heap is full.\n");
		exit(EXIT_FAILURE);
	}
	i = ++(n);
	while ((i != 1) && (item.key > heap[i / 2].key)) {
		heap[i] = heap[i / 2];
		i /= 2;
	}
	heap[i] = item;
}

element pop(int n) {
	int parent, child;
	element item, temp;
	if (HEAP_EMPTY(n)) {
		fprintf(stderr, "The heap is full.\n");
		exit(1);
	}
	item = heap[1];
	temp = heap[(n)--];
	parent = 1;
	child = 2;
	while (child <= n) {
		if ((child <n) && (heap[child].key < heap[child + 1].key))
			child++;
		if (temp.key >= heap[child].key) break;

		heap[parent] = heap[child];
		parent = child;
		child *= 2;
	}
	heap[parent] = temp;
	return item;
}

void inorder(treePointer ptr) {
	if (ptr) {
		inorder(ptr->left);
		printf("%d ", ptr->data);
		inorder(ptr->right);
	}
}

int main() {
	int x=0, siz;
	FILE *f;
	fopen_s(&f, "input.txt", "r");
	int i = 1;
	fscanf_s(f, "%d", &x);
	element temp;
	temp.key = x;
	push(temp, 0);

	for (i = 0; i < MAX_ELEMENTS; i++) {
		tree[i] = malloc(sizeof(tree[i]));
        	
	}

	i = 1;
	while (!feof(f)) {
		element root;
		fscanf_s(f, "%d", &x);
		root.key = x;
		tree[i+1]->data = x;
		push(root, i++);
	}
	siz = i;
	
	for(i=1;i<=siz;i++)
	tree[i]->data = heap[i].key;

	//left,right 贸府
	for (i = 1; i <= siz; i++) {
		if (i * 2 <= siz)tree[i]->left = tree[i * 2];
		else tree[i]->left = NULL;

		if ((i * 2) + 1 <= siz)tree[i]->right = tree[i * 2 + 1];
		else tree[i]->right = NULL;
	}


	//免仿*******************************************
	//#1
	printf("Level Order: ");
	for (i = 1; i <= siz; i++)
		printf("%d ", heap[i].key);
	printf("\nInorder: ");
	inorder(tree[1]);
	printf("\n");
	//

    //#2 
	pop(siz);
	
	siz--;
	for (i = 1; i <= siz; i++)
		tree[i]->data = heap[i].key;

	//left,right 贸府
	for (i = 1; i <= siz; i++) {
		if (i * 2 <= siz)tree[i]->left = tree[i * 2];
		else tree[i]->left = NULL;

		if ((i * 2) + 1 <= siz)tree[i]->right = tree[i * 2 + 1];
		else tree[i]->right = NULL;
	}
	
	printf("Level Order: ");
	for (i = 1; i <= siz; i++)
		printf("%d ", heap[i].key);

	printf("\nInorder: ");
	inorder(tree[1]);
	printf("\n");
	//
	//#3
	pop(siz);

	siz--;
	for (i = 1; i <= siz; i++)
		tree[i]->data = heap[i].key;

	//left,right 贸府
	for (i = 1; i <= siz; i++) {
		if (i * 2 <= siz)tree[i]->left = tree[i * 2];
		else tree[i]->left = NULL;

		if ((i * 2) + 1 <= siz)tree[i]->right = tree[i * 2 + 1];
		else tree[i]->right = NULL;
	}

	printf("Level Order: ");
	for (i = 1; i <= siz; i++)
		printf("%d ", heap[i].key);

	printf("\nInorder: ");
	inorder(tree[1]);
	printf("\n");
	//

	return 0;
}