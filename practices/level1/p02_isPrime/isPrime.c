#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int n,m,i;
    scanf("%d",&n);
    m=sqrt(n);
    if(n==1){
        printf("no");
        return 0;
    }
    for(i=2;i<=m;i++){
        if(n%i==0){
            printf("no");
            return 0;
        }
    }
    printf("yes");
    return 0;
}
