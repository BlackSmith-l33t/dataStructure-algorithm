#include <iostream>
#include "CMyQueue.h"
#include "CMyStack.h"
#include <queue>

#define DEFAULT_SIZE 10

using namespace std;

int main()
{
#pragma region  Test Queue  
	CMyQueue<int> myQueue;
	
	cout << "[Queue Test]" << endl;

	for (int i = 0; i < DEFAULT_SIZE; i++)
	{
		myQueue.push(i + 1);
	}
	cout << endl;

	cout << "Queue : ";
	myQueue.printAll();
	cout << endl;

	cout << "맨 앞에 있는 데이터 : " << myQueue.front() << endl;
	cout << endl;

	cout << "=======================================" << endl;

	// pop()을 실행한 뒤 Queue안에 들어있는 데이터를 출력합니다.
	myQueue.pop();
	cout << "Queue : ";
	myQueue.printAll();
	cout << endl;

	cout << "맨 앞에 있는 데이터 : " << myQueue.front() << endl;
	cout << "=======================================" << endl;
	cout << endl;
#pragma endregion

#pragma region Test Stack
	CMyStack<int> myStack;

	cout << "[Stack Test]" << endl;

	for (int i = 0; i < DEFAULT_SIZE; i++)
	{
		myStack.push(i + 1);
	}
	cout << endl;

	cout << "Stack : ";
	myStack.printAll();
	cout << endl;

	cout << "맨 위에 있는 데이터 : " << myStack.top() << endl;
	cout << endl;

	cout << "=======================================" << endl;

	// pop()을 실행한 뒤 Stack안에 들어있는 데이터를 출력합니다.
	myStack.pop();
	cout << "Stack : ";
	myStack.printAll();
	cout << endl;

	cout << "맨 위에 있는 데이터 : " << myStack.top() << endl;
	cout << "=======================================" << endl;
#pragma endregion
}

