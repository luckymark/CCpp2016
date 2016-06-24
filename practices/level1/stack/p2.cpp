// ConsoleApplication47.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
#include"Stack.h"
using namespace std;
int main()
{
	Stack a;
	for (int i = 0; i < 100; i++)
		a.push(i);
	a.pop();
    return 0;
}

