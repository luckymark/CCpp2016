#include <cstdio>
void MoveBlocks(int BlockNum,int Start,int Temp,int End)
{
    if(BlockNum==1)
    {
        printf("%dth Block from %c to %c\n",BlockNum,Start+'A'-1,End+'A'-1);
        return ;
    }
    else
    {
        MoveBlocks(BlockNum-1,Start,End,Temp);
        printf("%dth Block from %c to %c\n",BlockNum,Start+'A'-1,End+'A'-1);
        MoveBlocks(BlockNum-1,Temp,Start,End);
    }
}
int main()
{
    int n;
    printf("Please input the number of blocks:\n");
    scanf("%d",&n);
    MoveBlocks(n,1,2,3);
}
