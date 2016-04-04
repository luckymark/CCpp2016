#include<stdio.h>

int main()
{
    for(int i=2;i<200;i++)
    {
        if(i%12==0&&i%7==0)
        {
            if((i-9-i/6-i/12-i/7)==(i/2))
            {
            printf("%d\n",i-4);
            break;
            }
        }
    }
    return 0;
}
