#include<stdio.h>
int isPrime(int n){
    int flag = 1;
    for(int i;i<n/2;i++){
        if(n%i==0){
            flag = 0;
            break;
        }
    }
    return flag;
}
int main(){
    int n = 0;
    scanf("%d",&n);
    if(n>2){
        if(isPrime(n)){
            printf("%d is a prime",n);
        }else{
            printf("%d is not a prime",n);
        }
    }else if(n==2){
        printf("%d is a prime",n);
    }else{
        printf("wrong input");
    }
    return 0;
}
