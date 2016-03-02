#include<stdio.h>
#include<math.h>
#include<stdlib.h>
int main()
{
    int j;
    for(int i=78;i>=-78;i--)
    {
        j=abs(i);
        for(int k=78;k>j;k--)
        {
            printf(" ");
        }
        printf("A");
        system("cls");
    }
    return 0;
}
