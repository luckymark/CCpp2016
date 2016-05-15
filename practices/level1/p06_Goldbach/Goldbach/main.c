//
//  main.c
//  Goldbach
//
//  Created by 陈浩贤 on 16/3/8.
//  Copyright © 2016年 陈浩贤. All rights reserved.
//

#include <stdio.h>
#define RANGE 100
#define N 5
void getPrime();
int count;
int a[RANGE];

void GoldBath();
int main(int argc, const char * argv[]) {
    // insert code here...
    getPrime();
    GoldBath();
    
    return 0;
}

void getPrime()
{
    
    for (int n=2; n<=RANGE; n++) {
        for (int i=2; i<=n; i++) {
            if (n%i==0) {
                if (n==i) {
                    a[count]=n;
                    count++;
                }break;
                
            }
        }
    }
    
}

void GoldBath()
{
    
    for (int n=4; n<=RANGE; n=n+2) {
        for (int i=0; i<count; i++) {
            for (int j=0; j<=i; j++) {
                if (n==a[i]+a[j]) {
                    printf("%d = %d + %d\n",n,a[i],a[j]);
                }
            }
        }
    }
}


