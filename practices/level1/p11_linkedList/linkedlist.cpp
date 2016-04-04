#include<stdio.h>
#include<stdlib.h>
struct linkedlist{
	int a;
	struct linkedlist *next;
};
struct linkedlist *create();
void travel(struct linkedlist *head);
void search(struct linkedlist *head);
struct linkedlist *reverse(struct linkedlist *head);
int main()
{
	int num;
	struct linkedlist *head;
	head=create();
	printf("Sequenced Output:\n");
	travel(head);
	head=reverse(head);
	printf("Reversed Output:\n");
	travel(head);
	search(head);
	return 0;
}
struct  linkedlist* create()
{
    struct linkedlist *head;
    struct linkedlist *p1,*p2;
    int n=0;
    p1=p2=(struct linkedlist *)malloc(sizeof(struct linkedlist));
	printf("Input the number(-9999 to exit):");
    scanf("%d",&p1->a);
    head=NULL;
    while(p1->a!=-9999)
    {
        n++;
        if(n==1){
			head=p1;
		}
        else{
			p2->next=p1;
		}
        p2=p1;
        p1=(struct linkedlist*)malloc(sizeof(struct linkedlist));
		printf("Input the number(-9999 to exit):");
        scanf("%d",&p1->a);
    }
    p2->next=NULL;
    return (head);
}
void travel(struct linkedlist *head)
{
	struct linkedlist *p;
	p=head;
	if (head!=NULL)
	{
		int i=0;
		do
		{
			i++;
			printf("The No.%d data is %d\n",i,p->a);
			p=p->next;
		}while (p!=NULL);
	}
	return;
}
struct linkedlist *reverse(struct linkedlist *head)
{
	struct linkedlist *p,*p1,*p2;
	p1=NULL;
	p2=head;
	while (p2!=NULL)
	{
		p=p2->next;
		p2->next=p1;
		p1=p2;
		p2=p;
	}
	head=p1;
	return head;
}
void search(struct linkedlist *head)
{
	struct linkedlist *p=NULL;
	int i=0,num=0;
	for(p=head;p!=NULL;p=p->next) 
	{
		i++;
		if (p->a==5) {
			num++;
			printf("%d\n",i);
			if (num==2) return;
		}
	}
	for (i=1;i<=2-num;i++)
	{
		printf("-1\n");
	}
	return;
}