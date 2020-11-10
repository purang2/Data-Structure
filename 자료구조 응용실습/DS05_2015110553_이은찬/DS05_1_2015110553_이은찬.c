#include <stdio.h>

#define MAX_DEGREE 1001
typedef struct {
	int degree;
	int coef[MAX_DEGREE];
}polynomial;

void main() {
	int n1, n2;
	int i, x, y;
	int flag[MAX_DEGREE] = { 0 };
	int yMin = 1003;
	polynomial poly;


	FILE *fp = NULL;
	FILE *fp2 = NULL;
	fopen_s(&fp, "a.txt", "r");
	fscanf_s(fp, "%d", &n1);

	for (i = 0;i < n1;i++) {
		fscanf_s(fp, "%d", &x);
		fscanf_s(fp, "%d", &y);
		
		if (y < yMin) yMin = y;
		poly.coef[y] = x;
		flag[y] = -1;
	}

	fopen_s(&fp2, "b.txt", "r");
	fscanf_s(fp2, "%d", &n2);

	for (i = 0;i < n2;i++) {
		fscanf_s(fp2, "%d", &x);
		fscanf_s(fp2, "%d", &y);
		if (y < yMin) yMin = y;

		switch (flag[y]) {
		case 0:
			poly.coef[y] = x;
			flag[y] = -1;
			break;
		case -1:
			poly.coef[y] += x;
			flag[y] = -1;
			break;
		default:
			break;
		}

	}
	for (i = MAX_DEGREE;i >= 0;--i) {
		if (flag[i] == -1) {
			if(i!=0)printf("%d%c^%d", poly.coef[i], 'x', i);
			else if (i == 0) printf("%d", poly.coef[i]);
			if (i != yMin) printf(" + ");
		}
	}
}