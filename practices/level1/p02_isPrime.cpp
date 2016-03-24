#include <stdio.h>
#include <stdbool.h>
bool PrimeJudge(int num);
int main()
{
    int num;
    scanf("%d",&num);
    if (PrimeJudge(num))
    {
        printf("yes");
    }
    else
    {
        printf("no");
    }
    return 0;
}
bool PrimeJudge(int num)
//第五题第六题也能用
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
