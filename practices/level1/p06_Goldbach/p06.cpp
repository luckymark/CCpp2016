#include<stdio.h>
#include<stdlib.h>
//在100范围内验证大于2的偶数都可写成两个素数之和 
int main()
{
	int n,m,i,j,k,l,a[100]={0};
	char flag =0;
	i=2;
	j=1;
	for(n=4;n<=100;n+=2)
	{
		m=n;
		do
		{
			while(m%i==0&&m>=i)
			{
				a[j]=i;
				
				m/=i;
				j++;
			}
			i++;
		}while(m>i);//分解质因数 
		for(k=1;k<=n;k++)
		{
			for(l=1;l<=k;l++)
			{
				if(a[k]+a[l]==n)
				{
					flag=1;
				}
			}
			
		}
		if(flag==0)
			{
				printf("no");
				exit(0);
			}
	}
	if(flag==1)
	{
		printf("yes");
	}
	return 0;
	
		
	
} 