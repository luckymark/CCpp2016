//Eric 2016-03-06 00:44:35
//p09_maze
//windows

#include <stdio.h>
#include <conio.h>
//use the _getch() function
#include <stdlib.h>
//use system() function

int ORDER[2][1000] = { 0 };	//�������� ת������
int maze[10][10][2] = { 0 };	//maze [0]0-�հף�1-BLOCK��2-�ˣ� [1] 3-����
void initializationMaze(void);
int checkOrder(char order);	//�ж����� ���ط���1
void showMaze(void);	//չʾ�Թ�

int locationRow, locationColumn;	//human-position
int main(void)
{
	char order;
	ORDER[0]['w'] = -1;
	ORDER[0]['s'] = 1;
	ORDER[1]['a'] = -1;
	ORDER[1]['d'] = 1;
	initializationMaze();
	showMaze();
	while (order = _getch())
	{
		if (checkOrder(order))
		{
			break;
		}
	}
	printf("Done!\n");

	system("pause");
	return 0;
}
void initializationMaze(void)
{
	//�����߿�
	for (int count1 = 0; count1 < 10; count1++)
	{
		for (int count2 = 0; (count1 == 0 || count2 == 0) && count2 < 10; count2++)
		{
			maze[count1][count2][0] = 1;
		}
	}
	//����base exit
	maze[1][0][0] = 2;
	locationRow = 1;
	locationColumn = 0;
	maze[1][9][1] = 3;
	maze[1][9][0] = 3;
	//blocks
	for (int count1 = 2; count1 < 10; count1++)
	{
		for (int count2 = 0; count2 < 10; count2++)
		{
			maze[count1][count2][0] = 1;
		}
	}
	//w or s test
	maze[2][2][0] = 0;
}
int checkOrder(char order)
{
	if ((maze[locationRow + ORDER[0][order]][locationColumn + ORDER[1][order]][0] != 1) && locationRow + ORDER[0][order] != -1)
	{
		maze[locationRow][locationColumn][0] = 0;
		locationRow += ORDER[0][order];
		locationColumn += ORDER[1][order];
	}
	maze[locationRow][locationColumn][0] = 2;
	showMaze();
	if (maze[locationRow][locationColumn][1] == 3)
		return 1;
	return 0;
}
void showMaze(void)
{
	system("cls");
	for (int count1 = 0; count1 < 10; count1++)
	{
		for (int count2 = 0; count2 < 10; count2++)
		{
			switch(maze[count1][count2])
			{
				case 1:
					printf("*");
					break;
				case 2:
					printf("O");
					break;
				default:
					printf(" ");
			}
		}
		printf("\n");
	}
}