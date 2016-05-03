#include<stdio.h>
#include<math.h>
#include"../p02_isPrime/isPrimeFn.h"
const int range = 100;
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
