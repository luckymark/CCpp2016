#include <stdio.h>
#include <stdlib.h>

int hanoi(int n,char from,char to,char other);

int main()
{
    char a='a',b='b',c='c';
    hanoi(64,a,c,b);
    return 0;
}


int hanoi(int n,char from,char to,char other){
    if(n==1){
        printf("%d %c->%c\n",n,from,to);
    }else{
        hanoi(n-1,from,other,to);
        printf("%d %c->%c\n",n,from,to);
        hanoi(n-1,other,to,from);
    }
    return 0;
}
