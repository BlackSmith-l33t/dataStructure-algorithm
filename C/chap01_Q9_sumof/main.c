#pragma warning(disable : 4996)
#include <stdio.h>	

/* 정수 a, b 를 포함하여 그 사이의 모든 정수의 합을 구합니다. */

int sumof(int a, int b)
{
	int sum = 0;

	for (int i = a; i <= b; i++)
	{
		sum += i;
	}

	return sum;
}

int main()
{
	int a, b;
	int result;
	
	puts("정수 a, b를 포함한 그 사이의 모든 정수의 합을 구합니다.");

	printf("a의 값 : ");
	scanf("%d", &a);
	printf("b의 값 : ");
	scanf("%d", &b);

	result = sumof(a, b);

	printf("a(%d)부터 b(%d) 사이 모든 정수의 합은 %d 입니다.\n", a, b, result);
	return;
}