//
//  main.c
//  allPrimes
//
//  Created by Ferris on 16/6/1.
//  Copyright © 2016年 Ferris. All rights reserved.
//

#include <stdio.h>
#include <time.h>
int sushu(int N);

int main(int argc, const char * argv[]) {
    clock_t t1 , t2;
    t1 = clock();
    int j;
    for (j=2; j<=1000; j++) {
        if (sushu(j) == 1) {
            printf("%d\n",j);
        }
        
    }
    t2 = clock();
    printf("运算时间:%dms\n", t2-t1);
    return 0;
}
int sushu(int N)
{
    int i;
    if(N==1||N==2){
        return 1;
    }
    else{
        for(i=2;i<N;i++){
            if(N%i==0){
                return 0;
            }
        }
        if(N==i){
            return 1;
        }
        
    }
    return 0;
}

