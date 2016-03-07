#include <cstdio>
#include <cmath>
#include <iostream>
using namespace std;
bool CheckPrime(int v)
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
int main()
{
	int n;
	while(scanf("%d",&n)==1)
	{
		if(n<=1)
        {
			cout<<"Are you kidding?"<<endl;
        }
		cout<<(CheckPrime(n)?"Yes":"No")<<endl;
	}
	return 0;
}
