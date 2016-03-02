#include<stdio.h>
#include<time.h>
int main()
{
    int a;
    clock_t t1=clock();
    printf("2\n3\n");
    for(int i=5;i<1001;i+=2)
    {
        int b=0;
        for(int j=3;j<i;j+=2)
        {
            if(i%j==0)
            {
                b+=1;
                break;
            }
        }
        if(b==0)
        {
            printf("%d\n",i);
        }
    }
    clock_t t2=clock();
    printf("time:%d\n",t2-t1);
    return 0;
}
