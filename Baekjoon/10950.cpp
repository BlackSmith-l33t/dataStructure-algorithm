#include <iostream>

using namespace std;


int main()
{
	const int ARRAYCOUNT = 100;

	int count = 0;
	int a, b;
	int result[ARRAYCOUNT];
	cin >> count;
	//cout << endl;

	for (int i = 0; i < count; i++)
	{
		cin >> a;
		cin >> b;
		result[i] = a + b;
	}

	for (int i = 0; i < count; i++)
	{
		cout << result[i] << endl;
	}
}