#include<stdio.h>
int main()
{
    int q,b,g;
    for (int i = 100;i < 1000;i++)
    {
        q = i / 100;
        b = i % 100 / 10;
        g = i % 10;
        if (q * q * q + b * b * b + g * g * g == i)
            printf("%d  ",i);
    }
}
