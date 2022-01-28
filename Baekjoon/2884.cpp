#include <iostream>
using namespace std;

int main()
{
	int hour, minute;

	cin >> hour;
	cin >> minute;

	minute = minute - 45;
	if (minute < 0)
	{
		minute = minute + 60;
		hour = hour - 1;
		if (hour < 0)
		{
			hour = 23;
		}
	}

	cout << hour;
	cout << " ";
	cout << minute;	
}