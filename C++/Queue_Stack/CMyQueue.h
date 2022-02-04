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
	CMyQueue();
	~CMyQueue();

	T	 front();					// ���� �տ� �ִ� �����͸� ����. 
	void push(const T& data);		// �����͸� �ִ´� (�� �����Ͱ� ���� �ڿ� �־�����.)
	void pop();						// ���� �տ� �ִ� �����͸� �̴´�. (�����Ѵ�.)
	void printAll(CMyList<T> list);

};

template<typename T>
CMyQueue<T>::CMyQueue()
{

}

template<typename T>
CMyQueue<T>::~CMyQueue()
{

}

template<typename T>
void CMyQueue<T>::push(const T& data)
{
	m_list.push_front(data);
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
void CMyQueue<T>::printAll(CMyList<T> list)
{
	for (int i = 0; i < list.m_size; i++)
	{
		cout << list[i] << ", ";
	}
}


