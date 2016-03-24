#include <stdio.h>
#include <stdbool.h>
#include <time.h>
const int MIN=2;
const int MAX=1000;
bool PrimeJudge(int num);
int main()
{
    int time;
    time=clock();
    for (int j=MIN;j<=MAX;j++)
    {
        if (PrimeJudge(j))
        {
            printf("%d\n",j);
        }
    }
    time=clock()-time;
    printf("time is %d",time);
    return 0;
}
bool PrimeJudge(int num)
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
