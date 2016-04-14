#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<windows.h>
#include<stdlib.h>

int main()
{
	int j = 0;
	bool h = 0;
	while(1)
	{
		for (int k = 0; k < j; k++)
		{
			printf(" ");
		}
		printf("L");
		Sleep(1);
		system("cls");
		if (j == 78)
			h = 1;
		if (j == 0)
			h = 0;
		if (h == 0)
			j++;
		if (h == 1)
			j--;
	}
	return 0;
}