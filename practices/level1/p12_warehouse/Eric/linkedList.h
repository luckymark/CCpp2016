#ifndef LINKEDLIST_H
#define LINKEDLIST_H
//�ַ�����ĳ���
#define CHAR_LENGTH 41
//����ṹ
typedef struct {
	char itemName[CHAR_LENGTH];
	char itemModel[CHAR_LENGTH];
	int itemNumber;
} _item;
//����ڵ�
typedef struct itemnode {
	_item item;
	struct itemnode *next;
} itemNode;
//�ڵ�ָ��
typedef itemNode * pItemNode;

//��ʼ������
pItemNode _initializeList(void);
//��ʼ���ڵ� ���ز���
pItemNode __initializeNode(pItemNode node);
//����ڵ㣨�»��
int _insertNodeFromStdin(const pItemNode head);
//��ȡ��Ϣ
_item __getInfoFrom2TempNode(void);
//����ڵ㣨���ļ���
int _insertNodeFromFile(const pItemNode head, _item temp);
//���Ƶ�Ŀ��ڵ�
int __copyNode(pItemNode targetItemNode, _item temp);
//ɾ���ڵ� �ض��ڵ�
int _deleteNode(const pItemNode head, int numOfNode);
//ɾ���ڵ� β���ڵ�
int _deleteNode(const pItemNode head);
//ɾ���ڵ� ָ����ָ
int _deleteNode(const pItemNode head, pItemNode pItemNode2Delete);
//���Ŀ�����Ƿ����
pItemNode __isNodeExist(const pItemNode head, int numOfNode);
//���ҽڵ�
int _findNode(const pItemNode head, int(*compFunc)(_item comItem1, _item comItem2), _item comItem1);
//Ӧ�ú���
int _impleFunction(const pItemNode head, int(*impleFunc)(_item *impleItem));
//Ӧ�ú��� �ض��ڵ�
int _impleFunction(const pItemNode head, int(*impleFunc)(_item *impleItem), int numOfNode);
//ɾ������
int _freeLinkedList(const pItemNode head);
//����β���ڵ�ָ��
pItemNode __bottomNode(const pItemNode head);
#endif