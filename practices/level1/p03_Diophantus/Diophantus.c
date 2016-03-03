#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i;
    for(i=1;i<=100;i++){
       if(i%12!=0||i%7!=0){
           continue;
       }else if((i/2)==(i-i/12-i/6-i/7-5-4)){
           break;
       }
    }
    printf("%d",i-4);
    return 0;
}
