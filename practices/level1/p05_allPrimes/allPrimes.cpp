#include<stdio.h>
#include<math.h>
const int range = 1001;
int isPrime(int n){
    int flag = 1;
    for(int i = 2;i<=sqrt(n);i++){
        if(n%i==0){
            flag = 0;
            break;
        }
    }
    return flag;
}

int main(){
	printf("2 ");
    for(int j = 3;j<range;j++){
        if(isPrime(j)){
            printf("%d ",j);
        }
    }
    return 0;
}
