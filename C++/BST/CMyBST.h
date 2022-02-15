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

	// ������� ����
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

	// 1. �ϳ��� �����ٸ�
	if (nullptr == pCurrent)
	{
		assert(nullptr);
	}

	while (!(nullptr == pCurrent->pLeft))
	{
		pCurrent = pCurrent->pLeft;
	}
	
	return iterator(this, pCurrent);  
	//��iterator *newIter = new iterator(this, pCurrent) 
	//			 return newIter; <--- �̷�������� �����ص� �Ǵ� ��? �ᱹ ���� ��?
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
	// 0. ����ó��, �ϳ��� ������ ��, �̹� end() iterator���� ��
	if (nullptr == this->m_pMyBST->m_pRootNode || nullptr == m_pBinaryNode)
	{
		assert(nullptr);
	}

	BinaryNode<T>* pCurrent = this->m_pBinaryNode;
	// 1. ������ �ڽ��� �ִ� ���, ������ �ڽ����� ����, ���� �ڽ��� ���� ������ ������
	// ������ �ڽ��� ���� ���� ���� �翬�� ���� ����̴�.
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

	// 2. ������ �ڽ��� ���� ���, �θ�� �����ϴµ� ���� �ڽ��� ������ ���� ��.
	// ���� ���� ���� �������� ���� ��尡 �� ��������.
	else  // nullptr == pCurrent->pRight;
	{
		while (true)
		{
			// ��� ���� �ö󰬴µ� �θ� ���������� �ö󰬴� == ó�� ��尡 ���� ū(������) Node����.
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
	// 0. ����ó��, �ϳ��� ������ ��, �̹� end() iterator���� ��
	if (nullptr == this->m_pMyBST->m_pRootNode || nullptr == m_pBinaryNode)
	{
		assert(nullptr);
	}
	
	iterator iter = iterator(this->m_pMyBST, this->m_pBinaryNode);
	++(this);

	return iter;
}

template<typename T>
bool CMyBST<T>::iterator::operator==(const iterator& _other)  // data�θ� �������ÿ� �������� ���� �� �����غ���.
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

	// 0. �ƹ��͵� ������� ������
	if (nullptr == m_pRootNode)
	{
		m_pRootNode = newNode;
		++m_size;
		return iterator(this, newNode);
	}

	while (true)
	{
		// 1. ��Ʈ��庸�� ���� ��
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
		// 2. ��Ʈ��庸�� Ŭ ��
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
	    // 3. ������ ����
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

	// �����Ͱ� ���� ��� 
	if (nullptr == iter.m_pBinaryNode || nullptr == iter.m_pMyBST || 0 == this->m_size)
	{
		assert(nullptr);
	}

	// ã�� ��尡 ��Ʈ��� �� ���
	if (eraseNode->isRoot())
	{
		// ������ ��忡 ���ʿ� �ڽ��� ���� ���
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
		// ������ ��忡 ���� �ڽĸ��� ���� ���
		else if (eraseNode->pLeft != nullptr && eraseNode->pRight == nullptr)
		{
			m_pRootNode = eraseNode->pLeft;
			delete eraseNode;
			--m_size;
		}
		// ������ ��忡 ������ �ڽĸ� ���� ���
		else if (eraseNode->pLeft == nullptr && eraseNode->pRight != nullptr)
		{
			m_pRootNode = eraseNode->pRight;
			delete eraseNode;
			--m_size;
		}
		// 0-3. �ڽ��� ���� ���
		else
		{
			delete eraseNode;
			--m_size;
		}
	}
	// ������ ��尡 �����ڽ� �� ���
	else if (eraseNode->isLeftChild())
	{
		// ������ ��忡 ���ʿ� �ڽ��� ���� ���
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
		// ������ ��忡 ���� �ڽĸ��� ���� ���
		else if (eraseNode->pLeft != nullptr && eraseNode->pRight == nullptr)
		{
			pCurrent = eraseNode->pLeft;
			eraseNode->pParent->pLeft = pCurrent;
			delete eraseNode;
			--m_size;
		}
		// ������ ��忡 ������ �ڽĸ� ���� ���
		else if (eraseNode->pLeft == nullptr && eraseNode->pRight != nullptr)
		{
			pCurrent = eraseNode->pRight;
			eraseNode->pParent->pLeft = pCurrent;
			delete eraseNode;
			--m_size;
		}
		// 0-3. �ڽ��� ���� ���
		else
		{
			delete eraseNode;
			--m_size;
		}
	}
	// ������ ��尡 ������ �ڽ� �� ���
	else if (eraseNode->isRightChild())
	{
		// ������ ��忡 ���ʿ� �ڽ��� ���� ���
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
		// ������ ��忡 ���� �ڽĸ��� ���� ���
		else if (eraseNode->pLeft != nullptr && eraseNode->pRight == nullptr)
		{
			pCurrent = eraseNode->pLeft;
			eraseNode->pParent->pRight = pCurrent;
			delete eraseNode;
			--m_size;
		}
		// ������ ��忡 ������ �ڽĸ� ���� ���
		else if (eraseNode->pLeft == nullptr && eraseNode->pRight != nullptr)
		{
			pCurrent = eraseNode->pRight;
			eraseNode->pParent->pRight = pCurrent;
			delete eraseNode;
			--m_size;
		}
		// 0-3. �ڽ��� ���� ���
		else
		{
			delete eraseNode;
			--m_size;
		}
	}

	// ������ ���� ��忡 ���� ��	
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
	// TODO : ������ȸ�� ����Ұ� 
	if (node == nullptr)
	{
		return;
	}

	printNode(node->pLeft);
	cout << node->data;
	printNode(node->pRight);
}






