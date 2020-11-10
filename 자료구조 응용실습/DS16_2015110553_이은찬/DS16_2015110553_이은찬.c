#include <stdio.h>
#include <stdlib.h>
#define MAX 200

typedef struct vertex *treePointer;
typedef struct vertex {
	int data;
	treePointer left, right;
};

void preorder(treePointer ptr) {
	if (ptr) {
		printf("%d ", ptr->data);
		preorder(ptr->left);
		preorder(ptr->right);
	}
}

void postorder(treePointer ptr) {
	if (ptr) {
		postorder(ptr->left);
		postorder(ptr->right);
		printf("%d ", ptr->data);
	}
}

void inorder(treePointer ptr) {
	if (ptr) {
		inorder(ptr->left);
		printf("%d ", ptr->data);
		inorder(ptr->right);
	}
}

void process(treePointer tp, int k) {
	treePointer temp1, temp2;
	
	while (tp) {	
		temp1 = malloc(sizeof(temp1));
		temp1->data = k;
		temp1->left = temp1->right = NULL;

		if (k < tp->data){

			if (!tp->left) {
				tp->left = temp1; break;
			}
			else tp = tp->left;
		}
		else if (k > tp->data) {
			if (!tp->right) {
				tp->right = temp1;
				break;
			}
			else {
				tp = tp->right; 
			}
		}
		else break;
	}
}

int search(treePointer tr, int key) {
	while (tr) {
		if (key == tr->data) return key;
		else if (key < tr->data) tr = tr->left;
		else  tr = tr->right;
	}
	 return -99999;
}

treePointer tree[MAX],ts;
int main() {
	int x, i, k=0,det; FILE *f1, *f2;
	
	for(i=0;i<MAX;i++)
		tree[0] = malloc(sizeof(tree[0]));
		
	fopen_s(&f1, "input1.txt", "r");
	fscanf_s(f1, "%d", &x,sizeof(int));
	
	tree[0]->data = x;
	tree[0]->left = tree[0]->right = NULL;
	
	i = 0;
	while (!feof(f1)) {
		ts = tree[0];
		fscanf_s(f1, "%d", &k);	

		//printf("<><>%d\n",i++);
		process(ts, k);
	
		}
	printf("Preorder:  ");
	preorder(tree[0]);
	printf("\nInorder:   ");
	inorder(tree[0]);
	printf("\nPostorder: ");
	postorder(tree[0]);

	fopen_s(&f2, "input2.txt", "r");


	printf("\nSearch: ");
	while (!feof(f2)) {
		
		fscanf_s(f2, "%d", &x);
		det=search(tree[0], x);

		if (det == -99999) printf("%d  ", 0);
		else printf("%d  ", 1);
		
	}

	}


