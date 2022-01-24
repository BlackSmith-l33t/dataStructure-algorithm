#include <iostream>
#include <vector>
#include <algorithm>
#include <random>	

using namespace std;

#define N 10

bool isExist(vector<int> array, int i);
vector<int> randomInputNum(vector<int>* target);

int main()
{
	bool IsInclude = false;
	vector<int> arrayA;

	int i = 7;
	randomInputNum(&arrayA);
	IsInclude = isExist(arrayA, i);

	if (IsInclude == true)
	{
		cout << i << "은 배열에 포함되어 있습니다." << endl;
	}
	else
	{
		cout << i << "은 배열에 포함되어 있지않습니다." << endl;
	}
}


bool isExist(vector<int> array, int i)
{
	int firstIndex = 0;
	int lastIndex = N - 1;
	int mid;

	while (firstIndex <= lastIndex)
	{
		mid = ((firstIndex + lastIndex) / 2);
		if (array.at(mid) == i)
		{
			return true;
		}
		else if (array.at(mid) > i)
		{
			lastIndex = mid - 1;
		}
		else
		{
			firstIndex = mid + 1;
		}
	}
	return false;
}

vector<int> randomInputNum(vector<int>* target)
{
	int randomNum = 0;

	random_device rd;
	mt19937 rand(rd());
	uniform_int_distribution<int> dis(1, N);

	for (int i = 0; i < N; i++)
	{
		randomNum = dis(rand);
		target->push_back(randomNum);
	}

	sort(target->begin(), target->end());

	return *target;
}