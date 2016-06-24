//example
/*
2 1 0 0 0
0 1 0 0 0
1 1 1 1 0
1 0 1 0 0
1 0 1 1 3
*/
#include "stdafx.h"
#include<stdio.h>
#include<stdlib.h>
#include<Windows.h>
#define X 5//控制迷宫大小
#define Y 5
int maze[X][Y];
struct now//当前坐标
{
	int i;
	int j;
};
void makemaze(void);//显示迷宫函数
int main()
{
	FILE *fin;
	fin = fopen("in.txt", "r");
	char ch;
	struct now a;
	a = { 0,0 };//now 
	int i, j, yes;
	yes = 0;
	for (i = 0; i < X; i++)//makemaze
		for (j = 0; j < Y; j++)
			fscanf(fin,"%d", &maze[i][j]);
	fclose(fin);
	system("cls");
	makemaze();
	while (scanf("%c", &ch) != EOF)//begin
	{
		if (yes)
		{
			printf("success!!!\n");
			break;
		}
		switch (ch)
		{
		case 'w':
		{

			if (a.i - 1 >= 0 && maze[a.i - 1][a.j])
			{
				if (maze[a.i - 1][a.j] == 3)
				{
					yes = 1;
					break;
				}
				maze[a.i][a.j] = 1;
				maze[--a.i][j] = 2;
				system("cls");
				makemaze();
			}
			break;
		}
		case 's':
		{
			if (a.i + 1 < X&&maze[a.i + 1][a.j])
			{
				if (maze[a.i + 1][a.j] == 3)
				{
					yes = 1;
					break;
				}
				maze[a.i][a.j] = 1;
				maze[++a.i][a.j] = 2;
				system("cls");
				makemaze();
			}
			break;
		}
		case 'a':
		{
			if (a.j - 1 >= 0 && maze[a.i][a.j - 1])
			{
				if (maze[a.i][a.j + 1] == 3)
				{
					yes = 1;
					break;
				}
				maze[a.i][a.j] = 1;
				maze[a.i][--a.j] = 2;
				printf("%d", maze[a.i][a.j - 1]);
				system("cls");
				makemaze();
			}
			break;
		}
		case 'd':
		{
			if (a.j + 1 < Y&&maze[a.i][a.j + 1])
			{
				if (maze[a.i][a.j + 1] == 3)
				{
					yes = 1;
					break;
				}
				maze[a.i][a.j] = 1;
				maze[a.i][++a.j] = 2;
				system("cls");
				makemaze();
				break;
			}
		}


		}


	}
	return 0;
}
void makemaze(void)
{
	int i, j;
	printf("-----------------------------------------------------\n");
	for (i = 0; i < X; i++)
		for (j = 0; j < Y; j++)
		{
			if (maze[i][j] == 0)
				printf("O");
			if (maze[i][j] == 1)
				printf(" ");
			if (maze[i][j] == 2)
				printf("B");
			if (maze[i][j] == 3)
				printf("E");
			if (j == (Y - 1))
				printf("\n");
		}
	printf("-----------------------------------------------------");
}
