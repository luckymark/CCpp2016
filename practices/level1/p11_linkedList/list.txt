#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstdlib>
using namespace std;
struct list
{
	int info;
	struct list *next;
};
struct list *head,*tail,*mid;
inline void print(struct list *n)
{
	struct list *cp;
	cp=n;
	while(cp!=NULL)
	{
		printf("%d ",cp->info);
		cp=cp->next;
	}
	printf("\n");
	return;
}
int main()
{
	int n;
	struct list *q;
	head=NULL;
	for(int i=1;i<=5;i++)
	{
		scanf("%d",&n);
		mid=(struct list*)malloc(sizeof(struct list));
		mid->info=n;
		mid->next=NULL;
		if(head==NULL) head=mid;
		else tail->next=mid;
		tail=mid;
	}
    print(head);
    struct list *nhead;
	for(q=head;q!=NULL;q=q->next)
	{
		mid=(struct list*)malloc(sizeof(struct list));
		mid->info=q->info;
		mid->next=nhead;
		nhead=mid;
	}
	print(nhead);
    int num=1;
	struct list *p;
	p=nhead;
	while(p!=NULL)
	{
		if(p->info==5) printf("%d\n",num);
		else printf("-1\n");
		p=p->next;
	}
	return 0;
}