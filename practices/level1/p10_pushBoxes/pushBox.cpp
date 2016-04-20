// Maze.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>

const int cx[4] = { -1,1,0,0 };
const int cy[4] = { 0,0,-1,1 };
int tot;


char map[10][10] = {
	'#','#','#','#','#','Y','#','#','#','#',
	'#',' ','#','1',' ',' ',' ',' ',' ','#',
	'#',' ',' ',' ','#','#','#','#','#','#',
	'#',' ','#',' ','#',' ',' ',' ',' ','#',
	'#',' ','O',' ','O',' ','#','#',' ','#',
	'#',' ','#',' ',' ',' ','#',' ',' ','#',
	'#',' ','#',' ','#',' ','#','#',' ','#',
	'#',' ','#','#','#','#','#','#',' ','#',
	'#','1',' ',' ','#',' ',' ',' ',' ','#',
	'#','#','#','#','#',' ','#','#','#','#' };

bool if_win();
bool valid(int x, int y,int cx,int cy);
int transform(char ch);
void print();

int main()
{
	int x = 0, y = 5;
	bool flag = false;
	char ch;
	print();
	while (!if_win())
	{
		int direction = 4;

		while (direction == 4)
		{
			printf("请输入方向：");
			scanf_s("%c", &ch, 1);
			direction = transform(ch);
			if (direction == 4) printf("\n错误的输入!\n");
		}
		system("cls");
		int mx = x + cx[direction];
		int my = y + cy[direction];
		if (valid(mx, my, mx + cx[direction], my + cy[direction]))
		{
			if (flag)   //走过箱子终点，需要还原原来的标志
			{
				map[x][y] = '1';
				flag = false;
			}
			else map[x][y] = ' ';
			if (map[mx][my] == '1') flag = true;
			map[mx][my] = 'Y';
			x = mx; y = my;

		}
		print();
	}
	system("pause");
}

bool if_win()
{
	if (tot==2)
	{
		printf("You win!!");
		return true;
	}
	return false;
}

bool valid(int x, int y,int cx,int cy)
{
	if (x == -1 && y == 5)
	{
		return false;
	}
	if (map[x][y] == 'O')
	{
		if (map[cx][cy] == 'O' || map[cx][cy] == '#')
			return false;
		if (map[cx][cy] == '1')  //箱子归位
		{
			map[cx][cy] = 'T';
			tot++;
			return true;
		}
		if (map[cx][cy] == ' ')  //推箱子
		{
			map[cx][cy] = 'O';
			return true;
		}
	}

	if (map[x][y] == '#')
	{
		printf("你撞墙了！！\n");
		return false;
	}
	return true;

}

int transform(char ch)
{
	switch (ch)
	{
	case 'w':
		return 0;
	case 's':
		return 1;
	case 'a':
		return 2;
	case 'd':
		return 3;

	default:
		break;
	}
	return 4;
}

void print()
{
	for (int i = 0; i <= 9; i++)
	{
		printf("\n");
		for (int j = 0; j <= 9; j++)
		{
			printf("%c", map[i][j]);
		}
	}
	printf("\n");
}

