#include<stdio.h>
#include<stdlib.h>
#define MAX 80
int main()
{
    char a='A';
    for(int n=0;n<2*MAX;n++)
    {
        for(int m=0;m<(MAX-abs(MAX-n));m++)
        {
            printf(" ");
        }
        printf("%c",a);
        system("cls");
    }
    return 0;
}

