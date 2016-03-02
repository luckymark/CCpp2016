#include<stdio.h>
int main()
{
    int a,j=0;
    scanf("%d",&a);
    for(int i=2;i<a;i++)
    {
        if(a%i==0)
        {
           j+=1;
           break;
        }
    }
    if(j==0)
    {
        printf("YES\n");
    }
    else
    {
        printf("NO\n");
    }
    return 0;
}
