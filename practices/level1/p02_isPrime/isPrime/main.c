//
//  main.c
//  isPrime
//
//  Created by 陈浩贤 on 16/3/8.
//  Copyright © 2016年 陈浩贤. All rights reserved.
//

#include <stdio.h>
void isPrime(int number);
int main(int argc, const char * argv[]) {
    // insert code here...
    
    int n;
    while (1) {
        printf("please enter your number:\n");
        scanf("%d",&n);
        isPrime(n);
    }
    
    
    return 0;
}

void isPrime(int number)
{
    int i;
    for (i=2; i<=number; i++) {
        if (number==1) {
            break;
        }else{
            if (number%i==0) {
                break;
            }
        }
    }
    if (number==i) {
        printf("%d是素数\n",number);
    }
    else
    {
        printf("%d不是素数\n",number);
    }
}
