#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct List
{
	static int num;
	int amount;
	char goods[100];
	struct List *next;
};
int n = 0;
List *head = NULL;
int List::num = 0;
struct List* createList(List *p, char info[], int n);
struct List* showMenu(List *p);
void showList(List *p, char[]);
struct List* deleteList(List *p, char info[]);
struct List* open(List *p, FILE *f, int n);
struct List* close(List *p, FILE *f, int n);
int main()
{
	FILE *fp;
	List *p;
	printf("                       welcome!!!                  \n");
	system("pause");
	system("cls");
	if ((fp = fopen("D:\\myrepo.txt", "r+")) == NULL)
	{
		if ((fp = fopen("D:\\myrepo.txt", "w+")) == NULL)
		{
			printf("error");
			exit(0);
		}
	}
	head = (List *)malloc(sizeof(List));
	p = (List *)malloc(sizeof(List));
	head = open(p, fp, n);
	head->next = p;
	if (p->num == 0)
	{
		p->amount = 0;
		p->next = NULL;
	}
	while (1)
		head = showMenu(p);
}
List * createList(List * p, char info[], int n)
{
	List *pnext;
	int middle = 0;
	if (p->num == NULL)
	{
		strcpy(p->goods, info);
		p->amount = n;
		p->num++;
		p->next = NULL;
	}
	else
	{
		for (p = head->next; p->next != NULL;)
		{
			if (strcmp(info, p->goods) == 0)
			{
				printf("�ֿ����Ѿ��д������!!!\n");
				middle = 1;
				break;
			}
			p = p->next;
		}
		if (middle == 1)
		{
			p->amount += n;
		}
		else
		{
			pnext = (List *)malloc(sizeof(List));
			p->next = pnext;
			p = p->next;
			p->next = NULL;
			strcpy(p->goods, info);
			p->amount = n;
			p->num++;
		}
	}
	printf("���%s�ɹ�\n", info);
	system("pause");
	return head;
}
struct List* showMenu(List *p)
{
	FILE *fwp;
	int n, a;
	char info[100];
	system("cls");
	printf("                                        * * * * * * * * * * * * * * * * * * *\n");
	printf("                                        *            ������ѡ�           *\n");
	printf("                                        *              1.���               *\n");
	printf("                                        *             2.���ҿ�              *\n");
	printf("                                        *              3.����               *\n");
	printf("                                        *             4.�˳�������          *\n");
	printf("                                        *        ����1,2,3,4��Ϊ��Ч����    *\n");
	printf("                                        * * * * * * * * * * * * * * * * * * *\n");
	scanf("%d", &n);
	system("cls");
	switch (n)
	{
	case 1:
		printf("�����������Ϣ\n");
		setbuf(stdin, NULL);
		gets_s(info);
		printf("�������������\n");
		setbuf(stdin, NULL);
		scanf("%d", &n);
		head = createList(p, info, n);
		return head;
	case 2:
		printf("��������Ҫ���ҵĻ�����Ϣ\n");
		setbuf(stdin, NULL);
		gets_s(info);
		showList(p, info);
		break;
	case 3:
		printf("�����������Ϣ\n");
		setbuf(stdin, NULL);
		gets_s(info);
		head = deleteList(p, info);
		return head;
	case 4:
		if ((fwp = fopen("D:\\myrepo.txt", "w+")) == NULL)
		{
			printf("error!!\n");
			exit(0);
		}
		close(p, fwp, p->num);
		printf("�������˳�!!!\n");
		system("pause");
		exit(0);
	default:
		printf("error!!\n");
		system("pause");
		setbuf(stdin, NULL);
	}
	return p;
}
struct List* open(List *p, FILE *fp, int n)
{
	int i = 0;
	head->next = p;
	char minfo[100];
	int mamount = 0;
	fscanf(fp, "%d\n", &n);
	while (i < n)
	{

		fgets(minfo, 100, fp);
		setbuf(stdin, NULL);
		fscanf(fp, "%d\n", &mamount);
		p = createList(p, minfo, mamount);
		i++;
	}
	fclose(fp);
	return head;
}
struct List* close(List *p, FILE *fp, int n)
{
	List *middle;
	int i = 0;
	n = p->num;
	fprintf(fp, "%d\n", n);
	while (i < n)
	{
		fputs(p->goods, fp);
		fprintf(fp, "%c%c", '\0', '\n');
		fprintf(fp, "%d\n", p->amount);
		middle = p;
		p = p->next;
		free(middle);
		i++;
	}
	fclose(fp);
	free(head);
	return 0;
}
void showList(List * p, char info[])
{
	List *middle = NULL;
	int flag = 0;
	if (p->num == 0)
	{
		printf("�ֿ�Ϊ��!\n");
		system("pause");
	}
	else
	{
		p = head->next;
		for (; p != NULL;)
		{
			if (strcmp(info, p->goods) == 0)
			{
				middle = p;
				flag = 1;
			}
			printf("��������:   ");
			printf("%s", p->goods);
			printf("       ��������:");
			printf("%d", p->amount);
			printf("\n");
			p = p->next;
		}
		if (flag == 1)
		{
			printf("find!!!\n");
			printf("����������Ϣ:\n");
			printf("��������:   ");
			printf("%s", middle->goods);
			printf("       ��������:");
			printf("%d", middle->amount);
			printf("\n");
		}
		else
		{
			printf("not found!!!\n");
		}
		system("pause");
	}
}
List* deleteList(List *p, char info[])
{
	List *middle;
	int flag = 0;
	for (p = head->next; p != NULL;)
	{
		if (strcmp(info, p->goods) == 0)
		{
			flag = 1;
			break;
		}
		middle = p;
		p = p->next;
	}
	if (flag == 0)
	{
		printf("�ֿ���û�д˻�����Ϣ:\n");
	}
	else
	{
		middle->next = p->next;
		p->num--;
		free(p);
		printf("ɾ��%s�ɹ�\n", info);
	}
	return head;
}
