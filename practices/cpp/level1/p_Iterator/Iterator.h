#pragma once

#include"queue.h"

class Iterator
{
public:
	Iterator();
	~Iterator();
	template<typename T>
	void traverse(T &queue);
private:

};

template<typename T>
inline void Iterator::traverse(T & queue)
{
	for (int i = queue.head-1; i >= queue.tail; i--)
	{
		std::cout << queue.data[i % 100] << std::endl;
	}
}
