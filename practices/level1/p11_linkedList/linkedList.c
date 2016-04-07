#include<stdio.h>
#include<stdlib.h>
#define FIND 5
struct List{int data;struct List *next};
struct List *head,*last;
void add();
void initialization();
void reversal();
int lookfor(int a);
int num=2;//表示链表中元素的个数
int times=0;//表示搜索的次数
int main()
{
    initialization();
    printf("请输入一组数来构成链表，输入字母来结束你的输入\n");
    add();//增加链表元素
    struct List *p=head;//用p来遍历整个链表
    printf("\n接下来将把链表反序\n");
    system("pause");
    reversal();
    printf("\n");
    p=head;
    for(int i=0;p->next!=NULL;i++)
    {
         printf("%d ",p->data);
         p=p->next;
    }
    printf("\n接下来将寻找链表中的5\n5所在的位置为");
    p=head;//把p重新指向头指针
    for(int out=0;out!=-1;)//out记录寻找的结果，一直寻找直到找不到为止
    {
        out=lookfor(FIND);
        printf("%d\t",out);
    }
    return 0;
}
void add()
{
    int a;
    scanf("%d %d",&head->data,&last->data);
    while(scanf("%d",&a)==1)
    {
        struct List *p;
        p=(struct List*)malloc(sizeof(struct List));
        p->data=a;
        p->next=NULL;
        last->next=p;
        last=p;
        num++;
    }
}
void initialization()
{
    head=(struct List*)malloc(sizeof(struct List));
    last=(struct List*)malloc(sizeof(struct List));
    head->next=last;
    last->next=NULL;
}
void reversal()
{
    struct List *p1=head,*p2=head->next;
    struct List *p3=p2->next;
    for(int i=0;p3->next!=NULL;i++)
    {
        p2->next=p1;
        p1=p2;
        p2=p3;
        p3=p3->next;
    }
    p2->next=p1;
    p3->next=p2;//将最后一个节点反序
    head->next=NULL;
    p1=head;
    head=last;
    last=p1;
}
int lookfor(int a)
{
    struct List *p=head;
    int b=times;
    for(int i=1;p->next!=NULL;i++)
    {
        if(a==p->data)
        {
            if(b!=0)
            {
                b--;
            }
            else
            {
                times++;
                return i;
            }
        }
        p=p->next;
    }
    return -1;
}
