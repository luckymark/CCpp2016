#include <stdio.h>
#include <stdlib.h>
#define CONSOLE_WIDTH 119

int main()
{
    int i,j;
    for(i=0;i<=CONSOLE_WIDTH-1;i++)
    {
        for(j=0;j<=i;j++)
        {
            printf(" ");
        }
        printf("A");
        system("cls");
    }
    for(i=CONSOLE_WIDTH-2;i>=0;i--)
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
