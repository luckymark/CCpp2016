#include<stdio.h>
#include<Windows.h>
int main()
{
	int n, a, b, c;
	for ( n = 100; n < 1000; n++)
	{
		a = (float)n / 100;
		b = (float)n / 10 - 10 * a;
		c = (float)n - 100 * a - 10 * b;
		//debug
		/*printf("%d %d %d\n", a, b, c);
		Sleep(30);*/
		if (n==a*a*a+b*b*b+c*c*c)
		{
			printf("%d ", n);
		}
	}
	getchar();
	return 0;
}