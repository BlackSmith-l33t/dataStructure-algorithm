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

	cout << "�� �տ� �ִ� ������ : " << myQueue.front() << endl;
	cout << endl;

	cout << "=======================================" << endl;

	// pop()�� ������ �� Queue�ȿ� ����ִ� �����͸� ����մϴ�.
	myQueue.pop();
	cout << "Queue : ";
	myQueue.printAll();
	cout << endl;

	cout << "�� �տ� �ִ� ������ : " << myQueue.front() << endl;
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

	cout << "�� ���� �ִ� ������ : " << myStack.top() << endl;
	cout << endl;

	cout << "=======================================" << endl;

	// pop()�� ������ �� Stack�ȿ� ����ִ� �����͸� ����մϴ�.
	myStack.pop();
	cout << "Stack : ";
	myStack.printAll();
	cout << endl;

	cout << "�� ���� �ִ� ������ : " << myStack.top() << endl;
	cout << "=======================================" << endl;
#pragma endregion
}

