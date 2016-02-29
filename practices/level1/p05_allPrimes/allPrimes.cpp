#include<stdio.h>
int isPrime(int n){
    int flag = 1;
    for(int i = 2;i<n/2;i++){
        if(n%i==0){
            flag = 0;
            break;
        }
    }
    return flag;
}

int main(){
    for(int j = 3;j<1001;j++){
        if(isPrime(j)){
            printf("%d ",j);
        }
    }
    return 0;
}
