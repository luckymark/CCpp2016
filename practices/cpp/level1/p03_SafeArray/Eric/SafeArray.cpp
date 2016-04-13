#include "SafeArray.h"

// SafeArray::SafeArray(const SafeArray &source)
bool SafeArray::isSafe(int index) const
{
	return (index < capacity) && (index >= LEAST_INDEX);
}