//Eric Linkedlist
#ifndef _LINKEDLIST_H
#define _LINKEDLIST_H

#define CHARLENGTH 41
typedef struct {
	char itemNames[CHARLENGTH];
	char itemModel[CHARLENGTH];
	int itemNumber;
} item;

typedef struct itemnode {
	item itemExample;
	struct itemnode *next;
}itemNode;

typedef itemNode * pItemNode;

pItemNode finitialize(void);
//初始化列表 返回头指针 失败返回NULL
int finsertNode(pItemNode head, int num2insert);
//向指定位置插入一个节点 0为末尾 return 1 when succeed insert
int fdeleteNode(pItemNode head, int num2delete);
//删除指定节点 return 1 when succeed delete
int fimplementFunc(pItemNode head, int(*impleFunc)(item toImple, int numOfNode));
//对每个节点应用函数 被应用函数返回0打断执行 return 1 全部执行 return 0 被中断
//numOfNode 表示第几个Node
int freverseLinkedList(pItemNode head);
//反转链表
int fcloseTheList(pItemNode head);
//删除链表 1表示成功
#endif