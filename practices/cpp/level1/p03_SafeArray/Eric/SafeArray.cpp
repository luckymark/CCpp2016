#include "SafeArray.h"
bool SafeArray::isSafe(int index)
{
    return index > arrayLessIndex && index < arrayMaxIndex;
}