#include <iostream>
#include <vector>
#include <list>

using namespace std;

int main() 
{
	vector<int> vec = { 1, 2, 3, 4, 5 };
	auto v_it4 = vec.begin() + 4;		//v_it4�� vec[4] ���Ҹ� ����ŵ�ϴ�.

	vec.insert(vec.begin() + 2, 0);		//v_it4 �ݺ��ڴ� ��ȿȭ�˴ϴ�.

	
	
	list<int> lst = { 1, 2, 3, 4, 5 };
		
	auto l_it4 = next(lst.begin(), 4);

	lst.insert(next(lst.begin(), 2), 0); // l_it4 �ݺ��ڴ� ������ ��ȿ�մϴ�.

	
	



	
}