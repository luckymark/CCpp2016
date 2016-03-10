//by Eric linkedList.c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linkedList.h"
pItemNode _setupNewItem(void);
//建立空节点所有值设为0或/0 成功返回地址 失败返回NULL
pItemNode _getInfo2Node(pItemNode targetNode);
//获取信息写入节点 setup a new Node return NULL when fail
pItemNode _checkIsNode(pItemNode head, int num2check);
//检查节点是否存在 num2check = 0 返回尾部节点的地址
//return pointer when the item exist, return NULL when unexist
pItemNode _IsBottomForReverse(pItemNode head);
//返回尾部节点前一个节点的位置
pItemNode finitialize(void)
{
	pItemNode newHead = _setupNewItem();
	return newHead;
}

int finsertNode(pItemNode head, int num2insert)
{
	switch (num2insert)
	{
	case 0:
	{
		pItemNode pBottomNode = _checkIsNode(head, num2insert);
		if (pBottomNode != NULL)
		{
			pBottomNode->next = _getInfo2Node((_setupNewItem()));
			return 1;
		}
		break;
	}

	default:
	{
		pItemNode pUpNode = _checkIsNode(head, num2insert - 1);
		//返回上一个的指针
		if (pUpNode != NULL)
		{
			pItemNode tempNextNode = pUpNode->next;
			pUpNode->next = _getInfo2Node(_setupNewItem());
			//链接链表
			pUpNode = pUpNode->next;
			pUpNode->next = tempNextNode;
			return 1;
		}
	}
	}

	return 0;
}

int fdeleteNode(pItemNode head, int num2delete)
{
	if (_checkIsNode(head, num2delete))
	{
		pItemNode pUpNode, pDeNode;
		pUpNode = _checkIsNode(head, num2delete - 1);
		pDeNode = pUpNode->next;
		//获取待删除节点和上游节点的地址
		pUpNode->next = pDeNode->next;
		//踢出待删除节点
		free(pDeNode);
		//删除节点
		return 1;
	}
	return 0;
}

int fimplementFunc(pItemNode head, int(*impleFunc)(item toImple, int numOfNode))
{
	pItemNode pCurrentNode = head;
	int numOfNode = 1;
	while (pCurrentNode->next != NULL)
	{
		pCurrentNode = pCurrentNode->next;
		if ((*impleFunc)(pCurrentNode->itemExample, numOfNode))
			//如果调用的函数返回0 则中断执行
		{
			return 0;
		}
		++numOfNode;
	}
	return 1;
}

int freverseLinkedList(pItemNode head)
{
	pItemNode ptempHeadNode;
	ptempHeadNode = head->next;
	if (ptempHeadNode == NULL)
	{
		return 0;
	}
	else
	{
		while (_IsBottomForReverse(ptempHeadNode))
		{
			head->next = _IsBottomForReverse(ptempHeadNode)->next;
			_IsBottomForReverse(ptempHeadNode)->next = NULL;
			head = head->next;
		}
		//最后一个节点
		head->next = ptempHeadNode;
	}
	return 0;
}

int fcloseTheList(pItemNode head)
{
	while (head->next != NULL)
	{
		pItemNode pCurrentNode = _IsBottomForReverse(head);
		free(pCurrentNode->next);
		pCurrentNode->next = NULL;
	}
	free(head);
	return 1;
}

//链表内部函数
pItemNode _setupNewItem(void)
{
	pItemNode newNode = (pItemNode)malloc(sizeof(itemNode));
	//设置数据为空
	memset(newNode->itemExample.itemNames, 0, sizeof(newNode->itemExample.itemNames));
	memset(newNode->itemExample.itemModel, 0, sizeof(newNode->itemExample.itemModel));
	newNode->itemExample.itemNumber = 0;
	newNode->next = NULL;

	return newNode;
}

pItemNode _getInfo2Node(pItemNode targetNode)
{
	printf("Please Enter the name of item(%d or less):", CHARLENGTH);
	fgets(targetNode->itemExample.itemNames, CHARLENGTH - 1, stdin);
	printf("\nPlease Enter the model of item(%d or less):", CHARLENGTH);
	fgets(targetNode->itemExample.itemModel, CHARLENGTH - 1, stdin);
	printf("\nPlease Enter the count of item:");
	fscanf(stdin, "%d", &targetNode->itemExample.itemNumber);
	printf("\n");	//看起来更漂亮：-）
	while (getchar() != '\n');
	return targetNode;
}

pItemNode _checkIsNode(pItemNode head, int num2check)
{
	pItemNode pCurrentNode = head;
	for (int count = 1; (num2check == 0 && pCurrentNode->next != NULL)
		|| (count < num2check && pCurrentNode->next != NULL); count++)
	{
		pCurrentNode = pCurrentNode->next;
	}

	switch (num2check)
	{
	case 0:
		return pCurrentNode;
	default:
		return pCurrentNode->next;
	}
}

pItemNode _IsBottomForReverse(pItemNode head)
{
	pItemNode pCurrentNode;
	pCurrentNode = head;
	if (pCurrentNode->next == NULL)
	{
		return NULL;
	}
	while (pCurrentNode->next->next != NULL)
	{
		pCurrentNode = pCurrentNode->next;
	}
	return pCurrentNode;
}