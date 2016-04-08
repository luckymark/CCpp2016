#include<stdio.h>
#include<math.h>
#include<stdbool.h>
bool isPrime(int a);
int main()
{
    int n;
    printf("input a number:");
    scanf("%d",&n);
    if(isPrime(n)!=0)
    {
        printf("It is a prime number");
    }
    else
    {
        printf("It is not a prime number");
    }
    return 0;
}
bool isPrime(int a)
{
    int b,y;
    for(b=2;b<sqrt(a);b++)
    {
        y=a%b;
        if(y==0)
        {
            return false;
        }
    }
    return true;
}
