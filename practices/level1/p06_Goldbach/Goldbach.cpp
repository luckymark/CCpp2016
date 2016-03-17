#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <string.h>
#define maxn 101
void FindPrimes(bool tag[]);
void work(int v,bool tag[]);
void Goldbach(bool tag[]);
int main()
{
    bool tag[maxn];
    memset(tag,false,sizeof(tag));
	FindPrimes(tag);
	Goldbach(tag);
	return 0;
}
void FindPrimes(bool tag[])
{
	for(int i=2;i<=maxn/2;i++)
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
		if(!tag[i] && !tag[v-i])
		{
			printf("%d=%d+%d\n",v,i,v-i);
			return ;
		}
}
void Goldbach(bool tag[])
{
	for(int i=4;i<=100;i+=2)
		work(i,tag);
}
