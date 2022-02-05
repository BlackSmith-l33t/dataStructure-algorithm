#pragma once
#include "CMyList.h"
#include <iostream>

using namespace std;

template <typename T>
class CMyQueue
{
private:
	CMyList<T> m_list;
public:	
	T	 front();					// ���� �տ� �ִ� �����͸� ����. 
	void push(const T& data);		// �����͸� �ִ´� (�� �����Ͱ� ���� �ڿ� �־�����.)
	void pop();						// ���� �տ� �ִ� �����͸� �̴´�. (�����Ѵ�.)
	void printAll();				// �����͸� ��� ����մϴ�.

};

template<typename T>
void CMyQueue<T>::push(const T& data)
{
	m_list.push_back(data);
}

template<typename T>
T CMyQueue<T>::front()
{	
	return m_list.front();
}

template<typename T>
void CMyQueue<T>::pop()
{
	m_list.pop_front();
}

template<typename T>
void CMyQueue<T>::printAll()
{
	m_list.printAll();
}


