#include <cstdio>
#include <cstdlib>
void initDate(linkList *head);
void ergodicinkList(linkList *head);
void reverseLinkList(linkList **head);
struct linkList
{
    int value;
    linkList *next;
};
int main()
{
    linkList *head=(linkList*)malloc(sizeof(linkList));
    initData(head);
    ergodicLinkList(head);
    reverseLinkList(head);
}
void initDate(linkList *head)
{
    int temp;
    while(scanf("%d",&temp)==1)
    {
        linkList *now=(linkList*)malloc(sizeof(linkList));
        now->value=temp;
        now->next=NULL;
        head->next=now;
        head=now;
    }
}
void ergodicinkList(linkList **head)
{
    for(head=head->next;head!=NULL;head=head->next)
    {
        // operation. For example:
        printf("value=%d\n",head->value);
    }
}
void reverseLinkList(linkList **head)
{
    linkList *now=*head->next,*pre=*head,*after=now->next;
    while(now!=NULL)
    {
        linkList *temp=after->next;
        now->next=pre;  after->next=now;
        pre=now; now=after; after=temp;
    }
    *head->next=NULL;
    *head=pre;
}
