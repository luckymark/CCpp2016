// uestc229.cpp : �������̨Ӧ�ó������ڵ㡣
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

