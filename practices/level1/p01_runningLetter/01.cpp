#include<stdio.h>
#include<stdlib.h>
#define num 78 
int main()
{
	int i,j;
	for(i=0;i<=num;i++)
	{
		for(j=0;j<=i;j++)
		{
			printf(" ");
		}
		printf("A");
		system("cls");
	}
	for(i=0;i<=num;i++)
	{
		for(j=0;j<=num-i;j++)
		{
			printf(" ");
		}
		printf("A");
		system("cls");
	}
	return 0;
}