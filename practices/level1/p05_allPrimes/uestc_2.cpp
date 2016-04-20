// uestc_2.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "iostream"
#include "ctime"
#include "windows.h"
using namespace std;

int n;

int two(int r, int v,int n)   //快速幂
{
	if (v == 0) return 0;
	if (v == 1) return r;
	if ((v & 1) == 1)
	{
		int num = two(r, v >> 2,n);
		return (num*num*r) % n;
	}
	if ((v & 1) == 0)
	{
		int num = two(r, v >> 2,n);
		return (num*num) % n;
	}
}
int main()
{
	SYSTEMTIME StartTime,EndTime;
	GetLocalTime(&StartTime);
	int t1 = time(0);
	srand(t1);
	for (n = 3; n <= 1000; n++)
	{
		
		bool flag = false;
		for (int i = 1; i <= 3; i++)
		{
			int r;
			do {
				r = rand() % n;
			} while (r < 2);
			//printf("rand:%d\n", r);
			if (two(r, n - 1,n) != 1) //费马小定理
			{
				flag = true;
				break;
			}
			if (flag) break;
			if (flag==false && i == 3) printf("%d\n", n);

		}
	}
	GetLocalTime(&EndTime);
	printf("milliseconds:%d", StartTIme.wMilliseconds - EndTIme.wMilliseconds);
	system("pause");
	return 0;
}


