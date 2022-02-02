#pragma once
#include <assert.h>

#define DEFAULT_SIZE 10

template <typename T>	
class CMyVector
{
private:
	T*	pDataArray;
	int m_size;
	int m_capacity;
public:
	CMyVector();
	~CMyVector();

private:
	void re_allocate(unsigned int resize);  // vector의 저장소 크기를 재조정

public:
	void push_back(const T& data);
	void pop_back();
	
	int size();
	int capacity();

	void clear();
	bool empty();

	T& operator[](int index);
	T& at(int index);

	class iterator
	{
		friend CMyVector;
	private:
		CMyVector* pVector;
		T* pData;
		int m_index;
	public:
		T& operator*(); //*iter;
		iterator& operator++(); //++iter;
		iterator operator++(int); //iter++;
		iterator& operator--(); //--iter;
		iterator operator--(int); //iter--;
		bool operator==(const iterator& _other); //iter == otherIter;
		bool operator!=(const iterator& _other); //iter != otherIter;
	};

	iterator begin();
	iterator end();

	void insert(const iterator& iter, const T& value);
	void erase(const iterator& iter);
};

template<typename T>
CMyVector<T>::CMyVector()
{
	pDataArray = new T[DEFAULT_SIZE];
	m_size = 0;
	m_capacity = DEFAULT_SIZE;
}

template<typename T>
CMyVector<T>::~CMyVector()
{
	m_size = 0;
	m_capacity = 0;
}

template<typename T>
void CMyVector<T>::re_allocate(unsigned int resize)
{
	if (m_size > resize)
	{
		resize = m_size;
	}

	T* newDataArray = new T[resize];
	for (int i = 0; i < m_size; ++i)
	{
		newDataArray[i] = pDataArray[i];
	}

	delete[] pDataArray;
	pDataArray = newDataArray;
	m_capacity = resize;
}

template<typename T>
int CMyVector<T>::size()
{
	return m_size;
}

template<typename T>
int CMyVector<T>::capacity()
{
	return m_capacity;
}

template<typename T>
void CMyVector<T>::push_back(const T& data)
{
	if (m_size > m_capacity / 2)
	{
		re_allocate(m_capacity * 2);
	}

	pDataArray[m_size] = data;
	m_size++;
}

template<typename T>
void CMyVector<T>::pop_back()
{
	assert(m_size != 0);
	
	if (m_size < m_capacity / 4)
	{
		re_allocate(m_capacity / 2);
	}
	m_size--;
}

template<typename T>
T& CMyVector<T>::operator[](int index)
{
	return at(index);
}

template<typename T>
T& CMyVector<T>::at(int index)
{
	assert(!(m_size == index));

	return pDataArray[index];
}

template<typename T>
void CMyVector<T>::clear()
{
	delete[] pDataArray;
	pDataArray = new T[DEFAULT_SIZE];
	m_size = 0;
	m_capacity = 0;
}

template<typename T>
bool CMyVector<T>::empty()
{	
	return m_size == 0;
}

template <typename T>
typename CMyVector<T>::iterator CMyVector<T>::begin()
{
	iterator newIter;
	newIter.pVector = this;
	newIter.pData = this->pDataArray;
	newIter.m_index = 0;
	return newIter;
}

template <typename T>
typename CMyVector<T>::iterator CMyVector<T>::end()
{
	iterator newIter;
	newIter.pVector = this;
	newIter.pData = this->pDataArray;
	newIter.m_index = -1;

	return newIter;
}


template<typename T>
T& CMyVector<T>::iterator::operator*()
{
	// 1. iterator가 Vector의 데이터 변경으로 잘못된 곳을 가르키고 있는 경우
	// 2. iterator가 가르키고 있는 곳에 데이터 아에 없는 경우
	// 3. iterator가 end() iterator일 때
	if (pVector->pDataArray != pData || pVector->m_size <= m_index || m_index == -1)
	{
		assert(nullptr);
	}

	return pData[m_index];
}
template <typename T> 
typename CMyVector<T>::iterator& CMyVector<T>::iterator::operator++() //++iter;
{
	// 1. iterator가 Vector의 데이터 변경으로 잘못된 곳을 가르키고 있는 경우
	// 2. iterator가 이미 end() iterator였을 떄 assert();
	// 3. iterator가 마지막 데이터를 가리키고 있을 경우 : iterator end()

	if (pVector->pDataArray != pData || -1 == m_index)
	{
		assert(nullptr);
	}

	if (m_index == pVector->m_size - 1)
	{
		m_index = -1;
	}
	else
	{
		m_index++;
	}

	return *this;
}

template<typename T> 
typename CMyVector<T>::iterator CMyVector<T>::iterator::operator++(int) //iter++;
{

	iterator dummy = *this;

	if (pVector->pDataArray != pData || -1 == m_index)
	{
		assert(nullptr);
	}

	if (m_index == pVector->size() - 1)
	{
		m_index = -1;
	}
	else
	{
		++(*this);
	}
	return dummy;
}
