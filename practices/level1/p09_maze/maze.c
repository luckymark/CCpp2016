#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

void showmaze();
void move(char direction);
int x=0,y=1;

 char maze[SIZE][SIZE+1]={
        "##########",
        "I ########",
        "#  #######",
        "## #######",
        "##     ###",
        "#####  ###",
        "###### ###",
        "###### ###",
        "###### ###",
        "######X###"
       };
int main()
{

    while(1){
        char direction;
        showmaze();
        scanf("%c",&direction);
        system("cls");
        move(direction);
    }
    return 0;
}

void showmaze()
{
        for(int i=0;i<=SIZE;i++)
       {
           printf("%s\n",maze[i]);
       }
}
void move(char direction)
{   maze[y][x]=' ';
    switch(direction)
    {
    case 'a':
        if(maze[y][x-1]!='#')
        {
            x--;
        }
        break;
    case 'w':
        if(maze[y-1][x]!='#')
        {
            y--;
        }
        break;
    case 's':
        if(maze[y+1][x]!='#')
        {
            y++;
        }
        break;
    case 'd':
        if(maze[y][x+1]!='#')
        {
            x++;
        }
        break;
        default:return;

    }

     if(maze[y][x]=='X')
     {
         printf("Congratulations!");
         exit(1);
     }
     else
     {
          maze[y][x]='I';
     }

}
