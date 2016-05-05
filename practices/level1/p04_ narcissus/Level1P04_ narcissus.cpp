// Level1P04_ narcissus.cpp : 定义控制台应用程序的入口点。
//

#include <stdio.h>
#include <math.h>


int main()
{	
	printf("3位数的水仙花数有:\n");
	for (int i = 100; i <= 999; i++)
	{
		int a = i / 100;
		int b = (i - 100 * a) / 10;
		int c = i % 10;
		if (i == pow(a,3) + pow(b,3) + pow(c,3))
		{
			printf("%d\n", i);
		}
	}
	return 0;
}

