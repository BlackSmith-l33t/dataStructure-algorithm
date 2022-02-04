#include <iostream>
#include "CMyQueue.h"
#include "CMyStack.h"
#include <queue>

#define DEFAULT_SIZE 10

using namespace std;

int main()
{
	CMyQueue<int> myQueue;
	queue<int> stlQ;

	for (int i = 0; i < DEFAULT_SIZE; i++)
	{
		stlQ.push(i);
		myQueue.push(i);
	}
}

