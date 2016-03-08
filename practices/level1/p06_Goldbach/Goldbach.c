#include<stdio.h>
#include<math.h>
int isPrime(int a);

int main()
{
    for(int i=4;i<=100;i+=2)
    {
        for(int n=2;n<=i/2;n++)
        {
            if(isPrime(n)&&isPrime(i-n))
                printf("%d=%d+%d\n",i,n,i-n);
        }
    }
    printf("Goldbach is right.");
    return 0;
}

int isPrime(int a)
{
    int b,y;
    for(b=2;b<=sqrt(a);b++)
    {
       y=a%b;
        if(y==0)
            return 0;
    }
    return 1;

}
