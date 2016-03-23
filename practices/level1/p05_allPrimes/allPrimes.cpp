#include <cmath>
#include <cstdio>
bool isPrime(int v);
void PrintPrimes();
int main()
{
	PrintPrimes();
	return 0;
}
bool isPrime(int v)
{
	for(int i=2;i<=sqrt(v);i++)
	{
		if(v%i==0)
		{
			return false;
		}
	}
	return true;
}
void PrintPrimes()
{
	for(int i=2;i<=1000;i++)
	{
		if(isPrime(i))
		{
			printf("%d\n",i);
		}
	}
}
