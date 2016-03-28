#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
inline bool prime(int x)
{
	if(x==2) return 1;
	for(int i=2;i<=sqrt(x);i++)
		if(x%i==0) return 0;
	return 1;
}
int main()
{
	for(int i=4;i<=100;i+=2)
		for(int j=2;j<=i/2;j++)
	    	if(prime(j)&&prime(i-j)) 
	        {
	        	printf("%d=%d+%d\n",i,j,i-j);
	            break;
	        }
	return 0;
}
