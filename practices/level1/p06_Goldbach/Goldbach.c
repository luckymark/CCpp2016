#include<stdio.h>
#include<math.h>
int jduge(int a)
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
int main()
{
    int i,n;
    for(i=4;i<=100;i+=2)
    {
        for(n=2;n<=i/2;n++)
        {
            if(jduge(n)&&jduge(i-n))
                printf("%d=%d+%d\n",i,n,i-n);
        }
    }
    printf("Goldbach is right.");
    return 0;
}
