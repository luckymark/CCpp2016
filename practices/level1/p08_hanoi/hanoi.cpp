#include<stdio.h>
#include<stdlib.h>
#define max 4
int hanoi(char, char, char, int);
void print(char, char);
int main()
{
	char a = 'A', b = 'B', c = 'C';
	hanoi(a, b, c, max);
	system("pause");
}
int hanoi(char a, char b, char c, int n)
{
	if (n == 0)
		return 0;
	hanoi(a, c, b, n - 1);
	print(a, c);
	hanoi(b, a, c, n - 1);
}
void print(char b, char c)
{
	printf("%c->%c\n", b, c);
}