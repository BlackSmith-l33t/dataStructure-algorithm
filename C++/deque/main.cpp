#include <iostream>
#include <deque>

using namespace std;;

int main() {
	deque<int> deq = { 1, 2, 3, 4, 5 };

	deq.push_front(0); // 맨 앞에 0 추가 : { 0, 1, 2, 3, 4, 5 }

	deq.push_back(6);  // 맨 뒤에 6 추가 : { 0, 1, 2, 3, 4, 5, 6 }
	
	deq.insert(deq.begin() + 2, 10); // 맨 앞에서 2칸 뒤에 10 추가 : { 0, 1, 10, 2, 3, 4, 5, 6 }

	deq.pop_back();    // 맨 뒤 원소 삭제 : { 0, 1, 10, 2, 3, 4, 5 }

	deq.pop_front();   // 맨 앞 원소 삭제 : { 1, 10 , 2, 3, 4, 5 }

	deq.erase(deq.begin() + 1); // { 1, 2, 3, 4, 5 }

	deq.erase(deq.begin() + 3, deq.end());  // { 1, 2, 3 }
}