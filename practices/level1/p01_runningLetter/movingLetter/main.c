//
//  main.c
//  movingLetter
//
//  Created by 陈浩贤 on 16/2/22.
//  Copyright © 2016年 陈浩贤. All rights reserved.
//

#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define WIDTH 158
int main()
{
    for (int i = 1; i <= WIDTH; i++)
    {
        printf("a");
        system("cls");
        for (int i = 1; i <= (WIDTH/2-abs(WIDTH/2-i));i++)
            printf(" ");
    }
    
    return 0;
}
    
