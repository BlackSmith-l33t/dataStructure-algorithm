#include <iostream>

using namespace std;

int Fibonacci(int n)
{
	if (0 == n)
	{
		return 0;
	}
	if (1 == n)
	{
		return 1;
	}
	else if (2 == n)
	{
		return 1;
	}
	else
	{
		return Fibonacci(n - 1) + Fibonacci(n - 2);
	}
}

int main()
{
	int num = 0; 	

	num = Fibonacci(2);
	cout << num << endl;

	num = Fibonacci(3);
	cout << num << endl;
	
	num = Fibonacci(4);
	cout << num << endl;
	
	num = Fibonacci(5);
	cout << num << endl;

	num = Fibonacci(6);
	cout << num << endl;

	num = Fibonacci(7);
	cout << num << endl;

	num = Fibonacci(8);
	cout << num << endl;
}