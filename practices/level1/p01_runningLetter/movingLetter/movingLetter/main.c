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
int main()
{
    for (int i = 1; i <= 158; i++)
    {
        printf("a");
        system("cls");
        for (int q = 1; q <= (79-abs(79-i));q++)
            printf(" ");
    }
    
    return 0;
}
    
