#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "someNum.h"
#include "readXml.h"
char**getMap(FILE*);
FILE*findFile(int);
char**getArray(int, int);
FILE*findFile(int level)
{
    width = height = -1;//��ʼ��һ�£����ں�߲��
    char dataFileName[20];
    itoa(level,dataFileName,10);//����ת��Ϊ�ַ���
    strcat(dataFileName,".xml");
    FILE* file = fopen(dataFileName, "rb");
    if (file != NULL)
    {
        return file;
    }
    else
    {
        Quit("�ؿ�������",FILE_NOT_EXIST);
    }
}

char**getMap(FILE* mapData)
{
    int man_x,man_y;
    fscanf(mapData,"<game width=\"%d\" height=\"%d\" man=\"(%d,%d)\"> ",&width,&height,&man_x,&man_y);//�������man��������COORD��ʾ�ģ����Ǻ�������COORD��x��y����short int��ת������̫���鷳���Ծ�ֱ��man_x,man_y
    if (height == -1 || width == -1)
    {
        Quit("δ֪����(��ȡmanʧ��)",UNEXPECT_ERROR);
    }
    char** map = getArray(width,height);
    map[man_x][man_y] = man;

    char buffer[256];
    while (1)
    {
        fscanf(mapData," %s ",buffer);
        if (strcmp("<walls", buffer) == 0)
        {
            readWalls(mapData,map);
        }
        else if (strcmp("<boxs", buffer) == 0)
        {
            readBoxs(mapData,map);
        }
        else if (strcmp("<finishPoints", buffer) == 0)
        {
            readFinishPoints(mapData,map);
        }
        else if (strcmp("</game>", buffer) == 0)
        {
            break;
        }
        else
        {
            Quit("δ֪����(��ȡ����ʧ��)",UNEXPECT_ERROR);
        }
    }
    return map;
}
char**getArray(int width,int heigth)
{
    char**map =(char**) malloc(width*sizeof(char*));
    for (int i = 0; i < width; i++)
    {
        map[i] = (char*)malloc(heigth*sizeof(char));
        memset(map[i],0,heigth*sizeof(char));
    }
    return map;
}