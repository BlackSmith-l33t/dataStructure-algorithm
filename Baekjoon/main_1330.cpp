#include <iostream>

using namespace std;

int main()
{
	int a, b;

	cin >> a;
	cin >> b;

	if (a > b && (-10000 <= a && a <= 10000) && (-10000 <= b && b <= 10000))
	{
		cout << ">" << endl;
	}
	else if (a < b && (-10000 <= a && a <= 10000) && (-10000 <= b && b <= 10000))
	{
		cout << "<" << endl;
	}
	else if (a == b && (-10000 <= a && a <= 10000) && (-10000 <= b && b <= 10000))
	{
		cout << "==" << endl;
	}
}