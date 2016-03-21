#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#define ROW 5
#define COLUMN 5
void printmaze(char maze[ROW][COLUMN]);
int main()
{
	char maze[ROW][COLUMN]={'*',' ',' ',' ',' ',
							' ','#',' ',' ',' ',
							' ',' ',' ',' ','#',
							' ','#',' ','#',' ',
							' ',' ',' ',' ','V'};
	int r=0,c=0;
	while (r!=ROW-1||c!=COLUMN-1)
	{
		printmaze(maze);
		int move;
		move=getch();
		switch (move)
		{
			case 0xE0:
				switch (move=getch())
				{
					case 72:
						if (!r) break;
						if (maze[r-1][c]!='#'){
							maze[r][c]=' ';
							r--;
							maze[r][c]='*';
						}
						break;
					case 80:
						if (r==ROW-1) break;
						if (maze[r+1][c]!='#'){
							maze[r][c]=' ';
							r++;
							maze[r][c]='*';
						}
						break;
					case 75:
						if (!c) break;
						if (maze[r][c-1]!='#'){
							maze[r][c]=' ';
							c--;
							maze[r][c]='*';
						}	
						break;
					case 77:
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
