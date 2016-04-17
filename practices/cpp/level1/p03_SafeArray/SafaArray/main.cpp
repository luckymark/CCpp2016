#include <stdio.h>
#include "SafeArray.h"
#define SIZE 100
int main()
{
    SafeArray safeArray(SIZE);
    safeArray.insert(5,100);
    int x=safeArray.get(5);
    x=safeArray.get(100);
    return 0;
}
