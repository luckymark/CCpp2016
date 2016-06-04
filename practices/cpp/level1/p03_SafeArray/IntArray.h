#pragma once

#include<iostream>

class IntArray
{
public:
	IntArray(int length);
	~IntArray();
	int getArray(int num);
	void setArray(int num, int data);

private:
	int *a;
	int length;

};
