#include <iostream>
#include <vector>
#include <list>

using namespace std;

int main() 
{
	vector<int> vec = { 1, 2, 3, 4, 5 };
	auto v_it4 = vec.begin() + 4;		//v_it4는 vec[4] 원소를 가리킵니다.

	vec.insert(vec.begin() + 2, 0);		//v_it4 반복자는 무효화됩니다.

	
	
	list<int> lst = { 1, 2, 3, 4, 5 };
		
	auto l_it4 = next(lst.begin(), 4);

	lst.insert(next(lst.begin(), 2), 0); // l_it4 반복자는 여전히 유효합니다.

	
	



	
}