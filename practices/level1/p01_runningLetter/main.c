#include <stdio.h>
#include <stdlib.h>
#define consoleWidth 119

int main()
{
    int i,j;
    for(i=0;i<=consoleWidth-1;i++)
    {
        for(j=0;j<=i;j++)
        {
            printf(" ");
        }
        printf("A");
        system("cls");
    }
    for(i=consoleWidth-2;i>=0;i--)
    {
        for(j=0;j<=i;j++)
        {
            printf(" ");
        }
        printf("A");
        system("cls");
    }
    return 0;
}
