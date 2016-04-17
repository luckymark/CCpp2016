#include <stdio.h>
#define GCD 12//Greatest Common Divisor
#define MAXAGE 1000//age that I can't imagine
int main()
{
    for(float age=GCD;age<MAXAGE;age+=GCD)
    {
        if((age/12+age/7+age/6+5+age/2+4)==age)
        {
            printf("丢番图丧子时%.0f岁\n",age-4);
            break;
        }
    }
    return 0;
}
