// ConsoleApplication46.cpp : 定义控制台应用程序的入口点。
#include "stdafx.h"
#include<stdio.h>
#include<Windows.h>
#include<stdlib.h>
#define X 8//控制迷宫大小
#define Y 8
struct now//当前坐标
{
	int i;
	int j;
};
int maze[X][Y];
int savefinal[X][Y];//存储终点坐标；
void makemaze(void);//显示迷宫函数
void detectfinal(void);//记录初始终点
int detectwin(void);//判断是否胜利
void setfinal(void);//将非箱子和人设定为终点
struct now detectplayer(void);//检测玩家初始位置
int main()
{
	int choosedif;
	FILE *fin;
	fin = fopen("in.txt", "r");
	char ch;
	struct now a;
	int i, j;
	int step = 0;//显示总步数
	scanf("%d", &choosedif);
	if (choosedif == 2)
		for (int count = 0; count < 8; count++)
			fscanf(fin, "%*[^\n]%*c");
	for (i = 0; i < X; i++)//makemaze
		for (j = 0; j < Y; j++)
			fscanf(fin, "%d", &maze[i][j]);
	a = detectplayer();//now 
	system("cls");
	makemaze();
	detectfinal();
	printf("\nfinalstep%d\n", step);
	while (scanf("%c", &ch) != EOF)//begin
	{

		if (detectwin())
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
				if (maze[a.i - 1][a.j] == 4 && ((maze[a.i - 2][a.j] == 1) || (maze[a.i - 2][a.j] == 3)))
				{
					maze[a.i][a.j] = 1;
					maze[--a.i][a.j] = 2;
					maze[a.i - 1][a.j] = 4;
					step++;

				}
				else if (!(maze[a.i - 1][a.j] == 4 && (maze[a.i - 2][a.j] == 4 || maze[a.i - 2][a.j] == 0)))
				{
					maze[a.i][a.j] = 1;
					maze[--a.i][a.j] = 2;
					step++;
				}
				system("cls");
				setfinal();
				makemaze();
				printf("\nfinalstep%d\n", step);
			}
			break;
		}
		case 's':
		{
			if (a.i + 1 < X&&maze[a.i + 1][a.j])
			{
				if (maze[a.i + 1][a.j] == 4 && (maze[a.i + 2][a.j] == 1) || (maze[a.i + 2][a.j] == 3))
				{
					maze[a.i][a.j] = 1;
					maze[++a.i][a.j] = 2;
					maze[a.i + 1][a.j] = 4;
					step++;
				}
				else if (!(maze[a.i + 1][a.j] == 4 && ((maze[a.i + 2][a.j] == 4) || maze[a.i + 2][a.j] == 0)))
				{
					maze[a.i][a.j] = 1;
					maze[++a.i][a.j] = 2;
					step++;
				}
				system("cls");
				setfinal();
				makemaze();
				printf("\nfinalstep:%d\n", step);

			}
			break;
		}
		case 'a':
		{
			if (a.j - 1 >= 0 && maze[a.i][a.j - 1])
			{
				if (maze[a.i][a.j - 1] == 4 && (maze[a.i][a.j - 2] == 1) || (maze[a.i][a.j - 2] == 3))
				{
					maze[a.i][a.j] = 1;
					maze[a.i][--a.j] = 2;
					maze[a.i][a.j - 1] = 4;
					step++;
				}
				else if (!(maze[a.i][a.j - 1] == 4 && (maze[a.i][a.j - 2] == 4 || maze[a.i][a.j - 2] == 0)))
				{
					maze[a.i][a.j] = 1;
					maze[a.i][--a.j] = 2;
					step++;
				}
				system("cls");
				setfinal();
				makemaze();
				printf("\nfinalstep%d\n", step);
			}
			break;
		}
		case 'd':
		{
			if (a.j + 1 < Y&&maze[a.i][a.j + 1])
			{
				if (maze[a.i][a.j + 1] == 4 && ((maze[a.i][a.j + 2] == 4) || (maze[a.i][a.j + 2] == 3)))
				{
					maze[a.i][a.j] = 1;
					maze[a.i][++a.j] = 2;
					maze[a.i][a.j + 1] = 4;
					step++;
				}
				else if (!(maze[a.i][a.j + 1] == 4 && (maze[a.i][a.j + 2] == 4 || maze[a.i][a.j + 2] == 0)))
				{
					maze[a.i][a.j] = 1;
					maze[a.i][++a.j] = 2;
					step++;
				}
				system("cls");
				setfinal();
				makemaze();
				printf("\nfinalstep%d\n", step);
			}break;
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
			if (maze[i][j] == 0)//障碍
				printf("O");
			if (maze[i][j] == 1)//可以行走的区域
				printf(" ");
			if (maze[i][j] == 2)//玩家
				printf("T");
			if (maze[i][j] == 3)//终点
				printf("E");
			if (maze[i][j] == 4)//箱子
				printf("D");
			if (j == (Y - 1))
				printf("\n");
		}
	printf("-----------------------------------------------------");
}
void detectfinal(void) {
	int i, j;
	for (i = 0; i < X; i++)
		for (j = 0; j < Y; j++) {
			if (maze[i][j] == 3)
				savefinal[i][j] = 1;
			else
				savefinal[i][j] = 0;
		}
}
int detectwin(void) {
	int i, j;
	for (i = 0; i < X; i++)
		for (j = 0; j < Y; j++) {
			if (savefinal[i][j] == 1)
				if (maze[i][j] != 4)
					return 0;
		}
	return 1;
}
void setfinal(void) {
	int i, j;
	for (i = 0; i < X; i++)
		for (j = 0; j < Y; j++)
			if (savefinal[i][j] == 1)
				if ((maze[i][j] == 2) || (maze[i][j] == 1))
					maze[i][j] = 3;
}
struct now detectplayer(void) {
	int a, b;
	struct now re;
	for (a = 0; a < X; a++)
		for (b = 0; b < Y; b++) {
			if (maze[a][b] == 2)
			{
				re.i = a;
				re.j = b;
				return re;
			}
		}
}
