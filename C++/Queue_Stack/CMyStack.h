#pragma once
#include "CMyList.h"
#include <iostream>

using namespace std;

template <typename T>
class CMyStack
{
private:
	CMyList<T> m_list;

public:						
	T	 top();						// 가장 위에 있는 데이터를 보여줍니다.
	void pop();						// 가장 앞에 있는 데이터를 뽑는다. (제거한다.)
	void push(const T& data);		// 데이터를 넣는다 (이 데이터가 가장 뒤에 넣어진다.)
	void printAll();				// 데이터를 모두 출력합니다
};

template<typename T>
void CMyStack<T>::push(const T& data)
{
	m_list.push_front(data);
}

template<typename T>
T CMyStack<T>::top()
{
	return m_list.front();
}

template<typename T>
void CMyStack<T>::pop()
{
	m_list.pop_front();
}

template<typename T>
void CMyStack<T>::printAll()
{
	m_list.printAll();
}