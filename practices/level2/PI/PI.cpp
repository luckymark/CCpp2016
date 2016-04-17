#include <cstdio>
#include <cstring>
#include <time.h>
#define SIZE 10010
#define DISPCNT 10000

int main()
{
    double start,finsh;
    start=clock();
    freopen("out.txt","w",stdout);
    int x[SIZE],ans[SIZE];
    memset(x,0,sizeof(x));
    memset(ans,0,sizeof(ans));
    ans[1]=x[1]=2;
    int a=1,b=3,Run=1,Cnt=0;
    while(Run && (++Cnt<200000000))
    {
        //x*=a
        int d=0,c;
        for(int i=SIZE-1;i>0;i--)
        {
            c=x[i]*a+d;
            x[i]=c%10;
            d=c/10;
        }
        //x/=b;
        d=0;
        for(int i=1;i<SIZE;i++)
        {
            c=x[i]+d*10;
            x[i]=c/b;
            d=c%b;
        }
        //ans+=x
        Run=0;
        for(int i=SIZE-1;i>0;i--)
        {
            c=x[i]+ans[i];
            ans[i]=c%10;
            ans[i-1]+=c/10;
            Run|=x[i];
        }
        a++;
        b+=2;
       // printf("Run=%d cnt=%d\n",Run,Cnt);
    }
    printf("3.");
    for(int i=2;i<=DISPCNT;i++)
    {
        printf("%d",ans[i]);
    }
    printf("\n");
    finsh=clock();
    printf("Total time:%gms\n",finsh-start);
    printf("Total memory:%db\n",sizeof(x)+sizeof(ans));
    return 0;
}
