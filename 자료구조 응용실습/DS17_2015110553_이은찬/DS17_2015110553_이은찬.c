#include <stdio.h>
#include <stdlib.h>
#define MAX_INDEX 200

typedef struct vertex* treePointer;
typedef struct vertex {
	int data;
	treePointer left, right;
}vertex;

void inorder(treePointer tp) {
	if (tp) {
		inorder(tp->left);
		printf("%d ", tp->data);
		inorder(tp->right);
	}
}

int main() {
	int n, i,j,x,cnt,add,start,max;int **arr;FILE *f;
	
	fopen_s(&f, "input.txt", "r");
	fscanf_s(f, "%d", &n, sizeof(int));
	start = 0; add = n; cnt = n;
	treePointer tree[MAX_INDEX];
	treePointer tree_2[MAX_INDEX];

	
	
	//2D ARRAY ALLOC  arr[n][MAX] =all set 0
	arr= (int **)calloc(n, sizeof(int *));
	for (i = 0; i<n; i++)
		arr[i] = (int *)calloc(MAX_INDEX, sizeof(int));
	
	//INPUT 처리
	for (i = 0; i < n; i++) {
		j = 0;
		while (1) {
			fscanf_s(f, "%d", &x, sizeof(int));
			if (x == -1) { arr[i][j++] = x; break; }
			else arr[i][j++] = x;
		}}


	//2*n개의 트리 활성화 
	for (i = 0; i < n*2-1; i++) {
		tree[i] = (treePointer)malloc(sizeof(vertex));
		if (i < n) {
			tree[i]->data = arr[i][0];
			tree[i]->left = tree[i]->right = NULL;
		}
	}

	while(1){
		//printf("sta : %d add : %d\n", start, add);
	for (i = start; i < start+add; i += 2) {
		if (tree[i]->data > tree[i + 1]->data) {
			tree[cnt]->data = tree[i + 1]->data;
			tree[cnt]->left = tree[i];
			tree[cnt]->right = tree[i + 1];
			cnt++;
		}
		else {
			tree[cnt]->data = tree[i]->data;
			tree[cnt]->left = tree[i];
			tree[cnt]->right = tree[i + 1];
			cnt++;
			}
	}
		start+=add; add/=2;
			if (add == 1) break;
			}
	
	
	printf("Winner :   %d\n", tree[cnt - 1]->data);
	printf("levelorder:   "); 
	start = (2 * n) - 2; add = 1;
	while (1) {
		for (i = start; i < start + add; i++)
			printf("%d ", tree[i]->data);


		if (start==0) break;
		add *= 2;
		start -= add;

	}

	printf("\nInorder:   "); inorder(tree[cnt - 1]);


	//seq #2
	max = tree[cnt - 1]->data; start = 0; add = n; cnt = n;
	//2*n개의 트리 활성화 
	for (i = 0; i < n * 2 - 1; i++) {
		tree_2[i] = (treePointer)malloc(sizeof(vertex));
		if (i < n) {
			if (arr[i][0] == max) tree_2[i]->data = arr[i][1];
				else tree_2[i]->data = arr[i][0];
			tree_2[i]->left = tree_2[i]->right = NULL;
		}
	}

	while (1) {
		//printf("sta : %d add : %d\n", start, add);
		for (i = start; i < start + add; i += 2) {
			if (tree_2[i]->data > tree_2[i + 1]->data) {
				tree_2[cnt]->data = tree_2[i + 1]->data;
				tree_2[cnt]->left = tree_2[i];
				tree_2[cnt]->right = tree_2[i + 1];
				cnt++;
			}
			else {
				tree_2[cnt]->data = tree_2[i]->data;
				tree_2[cnt]->left = tree_2[i];
				tree_2[cnt]->right = tree_2[i + 1];
				cnt++;
			}
		}
		start += add; add /= 2;
		if (add == 1) break;
	}



	printf("\nWinner :   %d\n", tree_2[cnt - 1]->data);
	printf("levelorder:   "); 

	start = (2 * n) - 2; add = 1;
	while (1) {
		for (i = start; i < start + add; i++)
			printf("%d ", tree_2[i]->data);


		if (start == 0) break;
		add *= 2;
		start -= add;

	}
	printf("\nInorder:   "); inorder(tree_2[cnt - 1]);

}