#include<stdio.h>

int main()
{
    for(int n=100;n<1000;n++)
    {
        int i,j,k,l,m;
        m=n%100;
        k=(n-m)/100;
        l=m%10;
        m=(m-l)/10;
        if(n==m*m*m+l*l*l+k*k*k)
        {
            printf("%d\n",n);
        }
    }
    return 0;
}
