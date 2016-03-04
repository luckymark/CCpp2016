#include<stdio.h>
//#include<math.h>
#include<time.h>
#define MAX 1001
/*int jduge(int a)     //ËØÊıÅĞ¶Ï
{
    int b,y;
    for(b=2;b<sqrt(a);b++)
    {
       y=a%b;
        if(y==0)
        break;
    }
    if(y!=0)
   {
       printf("%d  ",a);
       return 1;
   }
   else
    return 0;
}*/
int main()
{   clock_t t1,t2;
    t1=clock();
    int num[MAX]={1,1}, i,j;
   for(i=2;i<MAX;i++)
  {
      if(!num[i])
      {
         printf("%d  ",i);
        for(j=i+i;j<=MAX-1;j+=i)
            num[j]=1;
        }
    }

    t2=clock();
    printf("%g seconds",(t2-t1)/(double)CLOCKS_PER_SEC);
    return 0;

}
