#include<stdio.h>
char *prime_judge(int a)
{
    int flag=0;
    for(int i=2;i<a;i++)
    {
        if(a%i==0)
        {
           flag+=1;
           break;
        }
    }
    if(flag==0)
    {
        return "Yes";
    }
    else
    {
        return "No";
    }
}
int main()
{
    int a;
    scanf("%d",&a);
    printf("%s",prime_judge(a));
    return 0;
}
