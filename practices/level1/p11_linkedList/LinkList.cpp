// LinkList.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>

struct data
{
	int value;
	data *next;
};

data *List = NULL, *head = NULL, *tail = NULL;

void build(int i, int val);
void print(data* head);
void search(data* head);

int main()
{
	int n,val;
	scanf_s("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf_s("%d", &val);
		build(i, val);
	}
	printf("\n");
	printf("正序：");
	print(head);
	printf("反序：");
	print(head);
	search(head);

	system("pause");
    return 0;
}

void build(int i, int val)
{
	if (i == 1)
	{
		List = (data *)malloc(sizeof(data));
		List->value = val;
		tail = List;
		head = tail;
	}
	else
	{
		List = (data *)malloc(sizeof(data));
		List->next = NULL;
		List->value = val;
		tail->next = List;
		tail = List;
	}
}

void print(data *t)
{
	data *m=NULL,*next;
	while (t != NULL)
	{
		next = t->next;
		t->next = m;
		m = t;
		printf("%d ", t->value);
		head = t;
		t = next;
	}
	printf("\n");
}

void search(data* t)
{
	int tot = 0, flag = 0;;
	for (; t != NULL; t = t->next)
	{
		tot++;
		if (t->value == 5)
		{
			flag++;
			printf("第%d个5的序号为%d\n", flag,tot);
			if (flag==2) break;
		}
	}
	for (; flag < 2; flag++)
		printf("第%d个5的序号为-1\n", flag+1);
}

