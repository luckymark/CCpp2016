#include<stdio.h>
#include<stdlib.h>
//��100��Χ����֤����2��ż������д����������֮�� 
int main()
{
	int n,m,i,j,k,l,a[100]={0},b[100]={0};
	
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
		}while(m>i);//�ֽ������� 
		for(k=1;k<=n;k++)
		{
			for(l=1;l<=k;l++)
			{
				if(a[k]+a[l]==n)
				{
					b[n]=1;
				}
			}
			
		}
		if(b[n]==0)
			{
				printf("no");
				exit(0);
			}
	}
	
	
		printf("yes");
	
	return 0;
	
		
	
} 