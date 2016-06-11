#include <stdio.h>
#include <stdlib.h>

void hanoi(int count,char start,char by,char to);
void move(int count,char start,char to);

int main()
{
    int num = 0;
    printf("请输入圆盘的数量\n");
    scanf("%d",&num);
    hanoi(num,'A','B','C');
    return 0;
}

void hanoi(int count,char start,char by,char to){
    if(count>0){
        hanoi(count-1,start,to,by);
        move(count,start,to);
        hanoi(count-1,by,start,to);
    }
}

void move(int count,char start,char to){
    printf("第%d个圆盘从%c柱子移动到%c柱子\n",count,start,to);
}
