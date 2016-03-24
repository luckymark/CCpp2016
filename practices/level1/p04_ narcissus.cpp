#include <stdio.h>
void Narcissus(void);
int main()
{
    Narcissus();
    return 0;
}
void Narcissus(void)
{
    for (int i=100;i<=999;i++)
    {
        if ((i/100)*(i/100)*(i/100)+(i%10)*(i%10)*(i%10)+((i-(i/100)*100)/10)*((i-(i/100)*100)/10)*((i-(i/100)*100)/10)==i)
        {
            printf("%d\n",i);
        }
    }
}
