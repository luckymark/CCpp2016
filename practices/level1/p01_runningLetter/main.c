#include <stdio.h>
#include <stdlib.h>
#define CONSOLE_WIDTH 119

int main()
{
    int i,j;
    for(i=0;i<=2*CONSOLE_WIDTH+1;i++)
    {
        for(j=0;j<=CONSOLE_WIDTH-abs(CONSOLE_WIDTH-i);j++)
        {
            printf(" ");
        }
        printf("A");
        system("cls");
    }
    return 0;
}
