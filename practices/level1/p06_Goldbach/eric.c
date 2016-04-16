//by Eric
//p06_Goldbach

#include <stdio.h>

#define MAX 100
void _findPrimes(int *prime);
void _confirmPrimes(int prime[]);
int _findTwoPrimes(int sourceEven);

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
	for (int count = 4; count < 101; count += 2)
	{
		if(_findTwoPrimes(count))
		{
            printf("%d Error\n", count);
        }
	}
}
int _findTwoPrimes(int sourceEven)
{
    for (int count1 = 2; count1 < sourceEven; count1++)
	{
		if (prime[count1] == 1)
		{
			continue;
		}
		for (int count2 = 2; count2 < sourceEven; count2++)
		{
			if (prime[count2] == 1)
			{
				continue;
			}
			if (sourceEven == count1 + count2)
			{
				printf("%d = %d + %d\n", sourceEven, count1, count2);
				return 0;
			}
	}
    //Goldbach is wrong
    return 1;
}