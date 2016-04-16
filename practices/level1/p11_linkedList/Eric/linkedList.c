//by Eric linkedList.c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linkedList.h"
pItemNode _setupNewItem(void);
//�����սڵ�����ֵ��Ϊ0��/0 �ɹ����ص�ַ ʧ�ܷ���NULL
pItemNode _getInfo2Node(pItemNode targetNode);
//��ȡ��Ϣд��ڵ� setup a new Node return NULL when fail
pItemNode _checkIsNode(pItemNode head, int num2check);
//���ڵ��Ƿ���� num2check = 0 ����β���ڵ�ĵ�ַ
//return pointer when the item exist, return NULL when unexist
pItemNode _IsBottomForReverse(pItemNode head);
//����β���ڵ�ǰһ���ڵ��λ��
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
		//������һ����ָ��
		if (pUpNode != NULL)
		{
			pItemNode tempNextNode = pUpNode->next;
			pUpNode->next = _getInfo2Node(_setupNewItem());
			//��������
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
		//��ȡ��ɾ���ڵ�����νڵ�ĵ�ַ
		pUpNode->next = pDeNode->next;
		//�߳���ɾ���ڵ�
		free(pDeNode);
		//ɾ���ڵ�
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
			//������õĺ�������0 ���ж�ִ��
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
		//���һ���ڵ�
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

//�����ڲ�����
pItemNode _setupNewItem(void)
{
	pItemNode newNode = (pItemNode)malloc(sizeof(itemNode));
	//��������Ϊ��
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
	printf("\n");	//��������Ư����-��
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