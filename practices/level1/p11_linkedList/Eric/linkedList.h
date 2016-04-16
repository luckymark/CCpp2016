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
//��ʼ���б� ����ͷָ�� ʧ�ܷ���NULL
int finsertNode(pItemNode head, int num2insert);
//��ָ��λ�ò���һ���ڵ� 0Ϊĩβ return 1 when succeed insert
int fdeleteNode(pItemNode head, int num2delete);
//ɾ��ָ���ڵ� return 1 when succeed delete
int fimplementFunc(pItemNode head, int(*impleFunc)(item toImple, int numOfNode));
//��ÿ���ڵ�Ӧ�ú��� ��Ӧ�ú�������0���ִ�� return 1 ȫ��ִ�� return 0 ���ж�
//numOfNode ��ʾ�ڼ���Node
int freverseLinkedList(pItemNode head);
//��ת����
int fcloseTheList(pItemNode head);
//ɾ������ 1��ʾ�ɹ�
#endif