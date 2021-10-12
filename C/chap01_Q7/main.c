#pragma warning(disable : 4996)
#include <stdio.h>

int main()
{
	int i, n;
	int sum;
	puts("1부터 n까지의 합을 구합니다.");
	printf("n의 값 : ");
	scanf("%d", &n);
	sum = 0;
	i = 1;
	while (i <= n)
	{
		sum += i;
		i++;
	}

	printf("1부터 %d까지의 합은 %d입니다.\n", n, sum);

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