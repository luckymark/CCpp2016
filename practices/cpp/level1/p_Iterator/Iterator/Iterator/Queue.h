#pragma once
#include "Iterator.h"
template<class T> class Iterator;
template<class T>
class Queue
{
public:

	Queue(int size = 100):size(size)
	{
		data = new T[size];
		top = -1;
	}
	Iterator<T>* creatIterator()const
	{
		return new Iterator<T>(this);
	}
	int getSize()const
	{
		return size;
	}
	void push(const T&item)
	{
		data[++top] = item;
	}
	T& get(int index)const
	{
		return data[index];
	}
	T& front()const
	{
		return data[top];
	}
	void pop()
	{
		if(top)
			--top;
	}
	~Queue()
	{
		delete[]data;
	}
private:
	int size,top;
	T* data;
};

