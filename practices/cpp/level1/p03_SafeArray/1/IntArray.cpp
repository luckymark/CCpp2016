#include "IntArray.h"

IntArray::IntArray(int length)
{
	a = new int[length];
	IntArray::length = length;
	for (size_t i = 0; i < length; i++)
	{
		a[i] = 0;
	}
}

IntArray::~IntArray()
{
	delete a;
}

int IntArray::getArray(int num)
{
	if (num > length)
	{
		std::cout << "error" << std::endl;
		return 0;
	}
	std::cout << a[num - 1] << std::endl;
	return a[num - 1];
}

void IntArray::setArray(int num, int data)
{
	if (num > length)
	{
		std::cout << "error" << std::endl;
		return ;
	}
	a[num - 1] = data;
}
