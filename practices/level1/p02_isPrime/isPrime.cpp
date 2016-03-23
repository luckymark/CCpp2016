#include <cstdio>
#include <cmath>
#include <iostream>
using namespace std;
bool isPrime(int v);
int main()
{
	
	int n;
	while(scanf("%d",&n)==1)
	{
		if(n<=1)
		{
			cout<<"Are you kidding?"<<endl;
		}
		cout<<(isPrime(n)?"Yes":"No")<<endl;
	}
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