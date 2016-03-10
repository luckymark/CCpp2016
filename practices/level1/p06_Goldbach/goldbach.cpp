#include<stdio.h>
int main()
{
	const int prime[26]={0,2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97};
	for (int i=4;i<=100;i+=2)
	{
		int flag=0;
		for (int j=1;j<=25;j++)
		{
			if (prime[j]+2>i) break;
			for (int k=j;k<=25;k++)
			{
				if (prime[j]+prime[k]==i){
					printf("%d = %d + %d\n",i,prime[j],prime[k]);
					flag=1;
					break;
				}
				if (prime[j]+prime[k]>i) break;
			}
			if (flag) break;
		}
	}
	return 0;
}


