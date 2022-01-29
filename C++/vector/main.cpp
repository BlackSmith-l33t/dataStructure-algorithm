#include <iostream>
#include <vector>
#include "CMyVector.h"

using namespace std;

int main()
{
	CMyVector<int> myVector;

	myVector.push_back(10);
	myVector.push_back(20);
	myVector.push_back(30);

	cout << myVector.at(0) << endl;
	cout << myVector[0] << endl;

	myVector.pop_back();
	myVector.pop_back();
	myVector.pop_back();
	//myVector.pop_back();

	

	//CMyVector<int>::iterator iter;

	//// iterator 활용
	//cout << "iter : ";
	//for (iter = myVector.begin(); iter != myVector.end(); ++iter)
	//{
	//	cout << *iter << ",";
	//}
	//cout << endl << endl;

	//// iter++ test
	//iter = myVector.begin();
	//cout << "iter++ : " << *(iter++) << endl;
	//cout << "iter   : " << *iter << endl;
	//cout << endl;

	//// iter-- test
	//cout << "iter-- : " << *(iter--) << endl;
	//cout << "iter   : " << *iter << endl;
	//cout << endl;

	//// ++iter test
	//++iter = myVector.begin();
	//cout << "++iter : " << *(++iter) << endl;
	//cout << "iter   : " << *iter << endl;
	//cout << endl;

	//// --iter test	
	//cout << "--iter : " << *(--iter) << endl;
	//cout << "iter   : " << *iter << endl;
	//cout << endl;

//#pragma region iter != otherIter test
//
//	iter = myVector.begin();
//
//	cout << "iter = myVector.begin()" << endl;
//	cout << "iter != myVector.end()" << endl;
//	if (iter != myVector.end())
//	{
//
//		cout << "=> iterator의 위치가 서로 다릅니다." << endl;
//	}
//	else
//	{
//		cout << "=> iterator의 위치가 서로 같습니다." << endl;
//	}
//
//	cout << "===================================" << endl << endl;
//
//	iter = myVector.end();
//	cout << "iter = myVector.end()" << endl;
//	cout << "iter != myVector.end()" << endl;
//	if (iter != myVector.end())
//	{
//		cout << "=> iterator의 위치가 서로 다릅니다." << endl;
//	}
//	else
//	{
//		cout << "=> iterator의 위치가 서로 같습니다." << endl;
//	}
//	cout << "===================================" << endl << endl;
//#pragma endregion
//
//#pragma region iter == otherIter test
//
//	iter = myVector.begin();
//
//	cout << "iter = myVector.begin()" << endl;
//	cout << "iter == myVector.end()" << endl;
//	if (iter == myVector.end())
//	{
//
//		cout << "=> iterator의 위치가 서로 같습니다." << endl;
//	}
//	else
//	{
//		cout << "=> iterator의 위치가 서로 다릅니다." << endl;
//	}
//
//	cout << "===================================" << endl << endl;
//
//	iter = myVector.end();
//	cout << "iter = myVector.end()" << endl;
//	cout << "iter == myVector.end()" << endl;
//	if (iter == myVector.end())
//	{
//		cout << "=> iterator의 위치가 서로 같습니다." << endl;
//	}
//	else
//	{
//		cout << "=> iterator의 위치가 서로 다릅니다." << endl;
//	}
//#pragma endregion
//
//













}