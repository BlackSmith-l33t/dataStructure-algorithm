#pragma warning(disable : 4996)
#include <stdio.h>

int sumof(int a, int b)
{
	int i, min, max;
	int sum = 0;

	if (a < b)
	{
		min = a;
		max = b;
	}
	else
	{
		min = b; 
		max = a;
	}

	for (int i = min; i <= max; i++)
	{
		sum += i;
	}

	return sum;
}

int main()
{
	int a, b;
	int sum; 
	
	printf("a �� : "); scanf("%d", &a);
	printf("b �� : "); scanf("%d", &b);

	printf("���� a, b ������ ��� ������ ���� %d�Դϴ�.\n", sumof(a, b));

	return 0;
}
