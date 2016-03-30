#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
bool isPrime(int x);
int main()
{
	int a;
	scanf("%d",&a);
	if(isPrime(a)) printf("Yes");
		else printf("no");
	return 0;
}
bool isPrime(int x)
{
	for(int i=2;i<=sqrt(x);i++)
		if(x%i==0) return 0;
	return 1;
}
