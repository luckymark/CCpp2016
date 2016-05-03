#include<stdio.h>
#include<math.h>
#include"../p02_isPrime/isPrimeFn.h"
const int range = 1001;

int main(){
    for(int j = 2;j<range;j++){
        if(isPrime(j)){
            printf("%d ",j);
        }
    }
    return 0;
}
