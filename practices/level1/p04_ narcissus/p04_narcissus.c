#include<stdio.h>
int main()
{
    for(int n=100;n<1000;n++)
    {
        int i,j,k,l,m;
        m=n%100;//去掉百位上的数
        k=(n-m)/100;//求出百位上的数
        l=m%10;//求出个位的数
        m=(m-l)/10;//求出十位的数
        if(n==m*m*m+l*l*l+k*k*k)//m为十位的数，k为百位的数，l为个位的数
        {
            printf("%d\n",n);
        }
    }
    return 0;
}
