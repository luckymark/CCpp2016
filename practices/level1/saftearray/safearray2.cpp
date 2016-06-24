// safearray2.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include"Safearray.h"
#include<iostream>
using namespace std;
int main()
{
	int n;
	Safearray a;
	for (int i = 0; i < 100; i++)
		a.input(i);
	cin >> n;
	a.output(n);
    return 0;
}

