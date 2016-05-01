// ConsoleApplication46.cpp : 定义控制台应用程序的入口点。
#include "stdafx.h"
//
#include "stdafx.h"
#include<stdio.h>//显示横杠
#include<stdlib.h>
#include<Windows.h>
typedef struct good {
	int num;
	int numname;
	char name[20];
};
good goods[1000];
void show(void);
int findNoZero(void);
int main() {
	int i = 0;//保存用户选项
	int customscanf, yes, addorout, total, finaltotal;
	int yes2;//有没有找到这种货物
	int nozeroone;//没有储存货物的位置
	int a, k, j = 0;//j是case3的循环变量
	a = yes2 = yes = 0;

	FILE *fin;
	fin = fopen("in.txt", "r");
	fscanf(fin, "%d", &total);
	while (a < total) {
		fscanf(fin, "%d %d %s", &goods[a].numname, &goods[a].num, goods[a].name);
		a++;
	}
	fclose(fin);
	show();
	while (scanf("%d",&i)!=EOF&&i!=0) {
		yes = yes2 = 0;
		switch (i) {
		case 1:
		{
			printf("name      num      numname\n");
			for (int j = 0; j < 1000; j++)
				if (goods[j].numname != 0)
					printf("%-10s%-10d%-10d\n", goods[j].name, goods[j].num, goods[j].numname);
			break;
		}
		case 2:
		{
			printf("please input the name num\n");
			scanf("%d", &customscanf);
			for (k = 0; k < 1000; k++) {
				if (goods[k].numname == customscanf)
				{
					printf("find it,input the number\n");
					scanf("%d", &addorout);
					goods[k].num += addorout;
					yes = 1;
					break;
				}
			}
			if (!yes)
			{
				printf("its new goods.Please input the name and its number\n");
				nozeroone = findNoZero();//依次输入名字和数量
				scanf("%s%d", goods[nozeroone].name, &goods[nozeroone].num);
				goods[nozeroone].numname = customscanf;
			}
			system("cls");
			show();
			break;
		}
		case 3:
		{
			printf("please input the name num\n");
			scanf("%d", &customscanf);
			for (j = 0; j < 1000; j++)
				if (goods[j].numname == customscanf)
				{
					yes2 = 1;
					break;
				}
			if (yes2)
			{
				printf("find it,input the number\n");
				scanf("%d", &addorout);
				if (addorout > goods[j].num)
				{
					printf("too much,you can't do this\n");
					system("cls");
					show();
					break;
				}
				else
					goods[j].num -= addorout;
				system("cls");
				show();
				break;
			}
			else
			{
				printf("no such thing !!!\n");
				break;
			}
		}
		}
	}
	fin=fopen("in.txt", "w");
	for (int a = 0;; a++)
		if (goods[a].numname == 0) {
			finaltotal = a + 1;
			fprintf(fin, "%d\n", finaltotal);
			break;
		}
	for (int a = 0; a < finaltotal - 1; a++)
		fprintf(fin,"%d %d %s\n", goods[a].numname, goods[a].num, goods[a].name);
	return 0;
}
void show(void) {
	for (int a = 0; a < 20; a++)
		printf("-");
	printf("\n");
	printf("1.See the list\n2.Add some good\n3.Out some good\n4.0 to quit\n");
	for (int a = 0; a < 20; a++)
		printf("-");
	printf("\n");
}
int findNoZero(void) {
	for (int a = 0; a < 1000; a++) {
		if (goods[a].numname == 0)
			return a;
	}
}
