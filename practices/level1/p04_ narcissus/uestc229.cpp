// uestc229.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "iostream"

int main()
{
	for (int i = 100; i <= 999; i++)
	{
		int a = i / 100;
		int b = (i - a * 100) / 10;
		int c = (i - a * 100 - b * 10);
		if (a*a*a + b*b*b + c*c*c == i) printf("%d\n", i);
	}
	system("pause");
    return 0;
}

