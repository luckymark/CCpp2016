// Level1P04_ narcissus.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include <stdio.h>
#include <math.h>


int main()
{	
	printf("3λ����ˮ�ɻ�����:\n");
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

