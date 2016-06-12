#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<windows.h>
#include<stdlib.h>

int main()
{
	int j = 0,f = 0;
	while (1)
	{
		for (int i = 0; i < j; i++)
		{
			printf(" ");
		}
		printf("LF");
		Sleep(1);
		system("cls");
		if (j == 78)
			f = 1;
		if (j == 0)
			f = 0;
		if (f == 0)
			j++;
		if (f == 1)
			j--;
	}
	return 0;
}