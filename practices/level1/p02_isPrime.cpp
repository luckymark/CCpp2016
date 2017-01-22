#include <stdio.h>
#include <stdbool.h>
bool isPrime(int num);
int main()
{
    int num;
    scanf("%d",&num);
    if (isPrime(num))
    {
        printf("yes");
    }
    else
    {
        printf("no");
    }
    return 0;
}
bool isPrime(int num)
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
