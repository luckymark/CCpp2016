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

//初始化列表 返回头指针 失败返回NULL
pItemNode finitialize(void);
//向指定位置插入一个节点 0为末尾 return 1 when succeed insert
//inputState 0 标准输入 1 从baseItem复制
int finsertNode(pItemNode head, int num2insert, int inputState, item *baseItem);
//删除指定节点 return 1 when succeed delete
int fdeleteNode(pItemNode head, int num2delete);
//查找相同的节点 返回节点序号 不存在返回0
int ffindNode(pItemNode head, item compareItem);
//比较函数 1 为相等
int _compareFunc(item comItem1, item comItem2);
//返回特定节点的Item 传入0，返回头Item
item fshowNoItem(pItemNode head, int noOfItem);
//对每个节点应用函数 被应用函数返回0打断执行 return 1 when succeed
int fimplementFunc(pItemNode head, int(*impleFunc)(item toImple));
//反转链表
int freverseLinkedList(pItemNode head);
//建立空节点所有值设为0或/0 成功返回地址 失败返回NULL
pItemNode _setupNewItem(void);
//获取信息写入节点 inputState = 0 标准输入输出 1 复制结构输入输出setup a new Node return NULL when fail
pItemNode _getInfo2Node(pItemNode targetNode, int inputState, item *baseItem);
//检查节点是否存在 num2check = 0 返回尾部节点的地址
//return pointer when the item exist, return NULL when unexist
pItemNode _checkIsNode(pItemNode head, int num2check);
//返回尾部节点前一个节点的位置
pItemNode _IsBottomForReverse(pItemNode head);

#endif