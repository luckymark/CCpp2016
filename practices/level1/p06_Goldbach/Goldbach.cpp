#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <string.h>
#define MAXN 101
void findPrimes(bool tag[]);
void work(int v,bool tag[]);
void goldbach(bool tag[]);
int main()
{
	bool tag[MAXN];
	memset(tag,false,sizeof(tag));
	findPrimes(tag);
	goldbach(tag);
	return 0;
}
void findPrimes(bool tag[])
{
	for(int i=2;i<=MAXN/2;i++)
	{
		if(!tag[i])
		{
			for(int j=2*i;j<=100;j+=i)
			{
				tag[j]=true;
			}
		}
	}
}
void work(int v,bool tag[])
{
	for(int i=2;i<=v;i++)
	{
		if(!tag[i] && !tag[v-i])
		{
			printf("%d=%d+%d\n",v,i,v-i);
			return ;
		}
	}
}
void goldbach(bool tag[])
{
	for(int i=4;i<=100;i+=2)
	{
		work(i,tag);
	}
}
