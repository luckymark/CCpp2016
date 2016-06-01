//
//  main.c
//  奔跑的字母
//
//  Created by Ferris on 16/3/22.
//  Copyright © 2016年 Ferris. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

int main(int argc, const char * argv[]) {
    int i,j;
    char a='A';
    for(i=0;i<=156;i++){
        if(i<80){
            printf("%*c",i,a);
        }
        else{
            printf("%*c",156-i,a);
        }
        system("clear");
    }
    return 0;
}
