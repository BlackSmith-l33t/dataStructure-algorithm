#pragma once
#include <iostream>
#include <assert.h>

// Node
template <typename T>
struct Node
{
	T	  m_data;
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
	Node<T>* pHeadNode;
	Node<T>* pTailNode;
	int			m_size;

public:
	CMyList();
	~CMyList();

	void push_back(const T& data);
	void pop_back();
	void push_front(const T& data);
	void pop_front();

	T	 front();
	T	 operator[](int n);

	int size() const;
	bool empty();
	void clear();
};

template<typename T>
CMyList<T>::CMyList()
{
	pHeadNode = nullptr;
	pTailNode = nullptr;
	m_size = 0;
}

template<typename T>
CMyList<T>::~CMyList()
{
	clear();
}

template<typename T>
void CMyList<T>::push_back(const T& data)
{
	Node<T>* newNode = new Node<T>(data, nullptr, nullptr);
	if (m_size > 0)
	{
		newNode->pPrev = pTailNode;
		pTailNode->pNext = newNode;
		pTailNode = newNode;
	}
	else
	{
		pHeadNode = newNode;
		pTailNode = newNode;
	}
	m_size++;
}

template<typename T>
void CMyList<T>::pop_back()
{
	if (0 == m_size)
	{
		// assert(0 == m_size);
		return;
	}
	else if (1 == m_size)
	{
		Node<T>* pDeleteNode = pTailNode;
		pTailNode = nullptr;
		pHeadNode = nullptr;
		delete pDeleteNode;

		m_size--;
	}
	else
	{
		Node<T>* pDeleteNode = pTailNode;
		pTailNode = pTailNode->pPrev;
		pTailNode->pNext = nullptr;
		delete pDeleteNode;

		m_size--;
	}
}

template<typename T>
void CMyList<T>::push_front(const T& data)
{
	Node<T>* newNode = newNode<T>(data, nullptr, nullptr);
	if (m_size > 0)
	{
		newNode->pNext = pHeadNode;
		pHeadNode->pPrev = newNode;
		pHeadNode = newNode;
	}
	else
	{
		pHeadNode = newNode;
		pTailNode = newNode;
	}
	m_size++;
}

template<typename T>
void CMyList<T>::pop_front()
{
	if (0 == m_size)
	{
		// assert(0 == m_size);
		return;
	}
	else if (1 == m_size)
	{
		Node<T>* pDeleteNode = pHeadNode;
		pTailNode = nullptr;
		pHeadNode = nullptr;
		delete pDeleteNode;

		m_size--;
	}
	else
	{
		Node<T>* pDeleteNode = pHeadNode;
		pHeadNode = pHeadNode->pNext;
		pHeadNode->pPrev = nullptr;
		delete pDeleteNode;

		m_size--;
	}
}

template<typename T>
int CMyList<T>::size() const
{
	return m_size;
}

template<typename T>
bool CMyList<T>::empty()
{
	return 0 == m_size;
}

template<typename T>
void CMyList<T>::clear()
{
	while (!empty())
	{
		pop_back();
	}
}

template<typename T>
 T CMyList<T>::front()
{
	if (0 == m_size)
	{
		// assert(0 == m_size);
		return;
	}

	return pHeadNode->m_data[0];
}

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