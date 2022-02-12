#include <iostream>
#include "CMyBST.h"

using namespace std;

int main()
{
	CMyBST<int> myBST;
	
	myBST.insert(10);
	myBST.insert(5);
	myBST.insert(4);
	myBST.insert(2);
	myBST.insert(2);
	myBST.insert(20);
	myBST.insert(25);
	myBST.insert(30);
	
	//myBST.erase(myBST.find(30));

}
