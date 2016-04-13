#include "SafeArray.h"

SafeArray::SafeArray(const SafeArray &source)
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
bool SafeArray::isSafe(int index) const
{
	return (index < capacity) && (index >= LEAST_INDEX);
}