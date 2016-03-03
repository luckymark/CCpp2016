#include<stdio.h>
#define MAX 80
int main()
{
    char a='A';
    int n,m;
    for(n=0;n<MAX;n++)
    {
        for(m=0;m<n;m++)
        {
            printf(" ");
        }
        printf("%c",a);
        system("cls");
    }
    for(n=MAX-1;n>=0;n--)
    {
        for(m=0;m<n;m++)
        {
            printf(" ");
        }
        printf("%c",a);
        system("cls");
    }

    return 0;
}

