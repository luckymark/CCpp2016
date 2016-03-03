#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int main()
{
    int i,n,j,k,m=1;                            //k用来标记是否被整除，m用来表示素数数组中最后一项的下标
    int a[500]={2,3};                           //a为素数数组
    printf("2\t3\t");
    for(i=5;i<1000;i+=2){
        k=0;                                    //新循环开始时置标记数为0，表示还未发现可被整除
        n=(int)sqrt(i);
        for(j=0;a[j]!=0&&a[j]<=n;j++){
            if(i%a[j]==0){
                k=1;                            //发现素因子，置标记为1并跳出循环
                break;
            }
        }
        if(k==0){                                //标记为0表示未发现素因子，为素数，打印该数并将其存入数组
            m+=1;
            a[m]=i;
            printf("%d\t",i);
        }
    }
    printf("\nThe time taken:%fs",(double)clock()/CLOCKS_PER_SEC);
    return 0;
}
