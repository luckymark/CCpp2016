#include<stdio.h>
#include"isPrimeFn.h"
int main(){
    int n = 0;
    scanf("%d",&n);
    if(n>1){
        if(isPrime(n)){
            printf("%d is a prime",n);
        }else{
            printf("%d is not a prime",n);
        }
    }else{
        printf("wrong input");
    }
    return 0;
}
