#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int va_goldbash(double n);
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
				if (va_goldbash(j))
				{
					k = i - j;
				}
				if(va_goldbash(k))
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
int va_goldbash(double n)
{
	if (n == 1 || n == 2)
	{
		return 1;
	}
	for (int i = 2; i <= sqrt(n); i++)
		if ((int)n%i == 0)
		{
			return 0;
		}
	return 1;
}
void print(double a, double b, double c)
{
	printf("%.0lf=%.0lf+%.0lf\n", a, b, c);
}
