#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int isPrime(double n);
void print(double r, int d);
int main()
{
	int result;
	for (double i = 2; i < 1000; i++)
	{
		print(isPrime(i), i);
	}
	system("pause");
}
int isPrime(double n)
{
	for (int i = 2; i <= sqrt(n); i++)
	{
		if ((int)n%i == 0)
		{
			return 0;
		}
	}
	return 1;
}
void print(double r, int d)
{
	if (r)
	{
		printf("%d\n", d);
	}
}