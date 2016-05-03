#include<stdio.h>
#include<stdlib.h>
#define WIDTH 118
#define abs(a) (a>0?a:-a)
int main()
{
    for(int i=WIDTH;i>=-WIDTH;i--)
    {
        int j;
        j=abs(i);
        for(int w=WIDTH;w>j;w--)
        {
            printf(" ");
        }
        printf("A");
        system("cls");
    }
    return 0;
}
