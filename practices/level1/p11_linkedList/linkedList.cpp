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
    printf("After reverstion:\n");
    ergodicLinkList(head);
    int firstPos=findValue(head,wantTofind);
    if(firstPos==-1)
    {
        printf("%d is not find\n",wantTofind);
        return 0;
    }
    printf("The first position is %d\n",firstPos);
    int nextPos=findValue(head+firstPos+1,wantTofind)+firstPos;
    if(nextPos==-1)
    {
        printf("%d is only exist once\n",wantTofind);
        return 0;
    }
    printf("The second positon is %d\n",nextPos);
    return 0;
}
void initData(node *&head)
{
    int temp;
    node *now=head;
    while(scanf("%d",&temp)==1)
    {
        now->next=(node*)malloc(sizeof(node));
        now=now->next;
        now->value=temp;
        now->next=NULL;
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
    node *pre=NULL;
    node *after=now->next;
    while(after!=NULL)
    {
        node *temp=after->next;
        now->next=pre;  
        after->next=now;
        pre=now; 
        now=after; 
        after=temp;
    }
    head->next=now;
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