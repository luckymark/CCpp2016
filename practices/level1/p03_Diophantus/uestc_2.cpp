// uestc_2.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include "iostream"

int main()
{
	
	for (int i = 1; i <= 100; i++)
	{
		if (i / 2.0 == i - 4 - (i / 6.0 + i / 12.0 + i / 7.0 + 5))
		{
			printf("%d", i - 4);
			break;
		}
	}
	system("pause");
    return 0;
}

