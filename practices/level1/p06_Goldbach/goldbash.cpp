#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int func(double n);
void print(double a, double b, double c);
int main()
{
	double i, j, k;
	for (i = 3; i < 100; i++)
	{
		if ((int)i % 2 == 0)
		{
			for (j = 2; j < i; j++)
			{
				if (func(j))
				{
					k = i - j;
				}
				if(func(k))
				{	
					print(i, j, k);
					k = 4;
					break;
				}
			}
		}
	}
	system("pause");
}
int func(double n)
{
	if (n == 1 || n == 2)
	{
		return 1;
	}
	for (int i = 2; i <= sqrt(n); i++)
	{
		if ((int)n%i == 0)
		{
			return 0;
		}
	}
	return 1;
}
void print(double a, double b, double c)
{
		printf("%.0lf=%.0lf+%.0lf\n", a, b, c);
}