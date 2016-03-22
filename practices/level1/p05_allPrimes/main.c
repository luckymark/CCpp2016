//
//  main.c
//  打印素数
//
//  Created by Ferris on 16/3/3.
//  Copyright © 2016年 Ferris. All rights reserved.
//

#include <stdio.h>
#include <time.h>
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
                break;
            }
        }
        if(N==i){
            return 1;
        }
        
    }
    return 0;
}

int main(int argc, const char * argv[]) {
    int j,k;
    for (j=2; j<=1000; j++) {
        if (sushu(j) == 1) {
            printf("%d\n",j);
        }
        
    }
    
    clock_t t1 , t2;
    t1 = clock();
    for (k=0;k<1000000000;k++);
    t2 = clock();
    printf("运算时间%d \n", t2-t1);
    return 0;
}
