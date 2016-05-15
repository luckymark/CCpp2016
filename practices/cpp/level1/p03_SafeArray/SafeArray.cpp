#include "SafeArray.h"
#include <iostream>
#include <cstdio>
void SafeArray::in(int p,int num)
{
	if(p>cap)
	{
		printf("Error!");
		return;
	}
	data[p]=num;
	return;
}
int SafeArray::out(int p)
{
	if(p>cap)
	{
		printf("Error!\n");
		exit(1);
	}
	return data[p];
}
