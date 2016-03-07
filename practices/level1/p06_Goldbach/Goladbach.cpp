#include<stdio.h>
#include<math.h>
const int range = 100;
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
    for(int i = 3;i<=range;i++){
        if(!(i%2)){
            for(int j = 2;i<i/2;j++){
                if(isPrime(j)&&isPrime(i-j)){
                    break;
                }else{
                    printf("%d can't",i);
                }
            }
        }
    }
    printf("done");
    return 0;
}
