#include<stdio.h>
#include<stdlib.h>
int hanoi(char from, char by, char to, int n);
void print(char from, char to);
int main()
{
	char from = 'A', by = 'B', to = 'C';
	hanoi(from, by, to, 64);
	system("pause");
}
int hanoi(char from, char by, char to, int n)
{
	if (n == 0)
	{
		return 0;
	}
	hanoi(from, to, by, n - 1);
	print(from, to);
	hanoi(by, from, to, n - 1);
}
void print(char b, char c)
{
	printf("%c->%c\n", b, c);
}