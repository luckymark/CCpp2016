#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#define ROW 5
#define COLUMN 5
#define ENDROW 4
#define ENDCOLUMN 4
#define CONTROL 0xE0
#define UP 72
#define DOWN 80
#define LEFT 75
#define RIGHT 77
void printmaze(char maze[ROW][COLUMN]);
int main()
{
	char maze[ROW][COLUMN]={'*',' ',' ',' ',' ',
							' ','#',' ',' ',' ',
							' ',' ',' ',' ','#',
							' ','#',' ','#',' ',
							' ',' ',' ',' ','V'};
	int r=0,c=0;
	while (r!=ENDROW||c!=ENDCOLUMN)
	{
		printmaze(maze);
		int move;
		move=getch();
		switch (move)
		{
			case CONTROL:
				switch (move=getch())
				{
					case UP:
						if (!r) break;
						if (maze[r-1][c]!='#'){
							maze[r][c]=' ';
							r--;
							maze[r][c]='*';
						}
						break;
					case DOWN:
						if (r==ROW-1) break;
						if (maze[r+1][c]!='#'){
							maze[r][c]=' ';
							r++;
							maze[r][c]='*';
						}
						break;
					case LEFT:
						if (!c) break;
						if (maze[r][c-1]!='#'){
							maze[r][c]=' ';
							c--;
							maze[r][c]='*';
						}	
						break;
					case RIGHT:
						if (c==COLUMN-1) break;
						if (maze[r][c+1]!='#'){
							maze[r][c]=' ';
							c++;
							maze[r][c]='*';
						}
						break;
					default:break;
				}
		}	
		system("cls");
	}
	printmaze(maze);
	printf("\nYou Win!\n");
	return 0;
}
void printmaze(char maze[ROW][COLUMN])
{	
	for (int k=0;k<COLUMN+2;k++)
	{
		printf("#");
	}
	printf("\n");
	for (int i=0;i<ROW;i++)
	{
		printf("#");
		for (int j=0;j<COLUMN;j++)
		{
			printf("%c",maze[i][j]);
		}
		printf("#\n");
	}
	for (k=0;k<COLUMN+2;k++)
	{
		printf("#");
	}
	printf("\n");
	return;
}
