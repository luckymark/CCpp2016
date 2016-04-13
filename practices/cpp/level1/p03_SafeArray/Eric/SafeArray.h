#ifndef SAFE_ARRAY_H
#define SAFE_ARRAY_H

#include <iostream>

#define LEAST_INDEX 0
class SafeArray
{
private:
	int *array = nullptr;
	int capacity = 0;
	int wrongIndexReturn;
	bool isSafe(int index) const;
public:
	SafeArray(int cap) : capacity(cap), array(new int[cap]){}
	SafeArray(const SafeArray &source)
	{
		auto temp = new int[source.capacity];
		for(int count = 0; count != source.capacity; count++)
		{
			*(temp + count) = *(source.array + count);
		}
		if(array != nullptr)
		{
			delete array;
		}
		array = temp;
		capacity = source.capacity;
	}

	int &operator[](int index)
	{
		if(isSafe(index))
		{
			return *(array + index);
		}
		else
		{
			std::cerr << "wrong index" << std::endl;
			return wrongIndexReturn;
		}
	}
	const int &operator[](int index) const
	{
		if(isSafe(index))
		{
			return array[index];
		}
		else
		{
			std::cerr << "wrong index" << std::endl;
			return wrongIndexReturn;
		}
	}
};
#endif