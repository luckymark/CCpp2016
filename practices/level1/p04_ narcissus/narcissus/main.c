//
//  main.c
//  narcissus
//
//  Created by 陈浩贤 on 16/3/8.
//  Copyright © 2016年 陈浩贤. All rights reserved.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    // insert code here...
    for (int i=1; i<=9; i++) {
        for (int j=0; j<=9; j++) {
            for (int k=0; k<=9; k++) {
                int flower=100*i+10*j+k;
                if (i*i*i+j*j*j+k*k*k==flower) {
                    printf("flower:%d\n",flower);
                }
            }
        }
    }
    return 0;
}
