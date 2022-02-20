#include <iostream>

using namespace std;

int main()
{
	int score;
	char grade;

	cin >> score;

	if (score >= 90 || score == 100)
	{
		grade = 'A';
		cout << grade;
	}
	else if (score >= 80 && score <= 89)
	{
		grade = 'B';
		cout << grade; 
	}
	else if (score >= 70 && score <= 79)
	{
		grade = 'C';
		cout << grade;
	}
	else if (score >= 60 && score <= 69)
	{
		grade = 'D';
		cout << grade;
	}
	else
	{
		grade = 'F';
		cout << grade;
	}

	

}