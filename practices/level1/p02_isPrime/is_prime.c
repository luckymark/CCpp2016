#include<stdio.h>
#include<math.h>
void jduge(int a)
{
    int b,y;
    for(b=2;b<sqrt(a);b++)
    {
       y=a%b;
        if(y==0)
        break;
    }
    if(y!=0)
    printf("It is a prime number");
    else
    printf("It is not a prime number");


}
int main()
{
    int n;
    printf("input a number:");
    scanf("%d",&n);
    jduge(n);
    return 0;

}
