#ifndef _WAREHOUSE_H
#define _WAREHOUSE_H
//启动器 创建链表 创建/加载/储存记录
void fstartWareHouse(void);
//检查储存文件1存在 0 不存在
int _checkIsFileExist(void);
//创建文件
int _createRecordFile(void);
//加载文件
int _loadRecord(pItemNode head);
//储存文件
int _saveRecord(pItemNode head);
//储存文件函数
int __saveRecordOutput(item toImple);
//展示命令选单
void _showCommandList(void);
//获得命令调用相应函数 返回0为退出系统
int _getCommandAndImplement(pItemNode head);
//检查链表是否为空返回0为空 1非空
int _checkIsEmpty(pItemNode head);
//增加记录 入库
int _addItem(pItemNode head);
int __addItemExist(pItemNode head, pItemNode tempNode);
int __addItemUnexist(pItemNode head, pItemNode tempNode);
//出库
int _outItem(pItemNode head);
//检查已有货物及信号是否存在 0 不存在 1 存在
int __checkIsItemRecord(pItemNode head, item toCompare);
//检查数量是否足够 0不够 1 够
int __outItemNumIsEnough(pItemNode head, item toCheck);
//显示货物记录
int _showItemList(pItemNode head);
//展示一个货物记录
int __showItem(item toImple);

#endif