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
        k=0;                                    //��ѭ����ʼʱ�ñ����Ϊ0����ʾ��δ���ֿɱ�����
        n=(int)sqrt(i);
        for(j=0;primes[j]!=0&&primes[j]<=n;j++){
            if(i%primes[j]==0){
                k=1;                            //���������ӣ��ñ��Ϊ1������ѭ��
                break;
            }
        }
        if(k==0){                                //���Ϊ0��ʾδ���������ӣ�Ϊ�����������������
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
