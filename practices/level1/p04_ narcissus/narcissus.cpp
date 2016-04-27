#include<stdio.h>
#include<Windows.h>
int main()
{
	int a, b, c;
	for ( i = 100; i < 1000; i++)
	{
		a = (float)i / 100;
		b = (float)i / 10 - 10 * a;
		c = (float)i - 100 * a - 10 * b;
		if (i==a*a*a+b*b*b+c*c*c)
		{
			printf("%d ", i);
		}
	}
	getchar();
	return 0;
}
