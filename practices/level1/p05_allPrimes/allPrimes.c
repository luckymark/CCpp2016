#include <stdio.h>
#include "BOOL.h"
#define SEARCH(x) allNum[x]
#define MAXNUM 1000
#define MAXROUND 32//1000开方为一个小数点前为31的小数，进一为32

BOOL allNum[MAXNUM+1];//Dirty way. Laze way
void initNums();
void sievePrimes();
void showAllPrimers();




int main()
{
    initNums();
    sievePrimes();
    showAllPrimers();
    return 0;
}




void initNums()
{
    for(int i=3;i<=MAXNUM;i++)
    {
        allNum[i]=i%2;
    }
    allNum[0]=allNum[1]=FALSE;
    allNum[2]=TRUE;
    return;
}
void sievePrimes()
{
    for(int i=3;i<MAXROUND;i+=2)
    {
        if(SEARCH(i)==FALSE)continue;//如果基准数不是素数，可跳过

        for(int j=i*2;j<=MAXNUM;j+=i)
        {
            allNum[j]=FALSE;
        }
    }
    return;
}
void showAllPrimers()
{
    for(int i=2;i<MAXNUM;i++)
    {
        if(SEARCH(i)==TRUE)
        {
            printf("%d\n",i);
        }
    }
}
