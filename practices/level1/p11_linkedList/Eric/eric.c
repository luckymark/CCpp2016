//Eric
//linkedList

#include <stdio.h>
#include <stdlib.h>
#include "linkedList.h"

int showNode(item toImple, int numOfNode);
int showFive(item toImple, int numOfNode);
int show2Five(item toImple, int numOfNode);
//�жϲ����5
int main(void)
{
	//��ʼ�����б�
	pItemNode head = finitialize();
	//�������� 9�� ��in.txt ��ֻ�ǲ���
	//�����out.txt
	//freopen("in.txt", "r", stdin);
	for (int count = 1; count < 10; count++)
	{
		finsertNode(head, 0);
	}

	//freopen("out.txt", "w", stdout);
	//������һ�� ���ֵ
	printf("To show value\n");
	fimplementFunc(head, (*showNode));
	//�ߵ����� �����ֵ
	freverseLinkedList(head);
	printf("To show the vaule after reversed\n");
	fimplementFunc(head, (*showNode));

	//�����һ�� 5
	printf("The first 5\n");
	if (fimplementFunc(head, (*showFive)))
	{
		printf("-1");
	}
	//�ڶ���5
	printf("\nThe second 5\n");
	if (fimplementFunc(head, (*show2Five)))
	{
		printf("-1");
	}

	//�ͷ��б�
	fcloseTheList(head);

	system("pause");
	return 0;
}
int showNode(item toImple, int numOfNode)
{
	printf("%d\n", toImple.itemNumber);
	return 0;
}
int showFive(item toImple, int numOfNode)
{
	if (toImple.itemNumber == 5)
	{
		printf("No.%d\n", numOfNode);
		return 1;
	}
	return 0;
}
int show2Five(item toImple, int numOfNode)
{
	static fiveCount = 0;
	if (toImple.itemNumber == 5)
	{
		fiveCount++;
		if (fiveCount == 2)
		{
			printf("No.%d\n", numOfNode);
			return 1;
		}
	}
	return 0;
}