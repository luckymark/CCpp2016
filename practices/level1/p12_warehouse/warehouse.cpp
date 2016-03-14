#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct List
{
	static int num;
	int amount;
	char good[100];
	struct List *next;
};
int n = 0;
List *head = NULL;
int List::num = 0;
struct List* createlist(List *p, char info[],int n );
struct List* menu(List *p);
void showlist(List *p,char []);
struct List* deletelist(List *p, char[]);
struct List* open(List *p, FILE *f,int n);
struct List* close(List *p,FILE *f,int n);
int main()
{
	FILE *fp;
	List *p;
	printf("                       welcome!!!                  \n");
	system("pause");
	system("cls");
	if ((fp = fopen("D:\\project\\C语言课后习题\\C语言课后第十一题\\myrepo.txt", "r+") )== NULL)
	{
		printf("error!!\n");
		exit(0);
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
	{
		head = menu(p);
	}
}
List * createlist(List * p, char info[], int n)
{
	List *pnext;
	int middle = 0;
	if (p->num == NULL)
	{
		strcpy(p->good, info);
		p->amount = n;
		p->num++;
		p->next = NULL;
	}
	else
	{
		for (p = head->next; p->next != NULL;)
		{
			if (strcmp(info, p->good) == 0)
			{
				printf("仓库中已经有此类货物!!!\n");
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
			strcpy(p->good, info);
			p->amount = n;
			p->num++;
		}
	}
	printf("添加%s成功\n", info);
	system("pause");
	return head;
}
struct List* menu(List *p)
{
	FILE *fwp;
	int n, a;
	char info[100];
	system("cls");
	printf("                                        * * * * * * * * * * * * * * * * * * *\n");
	printf("                                        *            请输入选项！           *\n");
	printf("                                        *              1.入库               *\n");
	printf("                                        *             2.查找库              *\n");
	printf("                                        *              3.出库               *\n");
	printf("                                        *             4.退出并保存          *\n");
	printf("                                        *        不是1,2,3,4则为无效操作    *\n");
	printf("                                        * * * * * * * * * * * * * * * * * * *\n");
	scanf("%d", &n);
	system("cls");
	switch (n)
	{
	case 1:
		printf("请输入货物信息\n");
		setbuf(stdin, NULL);
		gets_s(info);
		printf("请输入货物数量\n");
		setbuf(stdin, NULL);
		scanf("%d", &n);
		head = createlist(p, info, n);
		return head;
	case 2:
		printf("请输入想要查找的货物信息\n");
		setbuf(stdin, NULL);
		gets_s(info);
		showlist(p, info);
		break;
	case 3:
		printf("请输入货物信息\n");
		setbuf(stdin, NULL);
		gets_s(info);
		head=deletelist(p, info);
		return head;
	case 4:
		if ((fwp = fopen("D:\\project\\C语言课后习题\\C语言课后第十一题\\myrepo.txt", "w+")) == NULL)
		{
			printf("error!!\n");
			exit(0);
		}
		close(p,fwp,p->num);
		printf("程序已退出!!!\n");
		system("pause");
		exit(0);
	default:
		printf("error!!\n");
		system("pause");
		setbuf(stdin, NULL);
	}
	return p;
}
struct List* open(List *p, FILE *fp,int n)
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
		p = createlist(p, minfo, mamount);
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
	while (i < n )
	{
		fputs(p->good, fp);
		fprintf(fp, "%c%c", '\0','\n');
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
void showlist(List * p, char info[])
{
	List *middle = NULL;
	int flag = 0;
	if (p->num == 0)
	{
		printf("仓库为空!\n");
		system("pause");
	}
	else
	{
		p = head->next;
		for (; p != NULL;)
		{
			if (strcmp(info, p->good )== 0)
			{
				middle = p;
				flag = 1;
			}
			printf("货物名称:   ");
			printf("%s", p->good);
			printf("       货物数量:");
			printf("%d", p->amount);
			printf("\n");
			p = p->next;
		}
		if (flag == 1)
		{
			printf("find!!!\n");
			printf("被搜索的信息:\n");
			printf("货物名称:   ");
			printf("%s", middle->good);
			printf("       货物数量:");
			printf("%d", middle->amount);
			printf("\n");
		}
		else
			printf("not found!!!\n");
		system("pause");
	}
}
List* deletelist(List *p, char info[])
{
	List *middle;
	int flag = 0;
	for (p = head->next; p != NULL;)
	{
		if (strcmp(info, p->good) == 0)
		{
			flag = 1;
			break;
		}
		middle = p;
		p = p->next;
	}
	if (flag == 0)
	{
		printf("仓库中没有此货物信息:\n");
	}
	else
	{
		middle->next = p->next;
		p->num--;
		free(p);
		printf("删除%s成功\n", info);
	}
	return head;
}
