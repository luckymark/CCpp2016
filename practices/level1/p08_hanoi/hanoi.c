#include <stdio.h>
#include <stdlib.h>

int move(int n,char from,char to){
    printf("%d %c->%c\n",n,from,to);
    return 0;
}

int hanoi(int first,int last,char from,char to,char other){
    if(first==last){
        move(first,from,to);
    }else{
        hanoi(first,last-1,from,other,to);
        move(last,from,to);
        hanoi(first,last-1,other,to,from);
    }
    return 0;
}

int main()
{
    char a='a',b='b',c='c';
    hanoi(1,64,a,c,b);
    return 0;
}
