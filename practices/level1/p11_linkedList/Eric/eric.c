//Eric
//linkedList

#include <stdio.h>
#include <stdlib.h>
#include "linkedList.h"

int showNode(item toImple, int numOfNode);
int showFive(item toImple, int numOfNode);
int show2Five(item toImple, int numOfNode);
//判断并输出5
int main(void)
{
	//初始化空列表
	pItemNode head = finitialize();
	//载入数据 9个 在in.txt 这只是测试
	//输出在out.txt
	//freopen("in.txt", "r", stdin);
	for (int count = 1; count < 10; count++)
	{
		finsertNode(head, 0);
	}

	//freopen("out.txt", "w", stdout);
	//遍历第一次 输出值
	printf("To show value\n");
	fimplementFunc(head, (*showNode));
	//颠倒链表 并输出值
	freverseLinkedList(head);
	printf("To show the vaule after reversed\n");
	fimplementFunc(head, (*showNode));

	//输出第一个 5
	printf("The first 5\n");
	if (fimplementFunc(head, (*showFive)))
	{
		printf("-1");
	}
	//第二个5
	printf("\nThe second 5\n");
	if (fimplementFunc(head, (*show2Five)))
	{
		printf("-1");
	}

	//释放列表
	fcloseTheList(head);

	system("pause");
	return 0;
}
int showNode(item toImple, int numOfNode)
{
	printf("%d\n", toImple.itemNumber);
	return 0;
}
int showFive(item toImple, int numOfNode)
{
	if (toImple.itemNumber == 5)
	{
		printf("No.%d\n", numOfNode);
		return 1;
	}
	return 0;
}
int show2Five(item toImple, int numOfNode)
{
	static fiveCount = 0;
	if (toImple.itemNumber == 5)
	{
		fiveCount++;
		if (fiveCount == 2)
		{
			printf("No.%d\n", numOfNode);
			return 1;
		}
	}
	return 0;
}