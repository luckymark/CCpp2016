#include <cstdio>
void moveBlocks(int BlockNum,int Start,int Temp,int End);
int main()
{
    int n;
    printf("Please input the number of blocks:\n");
    scanf("%d",&n);
    moveBlocks(n,1,2,3);
}
void moveBlocks(int BlockNum,int Start,int Temp,int End)
{
    if(BlockNum==0)
    {
        return ;
    }
    else
    {
        moveBlocks(BlockNum-1,Start,End,Temp);
        printf("%dth Block from %c to %c\n",BlockNum,Start+'A'-1,End+'A'-1);
        moveBlocks(BlockNum-1,Temp,Start,End);
    }
}
