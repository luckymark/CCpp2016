#include<stdio.h>
#include<stdlib.h>
struct node
{
	int value;
	struct node*next;
};
struct node*first=NULL;
struct node*add_to_list(struct node*list,int n);
void in_list();
void reverse_list();
void print_list();
int search_list(int *q);
int search_list_next(int *q);
int main()
{
	int n;
	int i=0;
	//int *q;
	//q=&i;
	for(;;)
	{
		scanf("%d",&n);
		if(n==0)
		{
			break;
		}
		first=add_to_list(first,n);
	}
	print_list();
	printf("\n");
	reverse_list();
	print_list();
	printf("\n");
	printf("%d\n",search_list(&i));  
	first=first->next;
	printf("%d",search_list(&i));
	return 0;
}
struct node*add_to_list(struct node*list,int n)
{
	struct node*newnode;
	newnode=(struct node*)malloc(sizeof(struct node));
	newnode->value=n;
	newnode->next=list;
	return newnode;
}
void print_list()
{
	for(struct node*p=first;p!=NULL;p=p->next)
	{
		printf("%d",p->value);
		printf(" ");
	}
}
void in_list()
{
	for(int n;;)
	{
		scanf("%d",&n);
		if(n==0)
		{
			break;
		}
		first=add_to_list(first,n);
	}
}
void reverse_list()
{
	struct node*cur,*pre,*tmp;
	cur=first;
	pre=cur->next;
	tmp=pre->next;
	pre->next=cur;
	cur->next=NULL;
	cur=pre;
	pre=tmp;
	while(pre!=NULL)
	{
		tmp=pre->next;
		pre->next=cur;
		cur=pre;
		pre=tmp;
	}
	first=cur;
}

int search_list(int *q)
{
	int flag=0;
	for(;first!=NULL;first=first->next)
	{
		(*q)++;
		if(first->value==5)
		{
			flag=1;
			return *q;   
			
			break;
		}
	}
	if(flag==0)
	{
		return -1;
	}
}
