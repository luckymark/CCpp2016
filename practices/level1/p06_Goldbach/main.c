//
//  main.c
//  Goldbach
//
//  Created by Ferris on 16/6/1.
//  Copyright © 2016年 Ferris. All rights reserved.
//

#include <stdio.h>


int isprime(int n);

int main()
{
    int n,i;
    
    for(n=6;n<100;n+=2)
    {
        for(i=3;i<(n/2);i++)
        {
            if(isprime(i)!=0)
            if(isprime(n-i)!=0)
            printf("%d 可以写成 %d 与 %d 之和，哥德巴赫猜想成立。\n",n,i,n-i);
        }
    }
    return 0;
}

int isprime(int n)
{
    int j,x;
    for(j=2;j<n;j++)   if(n%j==0)
    {
        x=0;
        break;
    }
    else
        x=1;
    return(x);
}

