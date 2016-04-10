#pragma once
#include <windows.h>
#define PAUSE() system("pause")
void gotoxy(int x, int y);//网上抄来的函数
void Quit(char*,int);
void  gotoxy(int x, int y)
{
    COORD pos;
    pos.X = x;
    pos.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
    return;
}
void Quit(char*message,int error_num)
{
    puts(message);
    PAUSE();
    exit(error_num);
}
