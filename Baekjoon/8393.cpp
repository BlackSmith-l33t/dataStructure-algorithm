#include <iostream>

using namespace std;

int main()
{
	int num;
	int result = 0;

	cin >> num;

	for (int i = 0; i <= num; i++)
	{
		result += i; // result = result + i
	}

	cout << result << endl;
}