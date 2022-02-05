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
	T	 top();						// ���� ���� �ִ� �����͸� �����ݴϴ�.
	void pop();						// ���� �տ� �ִ� �����͸� �̴´�. (�����Ѵ�.)
	void push(const T& data);		// �����͸� �ִ´� (�� �����Ͱ� ���� �ڿ� �־�����.)
	void printAll();				// �����͸� ��� ����մϴ�
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