#pragma once
#include <assert.h>
#include <iostream>
using namespace std;

template <typename T>
struct BinaryNode
{
	T				data;
	BinaryNode<T>*	pParent;
	BinaryNode<T>*	pLeft;
	BinaryNode<T>*	pRight;

	BinaryNode<T>()
	{
		this->pParent	 = nullptr;
		this->pLeft		 = nullptr;
		this->pRight	 = nullptr;
	}

	BinaryNode<T>(T data, BinaryNode<T>* pParent, BinaryNode<T>* pLeft, BinaryNode<T>* pRight)
	{
		this->data		= data;
		this->pParent	= pParent;
		this->pLeft		= pLeft;
		this->pRight	= pRight;
	}

	bool isRoot()
	{
		return nullptr == pParent;
	}

	bool isLeftChild()
	{
		if (isRoot())
		{
			return false;
		}
		if (pParent->pLeft == this)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	bool isRightChild()
	{
		if (isRoot())
		{
			return false;
		}
		if (pParent->pRight == this)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
};

template <typename T>
class CMyBST
{
	BinaryNode<T>*	 m_pRootNode;
	unsigned int	 m_size;
public:
	CMyBST();
	~CMyBST();

	void clear();
	unsigned int size();
	bool empty();	
	void printNode(BinaryNode<T>* node);

	// 여기부터 과제
	class iterator
	{
		friend CMyBST;
	private: 
		CMyBST<T>*		m_pMyBST;
		BinaryNode<T>*	m_pBinaryNode;

	public:
		iterator();
		iterator(CMyBST<T>* pBinaryBST, BinaryNode<T>* pNode);
		~iterator();

		T&			operator*();
		iterator&	operator++();
		iterator	operator++(int);
		//iterator&	operator--();
		//iterator	operator--(int);
		bool		operator==(const iterator& _other);
		bool		operator!=(const iterator& _other); 
	};

	iterator insert(const T& target);
	iterator erase(const iterator& iter);
	iterator find(const T& target);
	iterator begin();
	iterator end();
};

template<typename T>
CMyBST<T>::CMyBST()
{
	m_pRootNode = nullptr;
	m_size = 0;
}

template<typename T>
CMyBST<T>::~CMyBST()
{
	clear();
}

template<typename T>
void CMyBST<T>::clear()
{
	//iterator iter = begin();
	//while (iter != end())
	//{
	//	//iter = earse(iter);
	//}	
}

template<typename T>
unsigned int CMyBST<T>::size()
{
	return m_size;
}

template<typename T>
bool CMyBST<T>::empty()
{
	return 0 == m_size;
}

template<typename T>
typename CMyBST<T>::iterator CMyBST<T>::begin()
{
	BinaryNode<T>* pCurrent = m_pRootNode;

	// 1. 하나도 없었다면
	if (nullptr == pCurrent)
	{
		assert(nullptr);
	}

	while (!(nullptr == pCurrent->pLeft))
	{
		pCurrent = pCurrent->pLeft;
	}
	
	return iterator(this, pCurrent);  
	//ㄴiterator *newIter = new iterator(this, pCurrent) 
	//			 return newIter; <--- 이런방식으로 구현해도 되는 것? 결국 같은 것?
}

template<typename T>
typename CMyBST<T>::iterator CMyBST<T>::end()
{
	return iterator(this, nullptr);
}

template<typename T>
CMyBST<T>::iterator::iterator()
{
	m_pMyBST		= nullptr;
	m_pBinaryNode	= nullptr;
}

template<typename T>
CMyBST<T>::iterator::iterator(CMyBST<T>* pBinaryBST, BinaryNode<T>* pNode)
{
	m_pMyBST		= pBinaryBST;
	m_pBinaryNode	= pNode;
}

template<typename T>
CMyBST<T>::iterator::~iterator()
{		
	m_pMyBST		= nullptr;
	m_pBinaryNode	= nullptr;
}

template<typename T>
T& CMyBST<T>::iterator::operator*()
{
	return m_pBinaryNode->data;
}

template<typename T>
typename CMyBST<T>::iterator& CMyBST<T>::iterator::operator++()
{
	// 0. 예외처리, 하나도 없었을 때, 이미 end() iterator였을 때
	if (nullptr == this->m_pMyBST->m_pRootNode || nullptr == m_pBinaryNode)
	{
		assert(nullptr);
	}

	BinaryNode<T>* pCurrent = this->m_pBinaryNode;
	// 1. 오른쪽 자식이 있는 경우, 오른쪽 자식으로 가서, 왼쪽 자식이 없을 때까지 내려감
	// 오른쪽 자식의 가장 작은 값이 당연히 다음 노드이다.
	if (nullptr != pCurrent->pRight)
	{	
		pCurrent = pCurrent->pRight;
		while (true)
		{
			if (nullptr == pCurrent->pLeft)
			{				
				break;
			}
			pCurrent = pCurrent->pLeft;
		}
		this->m_pBinaryNode = pCurrent;
		return *this; 
	}

	// 2. 오른쪽 자식이 없는 경우, 부모로 가야하는데 왼쪽 자식일 때까지 위로 감.
	// 나를 가장 먼저 왼쪽으로 보낸 노드가 내 다음노드다.
	else  // nullptr == pCurrent->pRight;
	{
		while (true)
		{
			// 계속 따라 올라갔는데 부모가 없을때가지 올라갔다 == 처음 노드가 가장 큰(마지막) Node였다.
			if (nullptr == pCurrent->pParent)
			{
				return *this;
			}			
			if (this->m_pBinaryNode == pCurrent->pParent->pLeft)
			{
				break;
			}			
			pCurrent = pCurrent->pParent;
		}

		this->m_pBinaryNode = pCurrent->pParent;
		return *this;
	}
}

template<typename T>
typename CMyBST<T>::iterator CMyBST<T>::iterator::operator++(int)
{
	// 0. 예외처리, 하나도 없었을 때, 이미 end() iterator였을 때
	if (nullptr == this->m_pMyBST->m_pRootNode || nullptr == m_pBinaryNode)
	{
		assert(nullptr);
	}
	
	iterator iter = iterator(this->m_pMyBST, this->m_pBinaryNode);
	++(this);

	return iter;
}

template<typename T>
bool CMyBST<T>::iterator::operator==(const iterator& _other)  // data로만 비교했을시에 문제점이 없을 시 생각해보자.
{
	bool IsSame = 
		this->m_pBinaryNode == _other->m_pBinaryNode	&&
		this->m_pMyBST == this->m_pMyBST				&&
		this->m_pBinaryNode->data == _other.m_pBinaryNode->data;
			
	return  IsSame;
}

template<typename T>
bool CMyBST<T>::iterator::operator!=(const iterator& _other)
{
	return *this == _other ? true : false;
}


template<typename T>
typename CMyBST<T>::iterator CMyBST<T>::insert(const T& target)
{
	BinaryNode<T>* newNode = new BinaryNode<T>(target, nullptr, nullptr, nullptr);
	BinaryNode<T>* pCurrent = m_pRootNode;

	// 0. 아무것도 들어있지 않을때
	if (nullptr == m_pRootNode)
	{
		m_pRootNode = newNode;
		++m_size;
		return iterator(this, newNode);
	}

	while (true)
	{
		// 1. 루트노드보다 작을 때
		if (newNode->data < pCurrent->data)
		{
			if (pCurrent->pLeft == nullptr)
			{
				m_pRootNode->pLeft = newNode;
				newNode->pParent = pCurrent;
				break;
			}
			else
			{		
				pCurrent = pCurrent->pLeft;
				if (pCurrent->pLeft == nullptr && pCurrent->data != newNode->data)
				{
					pCurrent->pLeft = newNode;
					newNode->pParent = pCurrent;
					break;
				}			
			}		
		}
		// 2. 루트노드보다 클 때
		else if (newNode->data > m_pRootNode->data)
		{
			if (pCurrent->pRight == nullptr)
			{
				pCurrent->pRight = newNode;
				newNode->pParent = pCurrent;
				break;
			}
			else
			{
				pCurrent = pCurrent->pRight;
				if (pCurrent->pRight == nullptr && pCurrent->data != newNode->data)
				{
					pCurrent->pRight = newNode;
					newNode->pParent = pCurrent;
					break;
				}
			}
		}
	    // 3. 같을때 무시
		else
		{
			delete newNode;
			return iterator(this, pCurrent);;
		}
	}

	++m_size;
	return iterator(this, newNode);
}

template<typename T>
typename CMyBST<T>::iterator CMyBST<T>::erase(const iterator& iter)
{	
	BinaryNode<T>* eraseNode = iter.m_pBinaryNode;
	BinaryNode<T>* pCurrent;

	// 데이터가 없을 경우 
	if (nullptr == iter.m_pBinaryNode || nullptr == iter.m_pMyBST || 0 == this->m_size)
	{
		assert(nullptr);
	}

	// 찾을 노드가 루트노드 일 경우
	if (eraseNode->isRoot())
	{
		// 삭제할 노드에 양쪽에 자식이 있을 경우
		if (eraseNode->pLeft != nullptr && eraseNode->pRight != nullptr)
		{
			pCurrent = m_pRootNode = eraseNode->pLeft;
				
			if (pCurrent->pRight != nullptr)
			{
				while (pCurrent->pRight != nullptr)
				{
					pCurrent = pCurrent->pRight;
				}
				pCurrent->pRight = eraseNode->pRight;
			}
			else
			{
				pCurrent->pRight = eraseNode->pRight;
			}
			delete eraseNode;
			--m_size;
		}
		// 삭제할 노드에 왼쪽 자식만이 있을 경우
		else if (eraseNode->pLeft != nullptr && eraseNode->pRight == nullptr)
		{
			m_pRootNode = eraseNode->pLeft;
			delete eraseNode;
			--m_size;
		}
		// 삭제할 노드에 오른쪽 자식만 있을 경우
		else if (eraseNode->pLeft == nullptr && eraseNode->pRight != nullptr)
		{
			m_pRootNode = eraseNode->pRight;
			delete eraseNode;
			--m_size;
		}
		// 0-3. 자식이 없을 경우
		else
		{
			delete eraseNode;
			--m_size;
		}
	}
	// 삭제할 노드가 왼쪽자식 일 경우
	else if (eraseNode->isLeftChild())
	{
		// 삭제할 노드에 양쪽에 자식이 있을 경우
		if (eraseNode->pLeft != nullptr && eraseNode->pRight != nullptr)
		{
			pCurrent = eraseNode->pLeft;
			eraseNode->pParent->pLeft = pCurrent;
			pCurrent->pParent = eraseNode->pParent;

			if (pCurrent->pRight != nullptr)
			{
				while (pCurrent->pRight != nullptr)
				{
					pCurrent = pCurrent->pRight;
				}
				pCurrent->pRight = eraseNode->pRight;
			}
			else
			{
				pCurrent->pRight = eraseNode->pRight;
			}
			delete eraseNode;
			--m_size;
		}
		// 삭제할 노드에 왼쪽 자식만이 있을 경우
		else if (eraseNode->pLeft != nullptr && eraseNode->pRight == nullptr)
		{
			pCurrent = eraseNode->pLeft;
			eraseNode->pParent->pLeft = pCurrent;
			delete eraseNode;
			--m_size;
		}
		// 삭제할 노드에 오른쪽 자식만 있을 경우
		else if (eraseNode->pLeft == nullptr && eraseNode->pRight != nullptr)
		{
			pCurrent = eraseNode->pRight;
			eraseNode->pParent->pLeft = pCurrent;
			delete eraseNode;
			--m_size;
		}
		// 0-3. 자식이 없을 경우
		else
		{
			delete eraseNode;
			--m_size;
		}
	}
	// 삭제할 노드가 오른쪽 자식 일 경우
	else if (eraseNode->isRightChild())
	{
		// 삭제할 노드에 양쪽에 자식이 있을 경우
		if (eraseNode->pLeft != nullptr && eraseNode->pRight != nullptr)
		{
			pCurrent = eraseNode->pLeft;
			eraseNode->pParent->pRight = pCurrent;

			if (pCurrent->pRight != nullptr)
			{
				while (pCurrent->pRight != nullptr)
				{
					pCurrent = pCurrent->pRight;
				}
				pCurrent->pRight = eraseNode->pRight;
			}
			else
			{
				pCurrent->pRight = eraseNode->pRight;
			}
			delete eraseNode;
			--m_size;
		}
		// 삭제할 노드에 왼쪽 자식만이 있을 경우
		else if (eraseNode->pLeft != nullptr && eraseNode->pRight == nullptr)
		{
			pCurrent = eraseNode->pLeft;
			eraseNode->pParent->pRight = pCurrent;
			delete eraseNode;
			--m_size;
		}
		// 삭제할 노드에 오른쪽 자식만 있을 경우
		else if (eraseNode->pLeft == nullptr && eraseNode->pRight != nullptr)
		{
			pCurrent = eraseNode->pRight;
			eraseNode->pParent->pRight = pCurrent;
			delete eraseNode;
			--m_size;
		}
		// 0-3. 자식이 없을 경우
		else
		{
			delete eraseNode;
			--m_size;
		}
	}

	// 삭제할 값이 노드에 없을 때	
	return iterator();
}


template<typename T>
typename CMyBST<T>::iterator CMyBST<T>::find(const T& target)
{	
	BinaryNode<T>* pCurrent = m_pRootNode;

	if (nullptr == m_pRootNode || 0 == m_size)
	{
		assert(nullptr);
	}

	if (target == m_pRootNode->data)
	{
		return iterator(this, m_pRootNode);
	}

	while (nullptr != pCurrent)
	{
		if (target < pCurrent->data)
		{
			pCurrent = m_pRootNode->pLeft;
		}
		else if (target > m_pRootNode->data)
		{
			pCurrent = m_pRootNode->pRight;
		}
		else
		{
			return iterator(this, pCurrent);
		}
	}
	return end();
}

template<typename T>
void CMyBST<T>::printNode(BinaryNode<T>* node)
{
	// TODO : 중위순회로 출력할것 
	if (node == nullptr)
	{
		return;
	}

	printNode(node->pLeft);
	cout << node->data;
	printNode(node->pRight);
}






