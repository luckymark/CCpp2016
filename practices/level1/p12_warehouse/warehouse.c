#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linkedList.h"
#include "warehouse.h"
void fstartWareHouse(void)
{
	pItemNode head;
	//初始化列表
	head = finitialize();
	//检查文件及加载或创建
	if (_checkIsFileExist())
	{
		_loadRecord(head);
	}
	else
	{
		_createRecordFile();
	}
	//正式启动
	while (_getCommandAndImplement(head))
	{
		_saveRecord(head);
	}
	printf("\n\nDone!");
}
int _checkIsFileExist(void)
{
	FILE *tempRecordName;
	tempRecordName = fopen("record.db", "r");
	if (tempRecordName == NULL)
	{
		return 0;
	}
	else
	{
		fclose(tempRecordName);
		return 1;
	}
}
int _createRecordFile(void)
{
	FILE *tempRecordName;
	tempRecordName = fopen("record.db", "w");
	if (tempRecordName == NULL)
	{
		return 0;
	}
	else
	{
		fclose(tempRecordName);
		return 1;
	}
}
int _loadRecord(pItemNode head)
{
	FILE *recordFile;
	recordFile = fopen("record.db", "r");
	//检查记录文件打开是否正常
	if (recordFile == NULL)
	{
		fprintf(stderr, "Read record Error.");
		return 0;
	}
	//开始加载
	item tempItem;
	while (fgets(tempItem.itemNames, CHARLENGTH - 1, recordFile))
	{
		fgets(tempItem.itemModel, CHARLENGTH - 1, recordFile);
		fscanf(recordFile, "%d", &tempItem.itemNumber);
		tempItem.itemNames[strlen(tempItem.itemNames) - 1] = '\0';
		tempItem.itemModel[strlen(tempItem.itemModel) - 1] = '\0';
		while (fgetc(recordFile) != '\n');
		finsertNode(head, 0, 1, &tempItem);
	}
	//关闭文件
	fclose(recordFile);
	return 1;
}
int _saveRecord(pItemNode head)
{
	FILE *recordFile;
	recordFile = fopen("record.db", "w");
	//判断文件是否正常
	if (recordFile == NULL)
	{
		printf("Error: Save Record Error.\n");
		return 0;
	}
	fclose(recordFile);
	//保存
	fimplementFunc(head, (&__saveRecordOutput));
	return 1;
}
int __saveRecordOutput(item toImple)
{
	FILE *recordFile;
	recordFile = fopen("record.db", "a+");
	fseek(recordFile, 0, SEEK_END);
	fputs(toImple.itemNames, recordFile);
	fprintf(recordFile, "\n");
	fputs(toImple.itemModel, recordFile);
	fprintf(recordFile, "\n");
	fprintf(recordFile, "%d\n", toImple.itemNumber);
	fclose(recordFile);
	return 0;
}
void _showCommandList(void)
{
	printf("a.Show item list\nb.Add Item\nc.出货\nd.exit\nEnter: ");
}
int _getCommandAndImplement(pItemNode head)
{
	_showCommandList();
	char tempOrder[40] = { '\0' };
	fgets(tempOrder, 39, stdin);
	switch (tempOrder[0])
	{
	case 'a':
		_showItemList(head);
		break;
	case 'b':
		_addItem(head);
		break;
	case 'c':
		_outItem(head);
		break;
	case 'd':
		//结束程序y
		return 0;
	default:
		printf("Error : Wrong command.\n");
		break;
	}
	//继续程序
	return 1;
}
int _showItemList(pItemNode head)
{
	fimplementFunc(head, &__showItem);
	printf("That's all record.\n");
	return 1;
}
int __showItem(item toImple)
{
	//printf("%-20s | %-20s | %10d\n", toImple.itemNames, toImple.itemModel, toImple.itemNumber);
	printf("%-40s | %-40s | %10d\n", toImple.itemNames, toImple.itemModel, toImple.itemNumber);
	return 0;
}
int _addItem(pItemNode head)
{
	pItemNode tempNode = _getInfo2Node(_setupNewItem(), 0, NULL);
	switch (__checkIsItemRecord(head, tempNode->itemExample))
	{
	case 1:
		__addItemExist(head, tempNode);
		break;
	case 0:
		__addItemUnexist(head, tempNode);
		break;
	default:
		printf("Error: Add Item Wrong");
		free(tempNode);
		return 0;
	}
	printf("success\n");
	free(tempNode);
	return 1;
}
int __addItemExist(pItemNode head, pItemNode tempNode)
{
	tempNode->itemExample.itemNumber +=
		fshowNoItem(head, ffindNode(head, tempNode->itemExample)).itemNumber;
	finsertNode(head, 0, 1, &(tempNode->itemExample));
	fdeleteNode(head, ffindNode(head, tempNode->itemExample));
	return 1;
}
int __addItemUnexist(pItemNode head, pItemNode tempNode)
{
	if (finsertNode(head, 0, 1, &(tempNode->itemExample)))
	{
		return 1;
	}
	//错误返回0
	return 0;
}
int _outItem(pItemNode head)
{
	printf("Please input the item you want to out\n");
	pItemNode tempNode = _getInfo2Node(_setupNewItem(), 0, NULL);
	if (__checkIsItemRecord(head, tempNode->itemExample))
	{
		if (__outItemNumIsEnough(head, tempNode->itemExample))
		{
			tempNode->itemExample.itemNumber =
				fshowNoItem(head, ffindNode(head, tempNode->itemExample)).itemNumber
				- tempNode->itemExample.itemNumber;
			//删除货物数量为0的时候的记录
			if (tempNode->itemExample.itemNumber)
			{
				finsertNode(head, 0, 1, &(tempNode->itemExample));
			}
			fdeleteNode(head, ffindNode(head, tempNode->itemExample));
			//释放tempNode
			free(tempNode);
			printf("出货成功\n");
			return 1;
		}
		else
		{
			printf("货物数量不足\n");
		}
	}
	else
	{
		printf("The item is not exist\n");
	}
	//释放tempNode
	free(tempNode);
	return 0;
}
int __checkIsItemRecord(pItemNode head, item toCompare)
{
	return ffindNode(head, toCompare);
}
int __outItemNumIsEnough(pItemNode head, item toCheck)
{
	if (toCheck.itemNumber <= fshowNoItem(head, ffindNode(head, toCheck)).itemNumber)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}