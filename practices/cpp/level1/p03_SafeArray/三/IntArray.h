#pragma once

#include<iostream>

template<typename T>
class IntArray
{
public:
	IntArray(T length);
	~IntArray();
	T getArray(int num);
	void setArray(int num, T data);

private:
	T *a;
	int length;

};

template<typename T>
IntArray<T>::IntArray(T length)
{
	a = new T[length];
	IntArray::length = length;
	for (size_t i = 0; i < length; i++)
	{
		a[i] = (T)0;
	}
}

template<typename T>
IntArray<T>::~IntArray()
{
	delete a;
}

template<typename T>
T IntArray<T>::getArray(int num)
{
	if (num > length)
	{
		std::cout << "error" << std::endl;
		return (T)0;
	}
	std::cout << a[num - 1] << std::endl;
	return a[num - 1];
}

template<typename T>
void IntArray<T>::setArray(int num, T data)
{
	if (num > length)
	{
		std::cout << "error" << std::endl;
		return;
	}
	a[num - 1] = data;
}
