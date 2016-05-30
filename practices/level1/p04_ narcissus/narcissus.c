#include <stdio.h>
#include <stdlib.h>

int is_narcissus(int num);

int main()
{
    printf("三位的水仙花数有：\n");
    for(int i=100;i<1000;i++){
        if(is_narcissus(i)){
            printf("%d\n",i);
        }
    }
    return 0;
}

int is_narcissus(int num){
    int hundred = num/100;
    int ten = (num - hundred*100)/10;
    int one = num%10;
    if(hundred*hundred*hundred+ten*ten*ten+one*one*one==num){
        return 1;
    }
    return 0;
}

