#include<stdio.h>
#include<math.h>
#include"../p02_isPrime/isPrimeFn.h"
const int range = 1001;

int main(){
    printf("2 ");
    for(int j = 3;j<range;j++){
        if(isPrime(j)){
            printf("%d ",j);
        }
    }
    return 0;
}
