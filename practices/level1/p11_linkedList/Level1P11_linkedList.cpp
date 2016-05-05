// Level1P11_linkedList.cpp : Defines the entry point for the console application.
//

#include <stdlib.h>
#include <stdio.h>

struct node
{
	int num;
	int order;
	struct node *next;
};

int totalPointSum = 0;
struct node *head;
struct node *tail;
void showChoice();
void create();
void showValue();
void findFive();
void turnOrder();

void main() {
	head = NULL;
	showChoice();
}

void showChoice() {
	int choice;
	printf("====  ���������ѡ��:  ====\n<1.��������/��ӽڵ�>\t<2.��������>\n<3.��������>\t<4.����ֵΪ5>\t<5.�˳�>\n");
	scanf("%d", &choice);
	switch (choice)
	{
	case 1:
		create();
		break;
	case 2:
		showValue();
		break;
	case 3:
		turnOrder();
		break;
	case 4:
		findFive();
		break;
	case 5:
		break;
	default:
		printf("====  �����������������  ====\n");
		showChoice();
		break;
	}
}

void create() {
	struct node *p1;
	p1 = (struct node*)malloc(sizeof(struct node));
	printf("<�ڵ�%d�ĵ�ַ��%d>  ������ڵ�%d��ֵ��", ++totalPointSum, p1, totalPointSum);
	scanf("%d", &p1->num);
	p1->order = totalPointSum;
	p1->next = NULL;
	if (head != NULL)
	{
		tail->next = p1;
		tail = p1;
		printf("====  ��ӽڵ���ɣ��ַ��ز˵�  ====\n");
		showChoice();
	}
	else
	{
		head = p1;
		tail = p1;
		printf("====  ������ͷ��ɣ��ַ��ز˵�  ====\n");
		showChoice();
	}
}

void showValue() {
	struct node *temp;
	temp = head;
	printf("\n");
	while (temp != NULL)
	{
		printf("## �ڵ�%d��ֵΪ��\t%d\t##\n", temp->order, temp->num);
		temp = temp->next;
	}
	printf("\n");
	printf("====  �����ӡ����,�ַ��ز˵�  ====\n");
	showChoice();
}

void findFive() {
	struct node *temp;
	int findFlag = 0;
	temp = head;
	while (temp != NULL)
	{
		if (temp->num == 5) {
			printf("%d\n", temp->order);
			findFlag = 1;
			printf("====  �Ƿ����������һ��ֵΪ5�Ľڵ㣿1.��\t2.��  ====\n");
			int choice;
			scanf("%d", &choice);
			switch (choice)
			{
			case 1:
				findFlag = 0;
				break;
			case 2:
				showChoice();
				return;
				break;
			default:
				break;
			}
		}
		temp = temp->next;
	}
	if (!findFlag)
	{
		printf("%d\n", -1);
	}
	showChoice();
}

void turnOrder() {
	struct node *temp,*tempNext,*temp2,*temp3;
	temp = head;
	temp3 = head;
	tempNext = temp->next;
	temp2 = tempNext;
	head->next = NULL;
	while (tempNext != NULL)
	{
		tempNext = tempNext->next;
		temp2->next = temp;
		temp = temp2;
		temp2 = tempNext;
	}
	head = tail;
	tail = temp3;
	printf("====  ������ɣ��ַ��ز˵�  ====\n");
	showChoice();

}