#include <stdio.h>
#include <stdlib.h>

#define MAX 9


typedef struct node *treePointer;

typedef struct node {
char data;
treePointer leftChild, rightChild;
};

void inorder(treePointer ptr) {
if (ptr) {
inorder(ptr->leftChild);
printf("%c", ptr->data);
inorder(ptr->rightChild);
}
}

void postorder(treePointer ptr) {
if (ptr) {
postorder(ptr->leftChild);
postorder(ptr->rightChild);
printf("%c", ptr->data);

}
}

void preorder(treePointer ptr) {
if (ptr) {
printf("%c", ptr->data);
preorder(ptr->leftChild);
preorder(ptr->rightChild);

}
}

/*
Traversal
inorder: A / B * C * D + E
POSTorder: A B / C * D * E +
PREorder: + * * / A B C D E

*/
int main(void) {	
	treePointer temp[MAX];
	treePointer temp2[MAX];
	
	int i;
	//memory allocating
	for (i = 0; i < MAX; i++) { //0~8
		temp[i] = (treePointer)malloc(sizeof(*temp[i]));
		temp2[i] = (treePointer)malloc(sizeof(*temp2[i]));
	}

	//TEMP1
	for (i = 0; i<MAX; i++)
	temp[i]->data = (char)('A'+i);

	//A child
	temp[0]->leftChild = temp[1];
	temp[0]->rightChild = temp[2];
	//B
	temp[1]->leftChild = temp[3];
	temp[1]->rightChild = temp[4];
	//C
	temp[2]->leftChild = temp[5];
	temp[2]->rightChild = temp[6];
	//D
	temp[3]->leftChild = temp[7];
	temp[3]->rightChild = temp[8];

	//E
	temp[4]->leftChild = NULL;
	temp[4]->rightChild = NULL;
	//F
	temp[5]->leftChild = NULL;
	temp[5]->rightChild = NULL;
	//G
	temp[6]->leftChild = NULL;
	temp[6]->rightChild = NULL;
	//H
	temp[7]->leftChild = NULL;
	temp[7]->rightChild = NULL;
	//I
	temp[8]->leftChild = NULL;
	temp[8]->rightChild = NULL;
	
	//TEMP2
	temp2[0]->data = '+';
	temp2[0]->leftChild = temp2[1];
	temp2[0]->rightChild = temp2[2];

	temp2[1]->data = '*';
	temp2[1]->leftChild = temp2[3];
	temp2[1]->rightChild = temp2[4];

	temp2[2]->data = 'E';
	temp2[2]->leftChild = NULL;
	temp2[2]->rightChild = NULL;

	temp2[3]->data = '*';
	temp2[3]->leftChild = temp2[5];
	temp2[3]->rightChild = temp2[6];

	temp2[4]->data = 'D';
	temp2[4]->leftChild = NULL;
	temp2[4]->rightChild = NULL;

	temp2[5]->data = '/';
	temp2[5]->leftChild = temp2[7];
	temp2[5]->rightChild = temp2[8];

	temp2[6]->data = 'C';
	temp2[6]->leftChild = NULL;
	temp2[6]->rightChild = NULL;

	temp2[7]->data = 'A';
	temp2[7]->leftChild = NULL;
	temp2[7]->rightChild = NULL;

	temp2[8]->data = 'B';
	temp2[8]->leftChild = NULL;
	temp2[8]->rightChild = NULL;

	printf("Preorder: ");
	preorder(temp[0]);


	printf("\nInorder:  ");
	inorder(temp[0]);

	printf("\nPostorder: ");
	postorder(temp[0]);

	printf("\nPreorder: ");
	preorder(temp2[0]);


	printf("\nInorder:  ");
	inorder(temp2[0]);

	printf("\nPostorder: ");
	postorder(temp2[0]);

	



	return 0;
}