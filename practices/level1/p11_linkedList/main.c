#include <stdio.h>
#include <stdlib.h>
#define NULL 0
#define TYPE struct node
#define LEN sizeof (struct node)

struct node
    {
        int num;
        struct node *next;
    };
TYPE *creat(int n);//创建链表
void print();//显示各节点值
TYPE *nodeReverse();//节点反序
int serchNode();
int main()
{
    printf("input the number of nodes:");
    int n;
    scanf("%d",&n);
    TYPE *head=NULL;
    head=creat(n);
    print(head);
    TYPE *newHead;
    newHead=nodeReverse(head);
    printf("\n反序后");
    print(newHead);
    printf("查找结果为:");
    int i,j=0;
    for(i=0;i<n;i++)
    {
        int j=serchNode(newHead,n,j);
        printf("\n%d",j);
    }
    return 0;
}


TYPE *creat(int n)
{
    TYPE *head,*pf,*pb;
    int i;
    for(i=0;i<n;i++)
    {
        pb=(TYPE*) malloc(LEN);
        printf("input a number\n");
        scanf("%d",&pb->num);
        if(i==0)
        {
            pf=head=pb;
        }
        else
        {
            pf->next=pb;
            pb->next=NULL;
            pf=pb;
        }
    }
    return head;
}


void print(TYPE *head)
{
    TYPE *temp;
    temp=head;
    printf("各节点的值为:");
    while(temp!=NULL)
    {
        printf("%d ",temp->num);
        temp=temp->next;
    }
}


TYPE *nodeReverse(TYPE *head)
{
    TYPE *p1=head,*p2=head->next,*p3;
    if(head==NULL||head->next==NULL)
    {
        return head;
    }
    while(p2!=NULL)
    {
        p3 = p2->next;
        p2->next = p1;
        p1 = p2;
        p2 = p3;
    }
    head->next = NULL;
    head=p1;
    return head;
}

int serchNode(TYPE *head,int n,int j)
{
    TYPE *temp;
    temp=head;
    int i=1;
    while(temp!=NULL)
    {
        if(temp->num==5)
        {
            temp->num=4;
            j++;
            return i;
        }
        temp=temp->next;
        if(i==n)
        {
            return -1;
        }
        i++;
    }
}

