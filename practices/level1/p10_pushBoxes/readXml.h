#pragma once
#include "readLevels.h"

void readWalls(FILE*,char**);
void readBoxs(FILE*, char**);
void readFinishPoints(FILE*, char**);

void readWalls(FILE*mapData, char**map)
{
    int numOfLines=-1;
    fscanf(mapData," lineNum=\"%d\"> ",&numOfLines);
    if (numOfLines == -1)
    {
        Quit("δ֪����(��ȡlines����ʧ��)",UNEXPECT_ERROR);
    }
    char buffer[255];
    while (numOfLines--)
    {
        int id=-1,num=-1,tempY;
        fscanf(mapData," <line id=\"%d\" num=\"%d\">",&id,&num);
        if (id == -1 || num == -1)
        {
            Quit("δ֪����(��ȡwallʧ��)",UNEXPECT_ERROR);
        }
        else
        {
            while (num--)
            {
                fscanf(mapData," %d ",&tempY);
                map[id][tempY] =wall;
            }
            fscanf(mapData," </line> ");
        }
    }
    fscanf(mapData, " </walls> ");
    return;
}
void readBoxs(FILE*mapData, char**map)
{
    int numOfBoxs=-1;
    fscanf(mapData," num=\"%d\"> ",&numOfBoxs);
    if (numOfBoxs == -1)
    {
        Quit("δ֪����(��ȡbox����ʧ��)",UNEXPECT_ERROR);
    }
    while (numOfBoxs--)
    {
        int tempX=-1, tempY=-1;
        fscanf(mapData," <box>%d %d</box> ",&tempX,&tempY);
        if (tempX == -1 || tempY == -1)
        {
            Quit("δ֪����(��ȡboxʧ��)",UNEXPECT_ERROR);
        }
        else
        {
            map[tempX][tempY] = box;
        }
    }
    fscanf(mapData,"</boxs>");
    return;
}
void readFinishPoints(FILE*mapData, char**map)
{
    int numOfFinishPoints = -1;
    fscanf(mapData,"num=\"%d\"> ",&numOfFinishPoints);
    if (numOfFinishPoints == -1)
    {
        Quit("δ֪����(��ȡfinishPoint����ʧ��)",UNEXPECT_ERROR);
    }
    while (numOfFinishPoints--)
    {
        int tempX=-1, tempY = -1;
        fscanf(mapData," <finishPoint>%d %d</finishPoint> ",&tempX,&tempY);
        if (tempX == -1 || tempY == -1)
        {
            Quit("δ֪����(��ȡfinishPointʧ��)",UNEXPECT_ERROR);
        }
        map[tempX][tempY] = finishPoint;
    }
    fscanf(mapData," </finishPoints> ");
    return;
}