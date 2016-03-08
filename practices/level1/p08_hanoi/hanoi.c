#include <stdio.h>
#include <stdlib.h>

int move(int n,char from,char to);
int hanoi(int n,char from,char to,char other);

int main()
{
    char a='a',b='b',c='c';
    hanoi(64,a,c,b);
    return 0;
}

int move(int n,char from,char to){
    printf("%d %c->%c\n",n,from,to);
    return 0;
}

int hanoi(int n,char from,char to,char other){
    if(n==1){
        move(n,from,to);
    }else{
        hanoi(n-1,from,other,to);
        move(n,from,to);
        hanoi(n-1,other,to,from);
    }
    return 0;
}
