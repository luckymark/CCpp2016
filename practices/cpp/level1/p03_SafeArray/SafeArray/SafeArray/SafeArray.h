#pragma once
#include <cstdio>
template<class T>
class SafeArray
{
public:
	SafeArray(int capbility)
	{
		this->capbility = capbility;
		data = new int[capbility];
	}
	~SafeArray()
	{
		delete []data;
	}
	void insert(int pos, T value)
	{
		if (pos<capbility)
		{
			data[pos] = value;
		}
		else
		{
			printf("The size is too large!\n");
		}
	}
	T operator [](int pos)
	{
		if (pos<capbility)
		{
			return data[pos];
		}
		else
		{
			printf("The size is too large!\n");
		}
	}
	T get(int pos)
	{
		if (pos<capbility)
		{
			return data[pos];
		}
		else
		{
			printf("The size is too large!\n");
			return -1;
		}
	}
private:
	int *data;
	int capbility;
};

