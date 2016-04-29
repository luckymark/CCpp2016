#include<stdio.h>
#include<math.h>
int check(int a)
{
    for (int i = 2;i <= sqrt(a);i++)
        if (a % i == 0) return 0;
    return 1;
}
int main()
{
    int pri[1010] = {0},i,j;
    for (i = 2;i <= 1000;i++)
    {
        if (pri[i] == 0 && check(i))
        {
            printf("%d ",i);
            for (j = i * 2;j <= 1000;j += i)
                pri[i] = 1;
        }
    }
}
