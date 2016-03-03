//by Eric
//p06_Goldbach

#include <stdio.h>
//#include <string.h>
//#include <stblib.h>

#define MAX 100
void _findPrimes(int *prime);
void _confirmPrimes(int prime[]);
int main(void)
{
	int prime[MAX] = { 0 };
	_findPrimes(prime);
	_confirmPrimes(prime);

	//system("pause");
	return 0;
}

void _findPrimes(int *prime)
{
	for (int count = 2; count < 500; count++)
	{
		for (int count1 = count + 1; count1 < 100; count1++)
		{
			if (count1 % count == 0)
			{
				prime[count1] = 1;
			}
		}
	}
}
void _confirmPrimes(int prime[])
{
	for (int count1 = 4; count1 < 101; count1 += 2)
	{
		for (int count2 = 2; count2 < count1; count2++)
		{
			if (prime[count2] == 1)
			{
				continue;
			}
			for (int count3 = 2; count3 < count1; count3++)
			{
				if (prime[count3] == 1)
				{
					continue;
				}
				if (count1 == count2 + count3)
				{
					printf("%d = %d + %d\n", count1, count2, count3);
					goto _break;	//请问老师，如果要跳出多重循环能不能不用goto?
				}
			}
		}
		printf("%d Error\n", count1);
	_break:
		;
	}
}