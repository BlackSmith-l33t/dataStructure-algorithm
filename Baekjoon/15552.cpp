#include <iostream>

using namespace std;

int main()
{
	const int ARRAY_SIZE = 100;
	int count;
	int a, b;
	int result[ARRAY_SIZE];

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> count;

	for (int i = 0; i < count; i++)
	{
		cin >> a;
		cin >> b;
		if ((a >= 1 && a <= 1000) && (b >= 1 && b <= 1000))
		{
			result[i] = a + b;
			cout << result[i] << "\n";
		}		
	}
}