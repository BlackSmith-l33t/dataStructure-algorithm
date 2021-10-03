#include <stdio.h>

int max4(int a, int b, int c, int d)
{
	int max = a;

	if (b > max)
	{
		max = (b > c) ? b : c;		
		max = max > d ? max : d;
	}
	else
	{
		max = max > c ? max : c;
		max = max > d ? max : d;
	}	
	
	return max;
}

int main() 
{
	int max = max4(2, 3, 4, 1);

	printf("%d", max);
}