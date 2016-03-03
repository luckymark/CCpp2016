#include <stdio.h>

int isPrime(int num);

int main(void){
    //define
    int x;
    //input
    scanf("%d",&x);
    //judge
    if(isPrime(x)){
        printf("Y");
    }
    else{
        printf("N");
    }
    return 0;
}

int isPrime(int num) {
    int i;

    for (i = 2; i < num; i++){
        if (num % i == 0)
            return 0;
    }
    return 1;
}