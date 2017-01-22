#include <stdio.h>
#include <stdbool.h>
#include <time.h>
const int MIN=2;
const int MAX=1000;
bool isPrime(int num);
int main()
{
    float time;
    time=clock();
    for (int j=MIN;j<=MAX;j++)
    {
        if (isPrime(j))
        {
            printf("%d\n",j);
        }
    }
    time=clock()-time;
    printf("time is %f seconds",time/CLOCKS_PER_SEC);
    return 0;
}
bool isPrime(int num)
//第二题的
{
    if ((2==num)||(3==num))
    {
        return true;
    }
    if (num%2==0)
    {
        return false;
    }
    for (int i=3;;i=i+2)
    {
        if (num%i==0)
        {
            return false;
        }
        if (num<=i*i)
        {
           return true;
        }
    }
}
