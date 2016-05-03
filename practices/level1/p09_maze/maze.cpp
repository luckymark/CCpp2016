#include<stdio.h>
#include<stdlib.h>
#define ROW 5
#define COLUMN 9
int x=0,y=1,finish;
char maze[ROW][COLUMN]=
{
	"XXXXXXXX",
 	"I XXX   ",
  	"X  XX XX",
  	"XX X  XX",
  	"XX   XXX"
};
void showmaze();
void move(char direction);
void clean();
int finishmaze();
int hitwall(char nextstep);
int main()
{
	showmaze();
	char direction;
	while(0==finish)
	{
	        scanf("%c",&direction);
		move(direction);
		
	}
	return 0;
}
void showmaze()
{
	for(int i=0;i<ROW;i++)
	{
		for(int j=0;j<COLUMN;j++)
		{
			printf("%c",maze[i][j]);
			if(COLUMN-1==j)
			{
				printf("\n");
			}
		}
	}
}
void move(char direction)
{
    maze[y][x]=' ';
    switch(direction)
    {
        case('w'):
            y--;
            break;
        case('a'):
            x--;
            break;
        case('s'):
            y++;
            break;
        case('d'):
            x++;
            break;
        default:
	    return;

    }
    if(hitwall(maze[y][x])==1)
    {
		maze[y][x]='I';
    };
    clean();
    if(finishmaze()==1)
    {
    	finish=1;
    }
} 
int hitwall(char nextstep)
{
	switch(nextstep)
	{
		case'X':
		{
			printf("game over");
			exit(0);
		}
		case' ':
		{
			return 1;
		}
	}
}
int finishmaze()
{
	if(x==COLUMN-1&&y==1)
	{
		printf("finished");
		return 1;
	}
	else
	{
		return 0;
	}
}
void clean()
{
	system("cls");
	showmaze();
}
