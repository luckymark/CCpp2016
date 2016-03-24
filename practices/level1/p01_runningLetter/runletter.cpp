#include<stdio.h>
#include<windows.h>
#include<stdlib.h>
int main()
{
	int i,j,g,h;
	for (h = 0; h < 10000; h++) {
		for (i = 0; i <= 78; i++) {
			for (j = 0; j < i; j++)
			{
				printf(" ");
			}
			printf("L");
			for (g = i; g <= 78; g++)
			{
				printf(" ");
			}
			Sleep(30);
			system("cls");
		}
		for (i = 78; i >= 1; i--) {
			for (j = 0; j < i; j++)
			{
				printf(" ");
			}
			printf("L");
			for (g = i; g <= 78; g++)
			{
				printf(" ");
			}
			Sleep(30);
			system("cls");
		}
	}
	return 0;
}