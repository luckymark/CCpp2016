// ConsoleApplication46.cpp : 定义控制台应用程序的入口点。
#include"stdafx.h"
#include<stdio.h>
#include<stdlib.h>
#define NULL 0
#define LEN sizeof(list)
typedef struct list {
	int num;
	list *next;
};
list *create(void);
void turn(void);
void ergodic(list *p3);//遍历
list *turn(list *p4);
void ergodicchcek(list *p3);
int searchfive(list *p3);
int searchsecondfive(list *p3);



int main()
{
	list *ps;
	ps = create();
	ergodic(ps);
	ps = turn(ps);
	ergodic(ps);
	ps = turn(ps);
	printf("%d ", searchfive(ps));//输出的是反序后的节点
	printf("%d", searchsecondfive(ps));
	return 0;
}




list *create(void)//* list
{
	int n = 0;
	list *p1, *p2, *p3, *head;
	p1 = p2 = p3 = head = NULL;
	p1 = (list*)malloc(LEN);
	scanf("%d", &p1->num);
	while (p1->num != 0) {
		n++;
		if (n == 1) {
			head = p1;
			p2 = p1;
			p2->next = NULL;
		}
		else
			p2->next = p1;
		p2 = p1;
		p1 = (list*)malloc(LEN);
		scanf("%d", &p1->num);
	}
	p2->next = NULL;
	free(p1);
	p3 = head;
	return p3;
}



void ergodic(list *p3)
{

	for (;;) {
		if (p3->next == NULL) {
			printf("%d ", p3->num);
			break;
		}
		else {
			printf("%d ", p3->num);
			p3 = p3->next;
		}
	}
	printf("\n");
}
list *turn(list *p4) {
	list *pNextsave, *pNow, *pNext, *presult;

	int swit = 0;
	pNext = pNextsave = pNow = pNext = presult = NULL;
	if (p4->next == NULL)
		return p4;
	if (((p4->next)->next) == NULL) {
		pNext = p4->next;
		pNext->next = p4;
		p4->next = NULL;
		return pNext;
	}

	pNow = p4;
	pNext = p4->next;
	do
	{
		if (swit != 1)
			swit = 1;
		else {
			pNow = pNext;//继承
			pNext = pNextsave;
		}
		pNextsave = pNext->next;
		pNext->next = pNow;
	} while (pNextsave->next != NULL);
	pNextsave->next = pNext;
	p4->next = NULL;
	return pNextsave;

}

void ergodicchcek(list *p3)//最后删除
{

	for (;;) {
		if (p3->next == NULL) {
			printf("%o %o\n", p3, p3->next);
			break;
		}
		else {
			printf("%o %o\n", p3, p3->next);
			p3 = p3->next;
		}
	}

}

int searchfive(list *p3) {
	int n = 0;
	for (;;) {
		n++;
		if (p3->num == 5)
			return n;
		else if (p3->next == NULL)
			return -1;
		else p3 = p3->next;
	}
}

int searchsecondfive(list *p3) {
	int n = searchfive(p3);
	if (n == -1)
		return -1;
	else {
		for (int j = 1; j <= n; j++) {
			if (p3->next == NULL)
				return -1;
			else
				p3 = p3->next;
		}
		for (;;) {
			n++;
			if (p3->num == 5)
				return n;
			else if (p3->next == NULL)
				return -1;
			else p3 = p3->next;
		}
	}
}