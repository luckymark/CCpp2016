#include<stdio.h>
#include<stdlib.h>
#define GOAL 5

struct node* createList(struct node*head);
void print(struct node*);
struct node* reverseList(struct node* head);
struct node* findNode(struct node* head,int goal,struct node *p);
struct node{
    int data;
    struct node *next;
};

int main()
{
    struct node loc={1,NULL},*p=&loc;
    struct node *head=NULL;
    head=createList(head);
    print(head);
    head=reverseList(head);
    print(head);
    p=findNode(head,GOAL,p);
    printf("%d\n",p->data);
    p->next=p->next->next;
    p->data++;
    p=findNode(p->next,GOAL,p);
    printf("%d\n",p->data);
    return 0;
}
struct node* createList(struct node*head)
{
    struct node*p1,*p2;
    p1=p2=(struct node*)malloc(sizeof(struct node));
    printf("输入节点的值(-1结束):");
    scanf("%d",&p1->data);
    p1->next=NULL;
    while((p1->data)!=-1)
    {
        if(head==NULL)
            {
                head=p1;
            }
        else
            {
                p2->next=p1;
            }
            p2=p1;
            p1=(struct node*)malloc(sizeof(struct node));
            printf("输入节点的值(-1结束):");
            scanf("%d",&p1->data);
    }
    free(p1);
    p1=NULL;
    p2->next=NULL;
    printf("链表输入结束!\n");
    return head;
};
void print(struct node* head)
{
    struct node*temp;
    temp=head;
    if(temp==NULL)
    {
        printf("链表为空!");
    }
    while(temp!=NULL)
    {
        printf("%d\n",temp->data);
        temp=temp->next;
    }
    printf("打印完成!\n");
}
struct node* reverseList(struct node* head)
{
    struct node *pre,*cur,*next;
    pre=head;
    cur=pre->next;
    next=NULL;
    if(cur)
    {
        next=cur->next;
        pre->next=NULL;
    }
    else
    {
        return head;
    }
    while(1)
    {
        cur->next=pre;
        if(next)
        {
            pre=cur;
            cur=next;
            next=next->next;
        }
        else
        {
            return cur;
        }
    }
};
struct node* findNode(struct node* head,int goal,struct node *p)
{
    struct node* temp;
    p->next=head;
    temp=p->next;
    while(temp!=NULL)
    {
        if(temp->data==goal)
        {
            return p;
        }
        temp=temp->next;
        p->next=temp;
        p->data++;
    }
    p->data=-1;
    return p;
}
