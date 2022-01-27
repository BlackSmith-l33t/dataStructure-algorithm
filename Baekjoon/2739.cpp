#include <iostream>
using namespace std;

int main()
{
	int result = 0;
	int inputNum;

	cin >> inputNum;

	for (int i = 1; i <= 9; i++)
	{
		result = inputNum * i;
		cout << inputNum << " * " << i << " = " << result << endl;
	}
}