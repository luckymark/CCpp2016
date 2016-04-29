#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define CONSOLE_WIDTH 78 
int main()
{
	
	for(int i=0;i<=2*CONSOLE_WIDTH;i++)
	{
		for(int j=0;j<=(CONSOLE_WIDTH-abs(CONSOLE_WIDTH-i));j++)
		{
			printf(" ");
		}
		printf("A");
		system("cls");
	}
	
	return 0;
}
