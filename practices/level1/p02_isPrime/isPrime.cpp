#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int Prime(int n);
void print(int r);
int main()
{
	int n, result;
	while (scanf("%d", &n)!=0)
	{
		result = Prime(n);
		print(result);
		
	}
	system("pause");
}
int Prime(int n)
{
	for (int i = 2; i < n; i++)
		{
			if (n%i == 0)
				return 0;
			
		}
	return 1;
}
void print(int r)
{
	if (r)
		printf("yes!\n");
	else
		printf("no!\n");
}
