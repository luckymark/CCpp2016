#include<iostream>
#include<cstdio>
#include<ctime>
#include<cmath>
using namespace std;
inline bool isPrime(int x)
{
	for(int i=2;i<=sqrt(x);i++)
		if(x%i==0) return 0;
	return 1;
}
int main()
{
	int a,b,c;
	clock_t t1,t2;
	t1=clock();
	printf("2\n");
	for(int i=3;i<=1000;i++)
		if(isPrime(i)) printf("%d\n",i);
	t2=clock();
	printf("time:%d",t2-t1);
	return 0;
}
