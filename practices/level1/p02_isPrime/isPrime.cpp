#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int func(int n);
void print(int );
int main()
{
	int n, result;
	while (scanf("%d", &n)!=0)
	{
		result = func(n);
		print(result);
		
	}
	system("pause");
}
int func(int n)
{
	for (int i = 2; i < n; i++)
		if (n%i == 0)
			return 0;
	return 1;
}
void print(int r)
{
	if (r)
		printf("yes!\n");
	else
		printf("no!\n");
}