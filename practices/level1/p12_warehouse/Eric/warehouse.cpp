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
	//初始化链表
	const pItemNode head = _initializeList();
	if (!head)
	{
		printf("ERROR: fail in initialization.\n");
		return;
	}
	//操作记录文件
	if (_operateRecordFile(head))
	{
		printf("ERROR: fail in operate record files.\n");
		return;
	}
	//循环
	char order;
	do
	{
		//展示命令选单
		_showCommandList();
		//功能函数启动器
		scanf("%c", &order);
		//吃回车
		while (getchar() != '\n');
		_startFunction(order, head);
		//保存记录
		if (_saveRecordFile(head))
		{
			printf("ERROR : Fail in save record file.\n");
			return;
		}
	} while (order != 'q');
}
//展示命令选单
void _showCommandList(void)
{
	printf("a.show item list\nb.import item\nc.export item\nq.quit\nCOMMAND:");
}
//功能函数启动器
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
//处理记录文件 加载 或者 新建
int _operateRecordFile(const pItemNode head)
{
	FILE *record = fopen(RECORD_FILE_NAME, "r");
	//无记录文件的情况
	if (record == NULL)
	{
		record = fopen(RECORD_FILE_NAME, "w");
		//检查创建文件是否成功
		if (record == NULL)
		{
			printf("ERROR : Fail to create the record file.\n");
			return 1;
		}
		fclose(record);
		return 0;
	}
	//关闭文件指针
	fclose(record);
	//存在记录文件的情况
	if (__reloadRecordFile(head))
	{
		printf("ERROR : Fail in reload record file\n");
		return 1;
	}
	return 0;
}
//从文件加载记录
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
//保存到文件
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
		//关闭文件
		fclose(record);
		//输出到文件
		_impleFunction(head, __outputNode2File);
	}
	return 0;
}
//输出节点到文件
int __outputNode2File(_item *impleItem)
{
	FILE *record;
	//打开文件
	record = fopen(RECORD_FILE_NAME, "a+");
	//定位到尾部
	fseek(record, 0, SEEK_END);
	//输出
	fprintf(record, "%s %s %d\n", impleItem->itemName, impleItem->itemModel, impleItem->itemNumber);
	//关闭文件
	fclose(record);
	return 0;
}
//===========================================功能函数====================================
//展示货物列表
void _showItemList(const pItemNode head)
{
	_impleFunction(head, &__showItemList);
	printf("============END============\n");
}
//输出货物信息到stdout
int __showItemList(_item *item)
{
	printf("%40s %40s %10d\n", item->itemName, item->itemModel, item->itemNumber);
	return 0;
}
//进库
void _importItem(const pItemNode head)
{
	_insertNodeFromStdin(head);
	//查看是否为已有的货物
	int countNode = -1;
	if ((countNode = _findNode(head, &__compFuncImport, __bottomNode(head)->item)) != 0)
	{
		//排除新添加的货物
		if (__isNodeExist(head, countNode) != __bottomNode(head))
		{
			__bottomNode(head)->item.itemNumber += _impleFunction(head, &__returnItemNumber, countNode);
			_deleteNode(head, countNode);
		}
	}
	printf("Successfully import.\n");
}
//进库比较函数
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
//进库合并节点
int __returnItemNumber(_item *impleItem)
{
	return impleItem->itemNumber;
}
//出库
void _exportItem(const pItemNode head)
{
	int countNode;
	_item tempItem = __getInfoFrom2TempNode();
	if (countNode = _findNode(head, &__compFuncExport, tempItem))
	{
		//正常出库
		if ((__isNodeExist(head, countNode)->item.itemNumber -= tempItem.itemNumber) == 0)
		{
			//如果货物数量为0 删除记录
			_deleteNode(head, countNode);
		}
		printf("Export successed!\n");
	}
	else
	{
		//不能出库的情况
		printf("ERROR : The item isn't exist or the number is not enough.\n");
	}
}
//出库比较函数
int __compFuncExport(_item comItem1, _item comItem2)
{
	//匹配货物
	if (!strcmp(comItem1.itemName, comItem2.itemName) && !strcmp(comItem1.itemModel, comItem2.itemModel))
	{
		//比较货物数量
		if (comItem1.itemNumber <= comItem2.itemNumber)
		{
			return 1;
		}
	}
	return 0;
}