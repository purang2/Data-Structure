#include <stdio.h>

int fact(int n) {

	if (n <= 1) return 1;
	else return n * fact(n - 1);
}

void main() {

	int N, K, i, sum = 0;
	int *psum;
	
	psum = &N;
	printf("N , K: ");
	scanf_s("%d%d", &N, &K);


	/*�˰��� : 
	(a) ���� n���� ���� ����ϰ� 
	(b) for���� ���� k�� �ݺ� 
	(c) while���� ���� ��� �ڸ����� factorial sum
    (d) sum�� ����� 0���� �ʱ�ȭ 
	*/
	printf("%d ", N);

	for (i = 0; i < K - 1;i++)
	{
		while(N!=0){
			sum += fact(N % 10); 
			N /= 10;    
		}
		printf("%d ", sum);
		*psum = sum;
		sum = 0;	
	}

}