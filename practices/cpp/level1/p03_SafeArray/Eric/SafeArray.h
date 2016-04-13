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
	SafeArray(const SafeArray &source);
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