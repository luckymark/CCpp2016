#include<stdio.h>
int main()
{
	
	for(int n=100,a,b,c;n<1000;n++)
	{
		a=n%10;
		b=((n-a)/10)%10;
		c=n/100;
		if(n==a*a*a+b*b*b+c*c*c)
		{
			printf("%d\n",n);
		}
	}
	return 0;
}
