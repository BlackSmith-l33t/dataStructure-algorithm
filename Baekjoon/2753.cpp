#include <iostream>

using namespace std;

int main()
{
	int year = 0;
	int result = 0;

	cin >> year;
	
	if ((year % 100 == 0) || (year % 4 == 0))
	{
		result = (year % 400 == 0) || (year % 100 != 0) ? 1 : 0;
	}
	else
	{
		result = 0;
	}	
	cout << result << endl;	
}