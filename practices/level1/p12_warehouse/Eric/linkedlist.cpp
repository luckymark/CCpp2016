#include "linkedlist.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//初始化指针
pItemNode _initializeList(void)
{
	pItemNode head;
	head = (pItemNode)malloc(sizeof(itemNode));
	//检查空间是否分配
	if (head == NULL)
	{
		return head;
	}
	//初始化节点
	__initializeNode(head);
	//返回头指针
	return head;
}
//初始化节点 返回参数
pItemNode __initializeNode(pItemNode node)
{
	node->next = NULL;
	memset(node->item.itemName, 0, sizeof(node->item.itemName));
	memset(node->item.itemModel, 0, sizeof(node->item.itemModel));
	node->item.itemNumber = 0;
	return node;
}
//插入节点（新货物）
int _insertNodeFromStdin(const pItemNode head)
{
	_insertNodeFromFile(head, __getInfoFrom2TempNode());
	return 0;
}
//获取信息
_item __getInfoFrom2TempNode(void)
{
	_item tempNode;
	printf("Please enter the Item's name:");
	scanf("%s", &tempNode.itemName);
	printf("\nPlease enter the Item's model:");
	scanf("%s", &tempNode.itemModel);
	printf("\nPlease enter the Item's number:");
	scanf("%d", &tempNode.itemNumber);
	//吃掉回车
	while (getchar() != '\n');
	return tempNode;
}

//插入节点（从文件）
int _insertNodeFromFile(const pItemNode head, _item temp)
{
	pItemNode current = head;
	//找到尾部节点
	current = __bottomNode(head);
	//创立新节点
	current->next = (pItemNode)malloc(sizeof(itemNode));
	if (current->next == NULL)
	{
		printf("ERROR : Fail in _insertNodeFromFile.\n");
		return 1;
	}
	//初始化新节点
	current = __initializeNode(current->next);
	//复制到目标节点
	if (__copyNode(current, temp))
	{
		printf("ERROR : Fail in copyNode.\n");
		return 1;
	}
	return 0;
}
//复制到目标节点
int __copyNode(pItemNode targetItemNode, _item temp)
{
	strcpy(targetItemNode->item.itemName, temp.itemName);
	strcpy(targetItemNode->item.itemModel, temp.itemModel);
	targetItemNode->item.itemNumber = temp.itemNumber;
	return 0;
}
//删除节点 特定节点
int _deleteNode(const pItemNode head, int numOfNode)
{
	pItemNode toDelete;
	//检查目标结点是否存在
	if ((toDelete = __isNodeExist(head, numOfNode)) == NULL)
	{
		printf("ERROR : Fail in delete the %d node.\n", numOfNode);
		return 1;
	}
	return _deleteNode(head, toDelete);
}
//删除节点 尾部节点
int _deleteNode(const pItemNode head)
{
	pItemNode current = head;
	//判断是否有节点
	if (current->next == NULL)
	{
		printf("There isn't any node.\n");
		return 1;
	}
	//找到最后一个节点
	current = __bottomNode(head);
	return _deleteNode(head, current);
}
//删除节点 指针所指节点
int _deleteNode(const pItemNode head, pItemNode pItemNode2Delete)
{
	pItemNode current = head;
	//找到目标节点的上一个节点
	while (current->next != pItemNode2Delete)
	{
		if (current->next == NULL)
		{
			printf("ERROR : Fail in find the node.\n");
			return 1;
		}
		current = current->next;
	}
	current->next = pItemNode2Delete->next;
	free(pItemNode2Delete);
	return 0;
}
//检查目标结点是否存在
pItemNode __isNodeExist(const pItemNode head, int numOfNode)
{
	pItemNode current = head;
	for (int nodeCount = 0; nodeCount < numOfNode; nodeCount++)
	{
		if (current->next != NULL)
		{
			current = current->next;
		}
		else
		{
			return NULL;
		}
	}
	return current;
}
//查找节点
int _findNode(const pItemNode head, int(*compFunc)(_item comItem1, _item comItem2), _item comItem1)
{
	pItemNode current = head;
	for (int countNode = 0; current != NULL; current = current->next)
	{
		if ((*compFunc)(comItem1, current->item))
		{
			return countNode;
		}
		countNode++;
	}
	return 0;
}
//应用函数
int _impleFunction(const pItemNode head, int(*impleFunc)(_item *impleItem))
{
	pItemNode current = head->next;
	while (current != NULL)
	{
		(impleFunc(&(current->item)));
		current = current->next;
	}
	return 0;
}
//应用函数 特定节点
int _impleFunction(const pItemNode head, int(*impleFunc)(_item *impleItem), int numOfNode)
{
	return (*impleFunc)(&(__isNodeExist(head, numOfNode)->item));
}
//删除链表
int _freeLinkedList(const pItemNode head)
{
	//删除所有的节点
	while (head->next != NULL)
	{
		_deleteNode(head);
	}
	//删除头节点
	free(head);
	return 0;
}
//返回尾部节点指针
pItemNode __bottomNode(const pItemNode head)
{
	pItemNode current = head;
	while (current->next != NULL)
	{
		current = current->next;
	}
	return current;
}