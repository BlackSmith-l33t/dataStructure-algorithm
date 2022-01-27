#include <iostream>
#include <list>
#include "CMyList.h"

//using std::list; 
using namespace std;

int main()
{
	CMyList<int> myList;

	//myList.pop_back();
	myList.push_back(10);
	myList.push_back(20);
	myList.push_back(40);
	myList.push_back(50);
	myList.push_back(60);
	myList.push_back(70);
	myList.push_back(80);
	myList.push_back(90);
	myList.push_back(100);



	/*myList.pop_back();
	myList.push_front(40);
	myList.pop_front();
	myList.clear();

	if (myList.empty())
	{
		cout << "해당 리스트는 비어있습니다." << endl;
	}
	else
	{
		cout << "해당 리스트는 비어있지 않습니다." << endl;
	}*/

	myList.printAll();
	cout << myList[0] << endl;

	CMyList<int> myList2;
	CMyList<int> myList3;

	myList2.push_back(1);
	myList2.push_back(2);

	myList3 = myList + myList2;

	myList3.printAll();


}


