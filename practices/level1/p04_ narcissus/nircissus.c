#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i,j,k,n,m;
    for(i=1;i<=9;i++){
        for(j=0;j<=9;j++){
            for(k=0;k<=9;k++){
                n=i*100+j*10+k;
                m=i*i*i+j*j*j+k*k*k;
                if(m==n){
                    printf("%d\n",n);
                }
            }
        }
    }
    return 0;
}
