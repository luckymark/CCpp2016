//
//  main.c
//  isPrime
//
//  Created by 陈浩贤 on 16/3/8.
//  Copyright © 2016年 陈浩贤. All rights reserved.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    // insert code here...
    int n,i;
    printf("please enter your number:\n");
    scanf("%d",&n);
    for (i=2; i<=n; i++) {
        if (n==1) {
            break;
        }else{
            if (n%i==0) {
                break;
            }
        }
    }
    if (n==i) {
        printf("%d是素数\n",n);
    }
    else
    {
        printf("%d不是素数\n",n);
    }
    return 0;
}
