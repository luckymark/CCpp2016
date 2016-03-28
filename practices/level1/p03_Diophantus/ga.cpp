#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
	int i;
	for(i=1;i<=300;i++)
	{
		if((i-(i/2.0+4))==(i/6.0+i/12.0+i/7.0+5))
		{
			printf("%d",i-4);
			return 0;
	    }
	}
	return 0;
}