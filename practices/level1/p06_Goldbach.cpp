#include <stdio.h>
#include <stdbool.h>
const int NUM=100;
bool isPrime(int j);
void Goldbach(void);
int main()
{
    Goldbach();
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
void Goldbach(void)
{
    bool num1[NUM];
    for (int i=2;i<=NUM;i++)
    {
        num1[i]=false;
        if (isPrime(i))
        {
            num1[i]=true;
        }
    }
    for (int i=2;i<=NUM;i=i+2)
    {
        for (int j=2;j<=i;j++)
        {
            for (int k=2;k<=i;k++)
            {
                if (num1[j]&&num1[k]&&(i==j+k))
                {
                    printf("%d=%d+%d\n",i,j,k);
                }
                //将此处改写为bool型函数可以只输出一组解
            }
        }
    }
}
