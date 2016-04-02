#include<stdio.h>
#include<windows.h>
#include<stdlib.h>
int main()
{
	int h;
	for (int i = 0; i < 10000; i++) {
		for (int j = 0; j <= 78; j++) {
			for (int k = 0; k < i; k++)
			{
				printf(" ");
			}
			printf("L");
			for (int k = j; k <= 78; k++)
			{
				printf(" ");
			}
			Sleep(30);
			system("cls");
		}
		for (int j = 78; j >= 1; j--) {
			for (int k = 0; k < j; k++)
			{
				printf(" ");
			}
			printf("L");
			for (int k = j; k <= 78; k++)
			{
				printf(" ");
			}
			Sleep(30);
			system("cls");
		}
	}
	return 0;
}