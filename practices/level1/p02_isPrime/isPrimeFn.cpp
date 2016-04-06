#include<math.h>
int isPrime(int n){
    if(n==2){
        return 1;
    }
    for(int i;i<sqrt(n);i++){
        if(n%i==0){
            return 0;
        }
    }
    return 1;
}
