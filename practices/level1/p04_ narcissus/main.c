//
//  main.c
//  水仙花数
//
//  Created by Ferris on 16/2/29.
//  Copyright © 2016年 Ferris. All rights reserved.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    int i,a,b,c;
    for (i=100; i<1000; i++) {
        a=i/100;
        b=(i-a*100)/10;
        c=i-(a*100)-(b*10);
        if (a^3+b^3+c^3==i) {
            printf("%d\n",i);
        }
    }
    return 0;
}
