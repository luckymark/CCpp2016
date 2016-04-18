#include<stdio.h>
int main()
{
    for(int i=2;i<190;i++)
    {
        float y1,y2;
        y1=i;
        y2=y1/2;
        if(y1*17/28-9-y2<1e-6&&y1*17/28-9-y2>-1e-6)
        {
            printf("%d\n",i-4);
            break;
        }
    }
    return 0;
}
