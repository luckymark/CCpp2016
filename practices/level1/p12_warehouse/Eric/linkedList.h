#ifndef LINKEDLIST_H
#define LINKEDLIST_H
//字符数组的长度
#define CHAR_LENGTH 41
//货物结构
typedef struct {
	char itemName[CHAR_LENGTH];
	char itemModel[CHAR_LENGTH];
	int itemNumber;
} _item;
//链表节点
typedef struct itemnode {
	_item item;
	struct itemnode *next;
} itemNode;
//节点指针
typedef itemNode * pItemNode;

//初始化链表
pItemNode _initializeList(void);
//初始化节点 返回参数
pItemNode __initializeNode(pItemNode node);
//插入节点（新货物）
int _insertNodeFromStdin(const pItemNode head);
//获取信息
_item __getInfoFrom2TempNode(void);
//插入节点（从文件）
int _insertNodeFromFile(const pItemNode head, _item temp);
//复制到目标节点
int __copyNode(pItemNode targetItemNode, _item temp);
//删除节点 特定节点
int _deleteNode(const pItemNode head, int numOfNode);
//删除节点 尾部节点
int _deleteNode(const pItemNode head);
//删除节点 指针所指
int _deleteNode(const pItemNode head, pItemNode pItemNode2Delete);
//检查目标结点是否存在
pItemNode __isNodeExist(const pItemNode head, int numOfNode);
//查找节点
int _findNode(const pItemNode head, int(*compFunc)(_item comItem1, _item comItem2), _item comItem1);
//应用函数
int _impleFunction(const pItemNode head, int(*impleFunc)(_item *impleItem));
//应用函数 特定节点
int _impleFunction(const pItemNode head, int(*impleFunc)(_item *impleItem), int numOfNode);
//删除链表
int _freeLinkedList(const pItemNode head);
//返回尾部节点指针
pItemNode __bottomNode(const pItemNode head);
#endif