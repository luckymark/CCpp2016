#include "linkedlist.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//��ʼ��ָ��
pItemNode _initializeList(void)
{
	pItemNode head;
	head = (pItemNode)malloc(sizeof(itemNode));
	//���ռ��Ƿ����
	if (head == NULL)
	{
		return head;
	}
	//��ʼ���ڵ�
	__initializeNode(head);
	//����ͷָ��
	return head;
}
//��ʼ���ڵ� ���ز���
pItemNode __initializeNode(pItemNode node)
{
	node->next = NULL;
	memset(node->item.itemName, 0, sizeof(node->item.itemName));
	memset(node->item.itemModel, 0, sizeof(node->item.itemModel));
	node->item.itemNumber = 0;
	return node;
}
//����ڵ㣨�»��
int _insertNodeFromStdin(const pItemNode head)
{
	_insertNodeFromFile(head, __getInfoFrom2TempNode());
	return 0;
}
//��ȡ��Ϣ
_item __getInfoFrom2TempNode(void)
{
	_item tempNode;
	printf("Please enter the Item's name:");
	scanf("%s", &tempNode.itemName);
	printf("\nPlease enter the Item's model:");
	scanf("%s", &tempNode.itemModel);
	printf("\nPlease enter the Item's number:");
	scanf("%d", &tempNode.itemNumber);
	//�Ե��س�
	while (getchar() != '\n');
	return tempNode;
}

//����ڵ㣨���ļ���
int _insertNodeFromFile(const pItemNode head, _item temp)
{
	pItemNode current = head;
	//�ҵ�β���ڵ�
	current = __bottomNode(head);
	//�����½ڵ�
	current->next = (pItemNode)malloc(sizeof(itemNode));
	if (current->next == NULL)
	{
		printf("ERROR : Fail in _insertNodeFromFile.\n");
		return 1;
	}
	//��ʼ���½ڵ�
	current = __initializeNode(current->next);
	//���Ƶ�Ŀ��ڵ�
	if (__copyNode(current, temp))
	{
		printf("ERROR : Fail in copyNode.\n");
		return 1;
	}
	return 0;
}
//���Ƶ�Ŀ��ڵ�
int __copyNode(pItemNode targetItemNode, _item temp)
{
	strcpy(targetItemNode->item.itemName, temp.itemName);
	strcpy(targetItemNode->item.itemModel, temp.itemModel);
	targetItemNode->item.itemNumber = temp.itemNumber;
	return 0;
}
//ɾ���ڵ� �ض��ڵ�
int _deleteNode(const pItemNode head, int numOfNode)
{
	pItemNode toDelete;
	//���Ŀ�����Ƿ����
	if ((toDelete = __isNodeExist(head, numOfNode)) == NULL)
	{
		printf("ERROR : Fail in delete the %d node.\n", numOfNode);
		return 1;
	}
	return _deleteNode(head, toDelete);
}
//ɾ���ڵ� β���ڵ�
int _deleteNode(const pItemNode head)
{
	pItemNode current = head;
	//�ж��Ƿ��нڵ�
	if (current->next == NULL)
	{
		printf("There isn't any node.\n");
		return 1;
	}
	//�ҵ����һ���ڵ�
	current = __bottomNode(head);
	return _deleteNode(head, current);
}
//ɾ���ڵ� ָ����ָ�ڵ�
int _deleteNode(const pItemNode head, pItemNode pItemNode2Delete)
{
	pItemNode current = head;
	//�ҵ�Ŀ��ڵ����һ���ڵ�
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
//���Ŀ�����Ƿ����
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
//���ҽڵ�
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
//Ӧ�ú���
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
//Ӧ�ú��� �ض��ڵ�
int _impleFunction(const pItemNode head, int(*impleFunc)(_item *impleItem), int numOfNode)
{
	return (*impleFunc)(&(__isNodeExist(head, numOfNode)->item));
}
//ɾ������
int _freeLinkedList(const pItemNode head)
{
	//ɾ�����еĽڵ�
	while (head->next != NULL)
	{
		_deleteNode(head);
	}
	//ɾ��ͷ�ڵ�
	free(head);
	return 0;
}
//����β���ڵ�ָ��
pItemNode __bottomNode(const pItemNode head)
{
	pItemNode current = head;
	while (current->next != NULL)
	{
		current = current->next;
	}
	return current;
}