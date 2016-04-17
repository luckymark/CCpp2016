#include <stdio.h>
#define _POW(x,y,z) x*x*x+y*y*y+z*z*z
int main()
{
    for(int i=1;i<10;i++)
    {
        for(int j=0;j<10;j++)
        {
            for(int k=0;k<10;k++)
            {
                int temp=_POW(i,j,k);
                if(i*100+j*10+k==temp)
                {
                    printf("%d\n",temp);
                }
            }
        }
    }
    return 0;
}
