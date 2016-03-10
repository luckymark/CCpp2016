// bitman1.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <string>
#include <iostream>

#define MAX 10000
#define AddPerson 1
#define SearchPerson 2
#define PrintAllPerson 3
#define DelPerson 4
using namespace std;
int p = 0,head = 0;

struct data
{
	string name,tel;
	int nex,pre;
}person[MAX];

void AddPersonInfomation(string name, string tel) //创建链表 .... 单词不缩写真的好长
{
	p++;
	person[p].name = name;
	person[p].tel = tel;
	person[p].nex = head;
	person[head].pre = p;
	head = p;
}

void Search(string st)  //搜索
{
	bool flag = false;
		for (int t = head; t;t=person[t].nex)
			if (person[t].name == st || person[t].tel == st)
			{
				flag = true;
				cout << "姓名:" << person[t].name << endl;
				cout << "号码:" << person[t].tel << endl<< endl;
			}
		if (flag == false) printf("未查询到此人\n");
}

void PrintAllInfomation() //打印全部
{
	for (int t = head; t; t = person[t].nex)
		{
			cout << "姓名:" << person[t].name << endl;
			cout << "号码:" << person[t].tel << endl<<endl;
		}
	printf("\n打印完毕\n");
}

void Delete(string st) //删除
{
		for (int t = head; t; t = person[t].nex)
			if (person[t].name == st || person[t].tel == st)
			{
				person[person[t].pre].nex = person[t].nex;
				person[person[t].nex].pre = person[t].pre;
			}
		printf("删除成功\n");
}

int main()
{
	int n;
	string name, tel, st;
	while (1)
	{
		printf("\n\n输入指令序号:\n");
		printf("1.添加\n");
		printf("2.查询\n");
		printf("3.列出所有信息\n");
		printf("4.删除\n");
		cin >> n;
		switch (n)
		{
		case AddPerson:
			printf("输入姓名:\n");
			cin >> name;
			printf("输入电话号码:\n");
			cin >> tel;
			AddPersonInfomation(name, tel);
			break;
		case SearchPerson:
			printf("输入姓名或者号码\n");
			cin >> st;
			Search(st);
			break;
		case PrintAllPerson:
			PrintAllInfomation();
			break;
		case DelPerson:
			printf("输入你想删除人的信息(以姓名或者号码)\n");
			cin >> st;
			Delete(st);
		default:
			break;
		}
	}
    return 0;
}

