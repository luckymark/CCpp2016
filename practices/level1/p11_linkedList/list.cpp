#include<stdio.h>
#include<stdlib.h>
struct List
{
	int No;
	int num;
	List *next;
};
struct List* createList(List *head, List *pn, int pNo, int pnum);
void showList(List *p);
struct List* turn(List *head,List *head1,List *p);
void findNum(List *head,int num);
int main()
{
	int No, num;
	List *p1, *p2;
	List *head, *head1;
	p1 = (List *)malloc(sizeof(List));
	p2 = (List *)malloc(sizeof(List));
	head = (List *)malloc(sizeof(List));
	head1 = (List *)malloc(sizeof(List));
	head->next = NULL;
	head1->next = NULL;
	while (1)
	{
		scanf("%d %d", &No, &num);
		if (No == 0)
		{
			break;
		}
		p1 = createList(head,p1, No, num);
	}
	showList(head);
	while (head->next != NULL)
	{
		p2 = turn(head, head1, p2);
	}
	findNum(head1, 5);
	free(p1);
	free(head1);
	free(head);
	system("pause");
}

List* createList(List *head, List *pn, int pNo, int pnum)
{
	List *p;
	p = (List *)malloc(sizeof(List));
	if (head->next == NULL)
	{
		pn = head;
		head->next = p;
		p->num = pnum;
		p->No = pNo;
		p->next = NULL;
	}
	else
	{
		pn->next = p;
		p->num = pnum;
		p->No = pNo;
		p->next = NULL;
	}
	return p;
}

void showList(List *head)
{
	List *p;
	for (p = head->next; p != NULL; p = p->next)
	{
		printf("%d %d\n", p->No, p->num);
	}
}

List* turn(List *head, List *head1, List *p)
{
	List  *deletep, *middle;
	p->next = (List *)malloc(sizeof(List));
	deletep = head;
	middle = deletep;
	for (; ; deletep = deletep->next)
	{
		
		if (deletep->next == NULL)
		{
			p = createList(head1, p, deletep->No, deletep->num);
			free(deletep);
			middle->next = NULL;
			break;
		}
		middle = deletep;
	}
	return p;
}

void findNum(List * head,int num)
{
	int flag = -1;
	List *p;
	for (p = head->next; p->num != num; p = p->next)
	{
		if (p->num == num)
		{
			flag = 1;
		}
	}
	if (flag)
	{
		printf("%d\n", p->No);
	}
	else
	{
		printf("%d\n", flag);
	}
}

