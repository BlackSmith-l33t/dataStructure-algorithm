#pragma warning(disable : 4996)
#include <stdio.h>

int main()
{
	int a = 1;
	int n;
	int sum = 0;

	printf("n °ª ÀÔ·Â : ");
	scanf("%d", &n);
	
	while ((n - a) >= 1)
	{
		sum += (a + n);
		a++;
		n--;
	}

	printf("%d", sum);
	return;
}