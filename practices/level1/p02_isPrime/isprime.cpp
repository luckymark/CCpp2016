#include<stdio.h>
#include<math.h>
int main()
{
	int n,i;
	char flag;
	scanf("%d",&n);
	flag=1;
	if(2==n)
	{
		printf("yes");
	}
	else
	{
		for(i=2;i<=sqrt(n);i++)
		{
			if(0==n%i)
			{
				flag=0;
			}
		}
		if(1==flag)
		{
			printf("yes");
		}
		else
		{
			printf("no");
		}
		
	}
	return 0;
}