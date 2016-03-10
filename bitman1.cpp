// bitman1.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <string>
#include <iostream>

using namespace std;
int p = 0,head = 0;
struct data
{
	string name,tel;
	int nex,pre;
}person[1000];

void add(string name, string tel)
{
	p++;
	person[p].name = name;
	person[p].tel = tel;
	person[p].nex = head;
	person[head].pre = p;
	head = p;
}

void search(int v, string st)
{
	if (v == 1)
		for (int t = head; t;t=person[t].nex)
			if (person[t].name == st)
			{
				cout << "姓名:" << person[t].name << endl;
				cout << "号码:" << person[t].tel << endl<< endl;
			}
	if (v == 2)
		for (int t = head; t; t = person[t].nex)
			if (person[t].tel == st)
			{
				cout << "姓名:" << person[t].name << endl;
				cout << "号码:" << person[t].tel << endl<< endl;
			}
}

void printall()
{
	for (int t = head; t; t = person[t].nex)
		{
			cout << "姓名:" << person[t].name << endl;
			cout << "号码:" << person[t].tel << endl<<endl;
		}
}

void del(int v, string st)
{
	if (v == 1)
		for (int t = head; t; t = person[t].nex)
			if (person[t].name == st)
			{
				person[person[t].pre].nex = person[t].nex;
				person[person[t].nex].pre = person[t].pre;
			}
	if (v == 2)
		for (int t = head; t; t = person[t].nex)
			if (person[t].tel == st)
			{
				person[person[t].pre].nex = person[t].nex;
				person[person[t].nex].pre = person[t].pre;
			}
}

int main()
{
	int n,o;
	string name, tel;
	while (1)
	{
		printf("\n\n输入指令:\n");
		printf("1.添加\n");
		printf("2.查询\n");
		printf("3.列出所有信息\n");
		printf("4.删除\n");
		cin >> n;
		switch (n)
		{
		case 1:
			printf("输入姓名:\n");
			cin >> name;
			printf("输入电话号码:\n");
			cin >> tel;
			add(name, tel);
			break;
		case 2:
			printf("输入1--以姓名查询  2--以电话号码查询\n");
			cin >> o;
			if (o == 1)
			{
				printf("输入姓名:\n");
				cin >> name;
				search(1,name);
			}
			if (o == 2)
			{
				printf("输入号码:\n");
				cin >> tel;
				search(2,tel);
			}
			break;
		case 3:
			printall();
			break;
		case 4:
			printf("输入你想删除人的信息 1--姓名方式 2--号码方式\n");
			cin >> o;
			if (o == 1)
			{
				printf("输入姓名:\n");
				cin >> name;
				del(1, name);
			}
			if (o == 2)
			{
				printf("输入号码:\n");
				cin >> tel;
				del(2, tel);
			}
		default:
			break;
		}
	}
    return 0;
}

