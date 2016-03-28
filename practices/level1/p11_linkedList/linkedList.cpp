#include <cstdio>
#include <cstdlib>
#define wantTofind 5
struct node
{
    int value;
    node *next;
};
void initData(node *&head);
void ergodicLinkList(node *head);
void reverseLinkList(node *&head);
int findValue(node *head,int exceptValue);
int main()
{
    node *head=(node*)malloc(sizeof(node));
    initData(head);
    ergodicLinkList(head);
    reverseLinkList(head);
    // int firstPos=findValue(head,wantTofind);
    // printf("%d\n",firstPos);
    // int nextPos=findValue(head+firstPos+1,wantTofind)+firstPos;
    // printf("%d\n",nextPos);
}
void initData(node *&head)
{
    int temp;
    while(scanf("%d",&temp)==1)
    {
        node *now=(node*)malloc(sizeof(node));
        now->value=temp;
        now->next=NULL;
        head->next=now;
        head=now;
    }
}
void ergodicLinkList(node *head)
{
    for(head=head->next;head!=NULL;head=head->next)
    {
        printf("value=%d\n",head->value);
    }
}
void reverseLinkList(node *&head)
{
    node *now=head->next;
    node *pre=head;
    node *after=now->next;
    while(after!=NULL)
    {
        node *temp=after->next;
        now->next=pre;  after->next=now;
        pre=now; now=after; after=temp;
    }
    head->next=NULL;
    head=pre;
}
int findValue(node *head,int exceptValue)
{
    int pos=0;
    for(head=head->next;head!=NULL;head=head->next)
    {
        ++pos;
        if(head->value==exceptValue)
        {
            return pos;
        }
    }
    return -1;
}