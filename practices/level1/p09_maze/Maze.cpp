// Maze.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>

const int cx[4] = { -1,1,0,0 };
const int cy[4] = { 0,0,-1,1 };


char map[10][10] = {  
'#','#','#','#','#','1','#','#','#','#',
'#',' ','#',' ',' ',' ',' ',' ',' ','#',
'#',' ','#',' ','#','#','#','#','#','#',
'#',' ','#',' ','#',' ',' ',' ',' ','#',
'#',' ',' ',' ','#',' ','#','#',' ','#',
'#',' ','#',' ',' ',' ','#',' ',' ','#',
'#',' ','#',' ','#',' ','#','#',' ','#',
'#',' ','#','#','#','#','#','#',' ','#',
'#',' ',' ',' ','#',' ',' ',' ',' ','#',
'#','#','#','#','#',' ','#','#','#','#' };

bool if_win(int x, int y);
bool valid(int x, int y);
int transform(char ch);
void print();

int main()
{
	int x = 0,y = 5;
	char ch;
	print();
	while (!if_win(x, y))
	{
		int direction = 4;
		
		while (direction == 4)
		{
			printf("请输入方向：");
			scanf_s("%c", &ch,1);
			direction = transform(ch);
			if (direction == 4) printf("\n错误的输入!\n");
		}
		system("cls");
		int mx = x + cx[direction];
		int my = y + cy[direction];
		if (valid(mx, my))
		{
			map[x][y] = ' ';
			map[mx][my] = '1';
			x = mx; y = my;
			
		}
		print();
	}
	system("pause");
}

bool if_win(int x, int y)
{
	if (x == 9 && y == 5)
	{
		printf("You win!!");
		return true;
	}
	return false;
}

bool valid(int x, int y)
{
	if (x == -1 && y == 5)
	{
		return false;
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

