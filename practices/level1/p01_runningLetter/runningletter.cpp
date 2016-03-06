#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define SIDE 100
int main()
{
	int i;
	for (i=2*SIDE;i>=0;i--)
	{
		int space,j;
		if (i>=SIDE){
			space=fabs(2*SIDE-i);
		}
		else{
			space=fabs(i);
		}
		for (j=0;j<=space;j++)
		{
			printf(" ");
		}
		printf("A");
		system("cls");
	}
	return 0;
}