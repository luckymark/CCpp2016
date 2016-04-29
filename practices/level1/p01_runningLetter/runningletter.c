#include<stdio.h>
#include<stdlib.h>
#define nch 80
int main()
{
    int i = 0,tot = 0,nh,nk;
    while (1)
    {
        nh = tot / nch;
        for (int j = 1;j <= nh;j++)
            printf("\n");
        if (nh % 2 == 0)    nk = tot % 80;
        else    nk = 80 - tot % 80;
        for (int j = 1;j <= nk;j++)
            printf(" ");
        printf("o");
        i++;
        tot++;
        system("cls");
    }
}
