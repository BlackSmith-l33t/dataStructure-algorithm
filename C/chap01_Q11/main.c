#pragma warning(disable : 4996)
#include <stdio.h>

int main()
{
	int num, digit;
	char s[30];

	do {
		printf("���� �Է� : "); scanf("%d", &num);
	} while (num < 0);

	itoa(num, s, 10);
	digit = strlen(s);

	printf("�� ���� %d�ڸ��Դϴ�.", digit);
	return 0;	
}