#pragma once
#include "Queue.h"
template <class T>
class Iterator
{
public:

	Iterator(const Queue<T>* aQueue):_queue(aQueue),_current(0){}
	~Iterator()
	{
		delete[]data;
	}
	void first()
	{
		_current = 0;
	}
	void next()
	{
		++_current;
	}
	bool isDone()const
	{
		return _current >= _queue->getSize();
	}
	T currentItem()const
	{
		return _queue->get(_current);
	}
private:
	const Queue<T>* _queue;
	int _current;
};

