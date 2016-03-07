#include<stdio.h>
void prime(int input);
int main()
{
	int n;
	
	scanf("%d",&n);
	prime(n);
	return 0;
}
void prime(int input)
{
	int i;
	char flag=1;
	if(2==input)
	{
		printf("yes");
	}
	else
	{
		for(i=2;i*i<=input;i++)
		{
			if(0==input%i)
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
}
