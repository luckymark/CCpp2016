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
	printf("====  请输入你的选择:  ====\n<1.创建链表/添加节点>\t<2.遍历链表>\n<3.反序链表>\t<4.查找值为5>\t<5.退出>\n");
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
		printf("====  输入错误，请重新输入  ====\n");
		showChoice();
		break;
	}
}

void create() {
	struct node *p1;
	p1 = (struct node*)malloc(sizeof(struct node));
	printf("<节点%d的地址：%d>  请输入节点%d的值：", ++totalPointSum, p1, totalPointSum);
	scanf("%d", &p1->num);
	p1->order = totalPointSum;
	p1->next = NULL;
	if (head != NULL)
	{
		tail->next = p1;
		tail = p1;
		printf("====  添加节点完成，现返回菜单  ====\n");
		showChoice();
	}
	else
	{
		head = p1;
		tail = p1;
		printf("====  创建表头完成，现返回菜单  ====\n");
		showChoice();
	}
}

void showValue() {
	struct node *temp;
	temp = head;
	printf("\n");
	while (temp != NULL)
	{
		printf("## 节点%d的值为：\t%d\t##\n", temp->order, temp->num);
		temp = temp->next;
	}
	printf("\n");
	printf("====  链表打印结束,现返回菜单  ====\n");
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
			printf("====  是否继续查找下一个值为5的节点？1.是\t2.否  ====\n");
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
	printf("====  反序完成，现返回菜单  ====\n");
	showChoice();

}