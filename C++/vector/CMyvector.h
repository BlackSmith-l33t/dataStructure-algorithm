#pragma once
#include <assert.h>
#include <math.h>

template <typename T>
class CMyVector
{
private:
	T*			 pData;
	unsigned int m_size; // 현재 사용량
	unsigned int m_capacity; //허용량
public:
	CMyVector();

	void push_back(const T& data);
	void pop_back();
	T& operator[](int index);

	unsigned int size();
	unsigned int capacity();

	T& at(int index);
};

template<typename T>
CMyVector<T>::CMyVector()
{
	pData = new T[10];
	m_size = 0;
	m_capacity = 10;
}

template<typename T>
void CMyVector<T>::push_back(const T & data)
{
	if (m_size >= m_capacity)
	{
		T* newData = new T[m_capacity * 2];
		for (int i = 0; i < m_size; ++i)
		{
			newData[i] = pData[i];
		}
		delete[] pData;
		pData = newData;
		m_capacity *= 2;
	}
	pData[m_size] = data;
	m_size++;
}

template<typename T>
void CMyVector<T>::pop_back()
{
	if (m_size == 0)
	{
		return;
	}

	m_size--;

	int capacitySize = ceil(((float)m_capacity / 8)); //

	if (m_size < capacitySize)
	{
		T* newData = new T[(int)(m_capacity / 2)];
		for (int i = 0; i < m_capacity / 2; i++)
		{
			newData[i] = pData[i];
		}
		delete[] pData;
		pData = newData;
		m_capacity /= 2;
	}
}

template<typename T>
unsigned int CMyVector<T>::size()
{
	return m_size;
}

template<typename T>
unsigned int CMyVector<T>::capacity()
{
	return m_capacity;
}

template<typename T>
T & CMyVector<T>::operator[](int index)
{
	return at(index);
}

template<typename T>
T & CMyVector<T>::at(int index)
{
	assert(!(index >= m_size));
	return pData[index];
}
