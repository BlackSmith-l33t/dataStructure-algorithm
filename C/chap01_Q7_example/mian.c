#pragma warning(disable : 4996)
#include <stdio.h>

int main()
{
	int i, n;
	int sum;

	puts("1���� n������ ���� ���մϴ�.");

	printf("n�� ��	: ");
	scanf("%d", &n);

	sum = 0;

	for (i = 0; i <= n; i++)
	{
		sum += i;
	}

	for (i = 1; i < n; i++)
	{
		printf("%d + ", i);
	}
	printf("%d = %d\n", n, sum);
	return;
}