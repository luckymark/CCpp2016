//
//  main.c
//  希腊诗选
//
//  Created by Ferris on 16/2/29.
//  Copyright © 2016年 Ferris. All rights reserved.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    float i;
    for(i=0;i<1000;i++){
        if((i/12+i/6+i/7+5+i/2+4)==i){
                printf("age=%.0f\n",i);
                break;
        }
    }
    return 0;
 

}
