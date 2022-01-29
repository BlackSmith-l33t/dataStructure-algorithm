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
	assert(!(m_size == 0));

	return pDataArray[index];
}

template<typename T>
void CMyVector<T>::clear()
{
	delete[] pDataArray;
	m_size = 0;
	m_capacity = 0;
}

template<typename T>
bool CMyVector<T>::empty()
{	
	return m_size == 0 && pDataArray == nullptr;
}


