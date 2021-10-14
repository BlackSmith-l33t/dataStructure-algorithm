#pragma warning(disable : 4996)
#include <stdio.h>

int main()
{
	int a, b;
	
	printf("a의 값 : "); scanf("%d", &a);
	printf("b의 값 : "); scanf("%d", &b);

	while (a >= b)
	{
		printf("a보다 큰 값을 입력하세요!\n");
		printf("b의 값 : "); scanf("%d", &b);
	}

	printf("b - a는 %d입니다.", b - a);
	return 0;
}