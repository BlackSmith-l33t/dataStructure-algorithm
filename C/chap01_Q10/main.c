#pragma warning(disable : 4996)
#include <stdio.h>

int main()
{
	int a, b;
	
	printf("a�� �� : "); scanf("%d", &a);
	printf("b�� �� : "); scanf("%d", &b);

	while (a >= b)
	{
		printf("a���� ū ���� �Է��ϼ���!\n");
		printf("b�� �� : "); scanf("%d", &b);
	}

	printf("b - a�� %d�Դϴ�.", b - a);
	return 0;
}