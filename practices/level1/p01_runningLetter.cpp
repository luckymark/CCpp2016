#include <stdio.h>
#include <windows.h>
const int SCREENWIDTH=110;
void Move(void);
int main()
{
    Move();
    return 0;
}
void Move(void)
{
    int k;
    for (int i=0;i<=SCREENWIDTH*2;i++)
    {
        if (i>=SCREENWIDTH)
        {
            k=SCREENWIDTH-(i-SCREENWIDTH);
        }
        else
        {
            k=i;
        }
        for (int j=0;j<=k;j++)
        {
            printf(" ");
        }
        printf("lovelive");
        system("cls");
    }
}
