#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "aboutSystem.h"
#include "readLevels.h"
/*
我有罪
我把界面尺寸做成了全局变量
我解析配置文件的部分显得这么dirty
我有罪
我对不起俸爷的悉心教导
我对不起同班大神们的熏陶
我有罪
2016.04.17
俸爷我错了，推箱子暂时实在不想碰，能不能暂时无视他

*/
void initMap(char**);
int main()
{
    FILE* janus = findFile(3);
    char**map=getMap(janus);
    initMap(map);
    putchar('a');
    PAUSE();
}
void initMap(char** map)
{
	system("cls");
    for (int x = 0; x < width; x++)
    {
        for (int y = 0; y < height; y++)
        {
            gotoxy(x,y);
            switch (map[x][y])
            {
            case space:putchar(' '); break;
            case man:putchar('o'); break;
            case wall:putchar('+'); break;
            case box:putchar('b'); break;
            case finishPoint:putchar('f'); break;
            default:Quit("应该不会出错的地方，为防万一打个点",UNEXPECT_ERROR);break;
            }
        }
    }
}


