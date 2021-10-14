#pragma warning(disable : 4996)
#include <stdio.h>

int main()
{
	int num, digit;
	char s[30];

	do {
		printf("숫자 입력 : "); scanf("%d", &num);
	} while (num < 0);

	itoa(num, s, 10);
	digit = strlen(s);

	printf("그 수는 %d자리입니다.", digit);
	return 0;	
}