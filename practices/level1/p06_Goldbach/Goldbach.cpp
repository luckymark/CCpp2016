#include <cstdio>
#include <cmath>
using namespace std;
const int maxn=101;
bool tag[maxn];
void FindPrimes()
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
void work(int v)
{
	for(int i=2;i<=v;i++)
		if(!tag[i] && !tag[v-i])
		{
			printf("%d=%d+%d\n",v,i,v-i);
			return ;
		}
}
void Goldbach()
{
	for(int i=4;i<=100;i+=2)
		work(i);
}
int main()
{
	FindPrimes();
	Goldbach();
	return 0;
}