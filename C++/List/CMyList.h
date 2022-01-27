#pragma once
#include <assert.h>
#include <iostream>

using namespace std;

// Node
template <typename T>
struct Node
{
	T		m_data;
	Node* pPrev;
	Node* pNext;

	Node()
	{
		pPrev = nullptr;
		pNext = nullptr;

	}
	Node(T _data, Node* _prev, Node* _next)
	{
		m_data = _data;
		pPrev = _prev;
		pNext = _next;
	}
	~Node()
	{

	}
};

template <typename T>
class CMyList
{
private:
	Node<T>* pHeadNode;
	Node<T>* pTailNode;
	int			m_size;

public:
	CMyList();
	~CMyList();
	CMyList(const CMyList& target); // ��������� 

	void push_back(const T& data);
	void pop_back();
	void push_front(const T& data);
	void pop_front();

	int size();
	bool empty();
	void clear();
	void printAll();

	T operator[](int n);
	CMyList operator+(const CMyList& _other);
	CMyList& operator+=(const CMyList& _other);

};

template<typename T>
inline CMyList<T>::CMyList()
{
	pHeadNode = nullptr;
	pTailNode = nullptr;
	m_size = 0;

}

template<typename T>
inline CMyList<T>::~CMyList()
{
	// TODO : �Ҹ��� ����� �޸� ���Ÿ� ����ؾ���.
}

template<typename T>
CMyList<T>::CMyList(const CMyList& target)
{
	pHeadNode = target.pHeadNode;
	pTailNode = target.pTailNode;
	m_size = target.m_size;
}

template<typename T>
void CMyList<T>::push_back(const T& data)
{
	if (m_size > 0)
	{
		Node<T>* newNode = new Node<T>(data, pTailNode, nullptr);

		pTailNode->pNext = newNode;
		pTailNode = newNode;
	}
	else
	{
		Node<T>* newNode = new Node<T>(data, nullptr, nullptr);

		pHeadNode = newNode;
		pTailNode = newNode;
	}
	m_size++;
}

template<typename T>
void CMyList<T>::pop_back()
{
	assert(!(0 == m_size));

	// TODO m_size�� 1�϶� �����߻�?
	Node<T>* newNode = new Node<T>(pTailNode->pPrev->m_data, pTailNode->pPrev, nullptr);
	delete pTailNode;
	pTailNode = newNode;
	pTailNode->pNext = nullptr;
	m_size--;
}

template<typename T>
void CMyList<T>::push_front(const T& data)
{
	if (m_size > 0)
	{
		Node<T>* newNode = new Node<T>(data, nullptr, pHeadNode);
		pHeadNode->pPrev = newNode;
		pHeadNode = newNode;
	}
	else
	{
		Node<T>* newNode = new Node<T>(data, nullptr, nullptr);

		pHeadNode = newNode;
		pTailNode = newNode;
	}
	m_size++;
}

template<typename T>
void CMyList<T>::pop_front()
{
	assert(!(m_size == 0));

	Node<T>* newNode = new Node<T>(pHeadNode->pNext->m_data, nullptr, pHeadNode->pNext->pNext);
	delete pHeadNode;
	pHeadNode = newNode;
	m_size--;
}

template<typename T>
int CMyList<T>::size()
{
	return m_size;
}

template<typename T>
bool CMyList<T>::empty()
{
	return m_size == 0;
}

template<typename T>
void CMyList<T>::clear()
{
	Node<T>* dummyNode = new Node<T>(pHeadNode->pNext->m_data, nullptr, pHeadNode->pNext->pNext);

	for (int i = 0; i < m_size - 1; i++)
	{
		delete pHeadNode;
		pHeadNode = dummyNode;
	}
	m_size = 0;
	delete pTailNode;
	delete dummyNode;
}

// �߰� �ǽ�

// ����Ʈ�� ���� ��� Node���� �����͸� ����ϴ� �Լ� ����
template<typename T>
void CMyList<T>::printAll()
{

	if (0 == m_size)
	{
		cout << "�迭�� ����ֽ��ϴ�." << endl;
		return;
	}
	else
	{
		Node<T>* printNode = new Node<T>(pHeadNode->m_data, pHeadNode->pPrev, pHeadNode->pNext);

		int count = m_size;
		while (count)
		{
			count--;
			cout << printNode->m_data;
			if (count > 0)
			{
				cout << ", ";
			}
			printNode = printNode->pNext;
		}
		cout << endl;
	}

}

// ����Ʈ ���� n��° Node�� �����͸� ��ȯ�ϴ� []������ ������
template<typename T>
T CMyList<T>::operator[](int n)
{
	assert(m_size != 0);

	Node<T>* dummyNode = pHeadNode;

	if (n == 0)
	{
		return dummyNode->m_data;
	}
	else
	{
		for (int i = 0; i < n - 1; i++)
		{
			dummyNode = pHeadNode->pNext;
			pHeadNode = dummyNode;
		}
	}

	return dummyNode->m_data;
}

// ����Ʈ�� ���� �ٸ� ����Ʈ�� ó���� ������ ����Ʈ�� ��ȯ�ϴ� +������ ������
template <typename T>
CMyList<T> CMyList<T>::operator+(const CMyList& _other)
{
	// 1. list1 tail->next �� list2->prev�� �����Ѵ�.

	if (pTailNode == nullptr)
	{
		pHeadNode = _other.pHeadNode;
		pTailNode = _other.pHeadNode;
 	}
	else
	{
		_other.pHeadNode->pPrev = pTailNode;
		pTailNode->pNext = _other.pHeadNode;
		pTailNode = _other.pTailNode;
	}
	m_size += _other.m_size;

	return *this;
}

template<typename T>
CMyList<T>& CMyList<T>::operator+=(const CMyList& _other)
{
	// TODO: ���⿡ ��ȯ ������ �����մϴ�.
}







