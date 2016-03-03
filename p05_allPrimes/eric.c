//by Eric 2016-03-02
//p02_isPrime
#include <stdio.h>
#include <time.h>
#define MAX 1001
void _allPrime(int *prime)
{
	for (int count = 2; count < MAX / 2; count++)
	{
		for (int count1 = 2; count1 < MAX && count < count1; count1++)
		{
			if (count1 % count == 0)
			{
				prime[count1] = 1;
			}
		}
	}
}
void _printPrime(int prime[])
{
	for (int count = 2; count < 1001; count++)
	{
		if (prime[count] != 1)
		{
			printf("%d\n", count);
		}
	}
}
int main(void)
{
	int prime[1001] = { 0 };

	_allPrime(prime);
	_printPrime(prime);

	printf("time:%f s", (double)clock() / CLOCKS_PER_SEC);
	return 0;
}