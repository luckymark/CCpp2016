/*
warehouse.h v2.0
author:Eric
date 2016-03-17
*/
#ifndef _WAREHOUSE_H
#define _WAREHOUSE_H

#include "linkedlist.h"

//文件名
#define RECORD_FILE_NAME "recode.db"

//启动器
void fstartWarehouse(void);

//==========================================启动器===================================
//处理记录文件 加载 或者 新建
int _operateRecordFile(const pItemNode head);
//从文件加载记录
int __reloadRecordFile(const pItemNode head);
//保存到文件
int _saveRecordFile(const pItemNode head);
//输出节点到文件
int __outputNode2File(_item *impleItem);
//展示命令选单
void _showCommandList(void);
//功能函数启动器
void _startFunction(char order, const pItemNode head);

//========================================功能函数=====================================
//展示货物列表
void _showItemList(const pItemNode head);
//输出货物信息到stdout
int __showItemList(_item *item);
//进库
void _importItem(const pItemNode head);
//进库比较函数
int __compFuncImport(_item comItem1, _item comItem2);
//进库合并节点
int __returnItemNumber(_item *impleItem);
//出库
void _exportItem(const pItemNode head);
//出库比较函数
int __compFuncExport(_item comItem1, _item comItem2);

#endif