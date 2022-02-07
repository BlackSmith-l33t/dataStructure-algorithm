#pragma once
#include <assert.h>


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

		T*			operator*();
		iterator&	operator++();
		iterator	operator++(int);
		/*iterator& operator--();
		iterator	operator--(int);
		bool		operator==(const iterator& _other);
		bool		operator!=(const iterator& _other); */
	};

	iterator insert(const T& target);
	//iterator earse(iterator iter);
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

	while (nullptr == pCurrent->pLeft)
	{
		pCurrent = pCurrent->pLeft;
	}
	
	return iterator(this, pCurrent);  
	//��iterator *newIter = new iterator(this, pCurrent) 
	//			 return newIter; <--- �̷�������� �����ص� �Ǵ� ���ϱ�? �ᱹ ���� ��?
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
T* CMyBST<T>::iterator::operator*()
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
				return end();
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
typename CMyBST<T>::iterator CMyBST<T>::insert(const T& target)
{
	BinaryNode<T>* newNode = new BinaryNode<T>(target, nullptr, nullptr, nullptr);
	BinaryNode<T>* pCurrent = m_pRootNode;

	// 0. �ƹ��͵� ������� ������
	if (nullptr == m_pRootNode)
	{
		m_pRootNode = newNode;
	}

	while (true)
	{
		// 1. ��Ʈ��庸�� ���� ��
		if (newNode->data < m_pRootNode->data)
		{
			pCurrent = m_pRootNode->pLeft;
			newNode->pParent = pCurrent;
			pCurrent->pLeft = newNode;
		}
		// 2. ��Ʈ��庸�� Ŭ ��
		else if (newNode->data > m_pRootNode->data)
		{
			pCurrent = m_pRootNode->pRight;
			newNode->pParent = pCurrent;
			pCurrent->pRight = newNode;
		}
	    // 3. ������ ����
		else
		{
			delete newNode;
			break;
		}
	}

	return iterator(this, newNode);

}


template<typename T>
typename CMyBST<T>::iterator CMyBST<T>::find(const T& target)
{
	BinaryNode<T>* pCurrent = m_pRootNode;

	//1. �ϳ��� �����µ� find�� �� ��� 
	if (0 == m_size) // m_pRootNode == nullptr;
	{
		return end();
	}

	while (true)
	{
		if (target < pCurrent->data)
		{
			if (nullptr == pCurrent->pLeft)
			{
				break;
			}
			pCurrent = pCurrent->pLeft;
		}
		else if (target > pCurrent->data)
		{
			if (nullptr == pCurrent->pRight)
			{
				break;
			}
			pCurrent = pCurrent->pRight;
		}
		else // target == pCurrent->data
		{
			return iterator(this, pCurrent);
		}
	}

	return end();
}






