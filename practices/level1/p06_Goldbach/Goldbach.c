#include <stdio.h>
#include "allPrimes.h"
#include "BOOL.h"
#define MAX_NUM 100
#define MIN_NUM 4
BOOL check(int num);
int main()
{
    for(int i=MIN_NUM;i<=MAX_NUM;i+=2)
    {
        if(check(i)==FALSE)
        {
			printf("%d\n",i);
            puts("哥德巴赫猜想被证明是错误的，我要发财啦~~~");
            return 0;
        }
    }
    puts("证明了一百以内的哥德巴赫猜想的正确性，然而并没有什么卵用，失望~~~");
    return 0;
}
BOOL check(int num)
{
    for(int i=0;i<NUM_OF_PRIMES;i++)
    {
        for(int j=0;allPrimes[i]+allPrimes[j]<=num;j++)
        {
            if(allPrimes[i]+allPrimes[j]==num)
            {
                return TRUE;
            }
        }
    }
    return FALSE;
}
