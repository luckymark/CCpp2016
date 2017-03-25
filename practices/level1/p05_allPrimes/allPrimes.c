#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

void findPrimes(int* primes,int max);
void printfPrime(int* primes,int max);

int main()
{
    int primes[1000]={0};
    int max=1000;
    findPrimes(primes,max);
    printfPrime(primes,max);
    printf("\nThe time taken:%fs",(double)clock()/CLOCKS_PER_SEC);
    return 0;
}

void findPrimes(int* primes,int max){
    int i,n,j,k,m=2;
    primes[0]=2;
    primes[1]=3;
    for(i=5;i<max;i+=2){
        k=0;                                    //新循环开始时置标记数为0，表示还未发现可被整除
        n=(int)sqrt(i);
        for(j=0;primes[j]!=0&&primes[j]<=n;j++){
            if(i%primes[j]==0){
                k=1;                            //发现素因子，置标记为1并跳出循环
                break;
            }
        }
        if(k==0){                                //标记为0表示未发现素因子，为素数，将其存入数组
            primes[m]=i;
            m+=1;
        }
    }
}

void printfPrime(int* primes,int max){
    int i;
    for(i=0;primes[i]!=0;i++){
        printf("%d\t",primes[i]);
    }
}
