#pragma warning(disable : 4996)
#include <stdio.h>

int main()
{
	int i, n;
	int sum;
	puts("1���� n������ ���� ���մϴ�.");
	printf("n�� �� : ");
	scanf("%d", &n);
	sum = 0;
	i = 1;
	while (i <= n)
	{
		sum += i;
		i++;
	}

	printf("1���� %d������ ���� %d�Դϴ�.\n", n, sum);

	for (int i = 1; i <= n; i++)
	{					
		printf("%d", i);
		if (i >= n)
		{
			printf(" = ");
			break;
		}		
		printf(" + ");
		
	}
	printf("%d", sum);
	return;
}