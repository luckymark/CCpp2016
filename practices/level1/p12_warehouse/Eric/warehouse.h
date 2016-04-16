/*
warehouse.h v2.0
author:Eric
date 2016-03-17
*/
#ifndef _WAREHOUSE_H
#define _WAREHOUSE_H

#include "linkedlist.h"

//�ļ���
#define RECORD_FILE_NAME "recode.db"

//������
void fstartWarehouse(void);

//==========================================������===================================
//�����¼�ļ� ���� ���� �½�
int _operateRecordFile(const pItemNode head);
//���ļ����ؼ�¼
int __reloadRecordFile(const pItemNode head);
//���浽�ļ�
int _saveRecordFile(const pItemNode head);
//����ڵ㵽�ļ�
int __outputNode2File(_item *impleItem);
//չʾ����ѡ��
void _showCommandList(void);
//���ܺ���������
void _startFunction(char order, const pItemNode head);

//========================================���ܺ���=====================================
//չʾ�����б�
void _showItemList(const pItemNode head);
//���������Ϣ��stdout
int __showItemList(_item *item);
//����
void _importItem(const pItemNode head);
//����ȽϺ���
int __compFuncImport(_item comItem1, _item comItem2);
//����ϲ��ڵ�
int __returnItemNumber(_item *impleItem);
//����
void _exportItem(const pItemNode head);
//����ȽϺ���
int __compFuncExport(_item comItem1, _item comItem2);

#endif