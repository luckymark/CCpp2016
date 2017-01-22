#include <stdio.h>
int Age(void);
int main()
{
    printf("%d\n",Age()-4);
    return 0;
}
int Age(void)
{
    for (double i=1;;i++)
    {
        if (i/6+i/12+i/7+5+i/2+4==i)
        {
            return i;
        }
    }
}
