#define _CRT_SECURE_NO_WARNING
#pragma warning(disable : 4996)

#include <stdio.h>

int min3(int  a, int b, int c)
{
	int min = a;

	if (b < min) { min = b; }
	if (c < min) { min = c; }

	return min;
}

int  main() {

	int a, b, c;
	printf("�� ������ �ּڰ��� ���մϴ�.\n");
	printf("a�� �� : ");    scanf("%d", &a);
	printf("b�� �� : ");    scanf("%d", &b);
	printf("c�� �� : ");    scanf("%d", &c);

	printf("�ּڰ��� %d�Դϴ�.\n", min3(a, b, c));
	return 0;
}
