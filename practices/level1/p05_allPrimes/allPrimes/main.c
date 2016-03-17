//
//  main.c
//  allPrimes
//
//  Created by 陈浩贤 on 16/3/8.
//  Copyright © 2016年 陈浩贤. All rights reserved.
//

#include <stdio.h>
#include <time.h>
int main(int argc, const char * argv[]) {
    // insert code here...
    const int RANGE=1000;
    for (int n=2; n<=RANGE; n++) {
        for (int i=2; i<=n; i++) {
            if (n%i==0) {
                if (n==i) {
                    printf("%d是素数\n",n);
                }
                break;
            }
        }
        
    }
    float duration=clock();
    printf("使用时间:%f\n",0.0001*duration);
    
    return 0;
}
