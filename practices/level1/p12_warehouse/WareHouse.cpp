// WareHouse.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <Windows.h>

using namespace std;

FILE *stream;

#define SHOW_LIST 1
#define IMPORT 2
#define EXPORT 3
#define EXIT 4


struct data
{
	char type[128];
	int num;
	data *next,*pre;
};

struct data *cargo, *head=NULL;

void readFromTxt();
void init(int v_operand);
void v_show_list();
void v_import();
void v_export();

int main()
{
	readFromTxt();
	int operand;
	while (1)
	{
		Sleep(2000);
		system("cls");
		printf("输入操作数：\n");
		printf("1:显示存货列表\n");
		printf("2:入库\n");
		printf("3:出库\n");
		printf("4:退出程序\n");
		scanf_s("%d", &operand);
		system("cls");
		init(operand);
	}
    return 0;
}

void readFromTxt()
{
	freopen_s(&stream ,"WareHouse.txt", "r", stderr);
	cargo = (struct data *)malloc(sizeof(struct data));
	int num;
	while (fscanf_s(stream, "%s", cargo->type,128)!=EOF)
	{
		fscanf_s(stream, "%d", &num);
		cargo->num = num;
		cargo->next = head;
		if (head!=NULL)
			head->pre = cargo;
		head = cargo;
		cargo = (struct data *)malloc(sizeof(struct data));
	}
	//delete(cargo);
}

void init(int v_operand)
{
	switch (v_operand)
	{
	case SHOW_LIST:
		v_show_list();
		break;
	case IMPORT:
		v_import();
		break;
	case EXPORT:
		v_export();
		break;
	case EXIT:
		freopen_s(&stream,"WareHouse.txt", "w", stderr);
		for (struct data *t = head; t != NULL; t = t->next)
		{
			fprintf(stream,"%s\n", t->type);
			fprintf(stream,"%d\n", t->num);
		}
		fclose(stream);
		exit(0);
		break;
	default:
		break;
	}
}

void v_show_list()
{
	for (struct data *t = head; t != NULL; t = t->next)
		printf("货物型号：%s  货物数量：%d\n",t->type,t->num);
	printf("\n\n");
}

void v_import()
{
	cargo = (struct data *)malloc(sizeof(struct data));
	printf("输入货物型号：\n");
	scanf_s("%s", cargo->type,128);
	printf("输入货物数量：\n");
	scanf_s("%d", &cargo->num);
	cargo->pre = cargo;
	cargo->next = head;
	if (head != NULL)
		head->pre = cargo;
	head = cargo;
	printf("入库成功！\n\n");
}

bool check(char *t1, char *t2,int len1,int len2)
{
	int tot = 0;
	if (len1 != len2) return false;
	else
		while (*(t1+tot) == *(t2+tot))
		{
			if (tot == len1) return true;
			tot++;
		}
	return false;
}
void v_export()
{
	char type[128];
	printf("输入出库货物型号：\n");
	scanf_s("%s", &type,128);
	for (struct data *t = head; t != NULL; t = t->next)
		if (check(t->type,type,strlen(t->type),strlen(type)))
		{
			if (t == head)
			{
				head = t->next;
				printf("出库成功！\n\n");
				break;
			}
			if (t->next != NULL)
			{
				t->pre->next = t->next;
				t->next->pre = t->pre;
				printf("出库成功！\n\n");
				break;
			}
			else
			{
				t->pre->next= NULL;
				printf("出库成功！\n\n");
				break;
			}
			
		}

}

