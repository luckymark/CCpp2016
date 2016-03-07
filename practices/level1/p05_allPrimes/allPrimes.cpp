#include <cmath>
#include <cstdio>
using namespace std;
bool checkprime(int v)
{
	for(int i=2;i<=sqrt(v);i++)
		if(v%i==0)
			return false;
	return true;
}
void PrintPrimes()
{
	for(int i=2;i<=1000;i++)
		if(checkprime(i))
			printf("%d\n",i);
}
int main()
{
	PrintPrimes();
	return 0;
}