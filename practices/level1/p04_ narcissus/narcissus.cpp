#include<stdio.h>
#include<stdlib.h>
int narcissus(int a);
void print(int s, int d);
int main()
{
	int n, a;
	for (n = 100; n < 1000; n++)
	{
		a = narcissus(n);
		print(a, n);
	}
	system("pause");
}
int narcissus(int a)
{
	int b, c, d;
	b = a / 100;
	c = (a % 100) / 10;
	d = (a % 100) % 10;
	if (a == b*b*b + c*c*c + d*d*d)
		return 1;
	return 0;
}
void print(int s, int d)
{
	if (s)
	{
		printf("%d", d);
	}
}