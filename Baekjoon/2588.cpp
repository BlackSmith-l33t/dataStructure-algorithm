#include <iostream>
#include <string>

using namespace std;

int main()
{
	int num1, num2;
	int result1 = 0, result2 = 0, result3 = 0;
	int multiple = 0;
	string numberToString;

	cin >> num1;	
	cin >> num2;
	
	numberToString = to_string(num2);
	
	multiple = ((int)(numberToString.at(2))) - 48;
	result1 = num1 * multiple;	

	multiple = ((int)(numberToString.at(1))) - 48;
	result2 = num1 * multiple;	

	multiple = ((int)(numberToString.at(0))) - 48;;
	result3 = num1 * multiple;

	cout << result1 << endl;
	cout << result2 << endl;
	cout << result3 << endl;
	cout << num1 * num2 << endl;
}