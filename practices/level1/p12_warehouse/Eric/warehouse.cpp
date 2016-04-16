/*
warehouse.c
author: Eric
date:2016-03-17
*/

#include "warehouse.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void fstartWarehouse(void)
{
	//��ʼ������
	const pItemNode head = _initializeList();
	if (!head)
	{
		printf("ERROR: fail in initialization.\n");
		return;
	}
	//������¼�ļ�
	if (_operateRecordFile(head))
	{
		printf("ERROR: fail in operate record files.\n");
		return;
	}
	//ѭ��
	char order;
	do
	{
		//չʾ����ѡ��
		_showCommandList();
		//���ܺ���������
		scanf("%c", &order);
		//�Իس�
		while (getchar() != '\n');
		_startFunction(order, head);
		//�����¼
		if (_saveRecordFile(head))
		{
			printf("ERROR : Fail in save record file.\n");
			return;
		}
	} while (order != 'q');
}
//չʾ����ѡ��
void _showCommandList(void)
{
	printf("a.show item list\nb.import item\nc.export item\nq.quit\nCOMMAND:");
}
//���ܺ���������
void _startFunction(char order, const pItemNode head)
{
	switch (order)
	{
	case 'a':
	case 'A':
		_showItemList(head);
		break;
	case 'b':
	case 'B':
		_importItem(head);
		break;
	case 'c':
	case 'C':
		_exportItem(head);
		break;
	case 'q':
	case 'Q':
	case 'd':
	case 'D':
		return;
	default:
		printf("ERROR : Wrong command\n");
		break;
	}
}
//�����¼�ļ� ���� ���� �½�
int _operateRecordFile(const pItemNode head)
{
	FILE *record = fopen(RECORD_FILE_NAME, "r");
	//�޼�¼�ļ������
	if (record == NULL)
	{
		record = fopen(RECORD_FILE_NAME, "w");
		//��鴴���ļ��Ƿ�ɹ�
		if (record == NULL)
		{
			printf("ERROR : Fail to create the record file.\n");
			return 1;
		}
		fclose(record);
		return 0;
	}
	//�ر��ļ�ָ��
	fclose(record);
	//���ڼ�¼�ļ������
	if (__reloadRecordFile(head))
	{
		printf("ERROR : Fail in reload record file\n");
		return 1;
	}
	return 0;
}
//���ļ����ؼ�¼
int __reloadRecordFile(const pItemNode head)
{
	FILE *record = fopen(RECORD_FILE_NAME, "r");
	_item inputItemNode;
	while (fscanf(record, "%s", &inputItemNode.itemName) == 1)
	{
		fscanf(record, "%s", &inputItemNode.itemModel);
		fscanf(record, "%d", &inputItemNode.itemNumber);
		if (_insertNodeFromFile(head, inputItemNode))
		{
			return 1;
		}
	}
	return 0;
}
//���浽�ļ�
int _saveRecordFile(const pItemNode head)
{
	FILE *record;
	record = fopen(RECORD_FILE_NAME, "w");
	if (record == NULL)
	{
		printf("ERROR : Fail to open the file when saving.\n");
		return 1;
	}
	else
	{
		//�ر��ļ�
		fclose(record);
		//������ļ�
		_impleFunction(head, __outputNode2File);
	}
	return 0;
}
//����ڵ㵽�ļ�
int __outputNode2File(_item *impleItem)
{
	FILE *record;
	//���ļ�
	record = fopen(RECORD_FILE_NAME, "a+");
	//��λ��β��
	fseek(record, 0, SEEK_END);
	//���
	fprintf(record, "%s %s %d\n", impleItem->itemName, impleItem->itemModel, impleItem->itemNumber);
	//�ر��ļ�
	fclose(record);
	return 0;
}
//===========================================���ܺ���====================================
//չʾ�����б�
void _showItemList(const pItemNode head)
{
	_impleFunction(head, &__showItemList);
	printf("============END============\n");
}
//���������Ϣ��stdout
int __showItemList(_item *item)
{
	printf("%40s %40s %10d\n", item->itemName, item->itemModel, item->itemNumber);
	return 0;
}
//����
void _importItem(const pItemNode head)
{
	_insertNodeFromStdin(head);
	//�鿴�Ƿ�Ϊ���еĻ���
	int countNode = -1;
	if ((countNode = _findNode(head, &__compFuncImport, __bottomNode(head)->item)) != 0)
	{
		//�ų�����ӵĻ���
		if (__isNodeExist(head, countNode) != __bottomNode(head))
		{
			__bottomNode(head)->item.itemNumber += _impleFunction(head, &__returnItemNumber, countNode);
			_deleteNode(head, countNode);
		}
	}
	printf("Successfully import.\n");
}
//����ȽϺ���
int __compFuncImport(_item comItem1, _item comItem2)
{
	if (!strcmp(comItem1.itemName, comItem2.itemName) && !strcmp(comItem1.itemModel, comItem2.itemModel))
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
//����ϲ��ڵ�
int __returnItemNumber(_item *impleItem)
{
	return impleItem->itemNumber;
}
//����
void _exportItem(const pItemNode head)
{
	int countNode;
	_item tempItem = __getInfoFrom2TempNode();
	if (countNode = _findNode(head, &__compFuncExport, tempItem))
	{
		//��������
		if ((__isNodeExist(head, countNode)->item.itemNumber -= tempItem.itemNumber) == 0)
		{
			//�����������Ϊ0 ɾ����¼
			_deleteNode(head, countNode);
		}
		printf("Export successed!\n");
	}
	else
	{
		//���ܳ�������
		printf("ERROR : The item isn't exist or the number is not enough.\n");
	}
}
//����ȽϺ���
int __compFuncExport(_item comItem1, _item comItem2)
{
	//ƥ�����
	if (!strcmp(comItem1.itemName, comItem2.itemName) && !strcmp(comItem1.itemModel, comItem2.itemModel))
	{
		//�Ƚϻ�������
		if (comItem1.itemNumber <= comItem2.itemNumber)
		{
			return 1;
		}
	}
	return 0;
}