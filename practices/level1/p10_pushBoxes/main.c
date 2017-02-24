#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "aboutSystem.h"
#include "readLevels.h"
/*
������
�Ұѽ���ߴ�������ȫ�ֱ���
�ҽ��������ļ��Ĳ����Ե���ôdirty
������
�ҶԲ���ٺү��Ϥ�Ľ̵�
�ҶԲ���ͬ������ǵ�Ѭ��
������
2016.04.17
ٺү�Ҵ��ˣ���������ʱʵ�ڲ��������ܲ�����ʱ������

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
            default:Quit("Ӧ�ò������ĵط���Ϊ����һ�����",UNEXPECT_ERROR);break;
            }
        }
    }
}


