#pragma warning(disable : 4996)
#include <stdio.h>	

/* ���� a, b �� �����Ͽ� �� ������ ��� ������ ���� ���մϴ�. */

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
	
	puts("���� a, b�� ������ �� ������ ��� ������ ���� ���մϴ�.");

	printf("a�� �� : ");
	scanf("%d", &a);
	printf("b�� �� : ");
	scanf("%d", &b);

	result = sumof(a, b);

	printf("a(%d)���� b(%d) ���� ��� ������ ���� %d �Դϴ�.\n", a, b, result);
	return;
}