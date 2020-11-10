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


	/*알고리즘 : 
	(a) 최초 n값을 먼저 출력하고 
	(b) for문을 통한 k번 반복 
	(c) while문을 통한 모든 자릿수별 factorial sum
    (d) sum값 출력후 0으로 초기화 
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