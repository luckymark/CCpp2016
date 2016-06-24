// Queue1.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
#include"Queue.h"
using namespace std;
int main()
{
	Queue a;
	for (int i = 0; i < 100; i++)
		a.append(i);
	for (int i = 0; i < 100; i++)
		cout << a.pop(i);
    return 0;
}

