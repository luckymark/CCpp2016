#include"safeArray.h"
#include<iostream>
using namespace std;
SafeArray::SafeArray(int n)
{
	data = new int[n];
}
void SafeArray::get(int n)
{
	cout << data[n] << endl;
}
SafeArray::~SafeArray()
{
	delete[]data;
}
void SafeArray::set(int p,int n)
{
	data[n] = p;
}
bool SafeArray::judge(int s,int max)
{
	if (s > max)
	{
		cout << "error" << endl;
		return false;
	}
	else
	{
		return true;
	}
}