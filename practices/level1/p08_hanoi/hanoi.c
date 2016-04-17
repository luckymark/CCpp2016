#include <stdio.h>
void move()
int main(int argc,char const *argv[])
{
    move(1,2,3,64);
    return 0;
}

void move(int from,int to,int empty,int num)
{
    if (num==1)
    {
        printf("Moving to %d from %d\n", to, from);
    }
    else
    {
        move(from,empty,to,num-1);
        move(from,to,empty,1);
        move(empty,to,from,num-1);
    }
}
