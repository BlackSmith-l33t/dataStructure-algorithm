#include <iostream>
#include <vector>
#include <assert.h>
#include "CMyvector.h"

using namespace std;

template <typename T>
void print_vectorData(vector<T> vec)
{
	cout << "vector data : ";
	for (int i = 0; i < vec.size(); ++i)
	{
		cout << vec[i] << ", ";
	}
	cout << endl;
}

template <typename T>
void print_vectorData(CMyVector<T> vec)
{
	cout << "vector data : ";
	for (int i = 0; i < vec.size(); i++)
	{
		cout << vec[i] << ", ";
	}
	cout << endl;
}

int main()
{
	CMyVector<int> myVector;
	cout << "push_back(10)" << endl;
	myVector.push_back(10);
	print_vectorData(myVector);
	cout << "vector.size() = " << myVector.size() << endl;
	cout << "vector.capacity() = " << myVector.capacity() << endl;

	cout << "push_back(20)" << endl;
	myVector.push_back(20);
	print_vectorData(myVector);
	cout << "vector.size() = " << myVector.size() << endl;
	cout << "vector.capacity() = " << myVector.capacity() << endl;

	cout << "push_back(30)" << endl;
	myVector.push_back(30);
	print_vectorData(myVector);
	cout << "vector.size() = " << myVector.size() << endl;
	cout << "vector.capacity() = " << myVector.capacity() << endl;

	cout << "pop_back()" << endl;
	myVector.pop_back();
	print_vectorData(myVector);
	cout << "vector.size() = " << myVector.size() << endl;
	cout << "vector.capacity() = " << myVector.capacity() << endl;

	for (int i = 0; i < 10; i++)
	{
		myVector.push_back(i);
		cout << "vector.size() = " << myVector.size() << endl;
		cout << "vector.capacity() = " << myVector.capacity() << endl;
	}

	print_vectorData(myVector);

	cout << "myVector.at(i) :" << myVector.at(2) << endl;
	cout << "myVector[i] :" << myVector[2] << endl;

	for (int i = 0; i < 10; i++)
	{
		myVector.pop_back();
	}
	
	cout << "vector.size() = " << myVector.size() << endl;
	cout << "vector.capacity() = " << myVector.capacity() << endl;

	return 0;
}