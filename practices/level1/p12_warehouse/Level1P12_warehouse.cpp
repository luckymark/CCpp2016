// Level1P12_warehouse.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <string>
#include <stdio.h>
using namespace std;

void showMenu();
void showAllGoods();
void change(int flag);
int test(int goodHave,int type);

int main()
{	
	showMenu();
	return 0;
}

int test(int goodHave,int type) {
	int good;
	switch (type)
	{
	case 1:
		cout << "请输入货物入库数量：";
		cin >> good;
		if (good < 0) {
			cout << "<输入错误，请重新输入！>" << endl;
			test(goodHave, 1);
		}
		else
		{
			return good;
		}
		break;
	case 2:
		cout << "请输入货物出库数量：";
		cin >> good;
		if (good > goodHave)
		{
			cout << "<库存不足，请重新输入！>" << endl;
			test(goodHave, 2);
		}
		else if(good < 0)
		{
			cout << "<输入错误，请重新输入！>" << endl;
			test(goodHave, 2);
		}
		else
		{
			return -good;
		}
		break;
	default:
		
		break;
	}
	return 0;
}

void showMenu() {
	cout << "=====  按数字选择菜单功能:  ====" << endl;
	cout << "<1.显示存货列表>   <2.入库>" << endl;
	cout << "<3.出库>       <4.退出程序>" << endl;
	char choice;
	cin >> choice;
	switch (choice)
	{
	case '1':
		showAllGoods();
		break;
	case '2':
		change(1);
		break;
	case '3':
		change(3);
		break;
	case '4':
		break;
	default:
		cout << "<输入错误，请重新选择>" << endl;
		showMenu();
		break;
	}
}

void showAllGoods() {
	FILE *fp;
	fp = fopen("goods.txt", "a+");
	cout << "\n<货号>\t\t<库存>\n";
	char mystring[100];
	while (fgets(mystring, 100, fp) != NULL) {
		cout << mystring;
	}
	cout << "\n";
	fclose(fp);
	cout << "<展示完成!>\n" << endl;
	showMenu();
}

void change(int type) {
	FILE *fp;
	int line = 0,findFlag = 0,exactLine;
	char goodNum[10];
	int goodSum;
	char buf[100], buff[100];
	char bufftemp[100][100];
	const char* del = "\t";
	char* tem;
	int tempGoods = 0;
	fp = fopen("goods.txt", "a+");
	cout << "\n<请输入货号:>";
	cin >> goodNum;
	while (fgets(buf, 100, fp) != NULL)
	{
		strcpy(buff, buf);
		tem = strtok(buff, del);
		if (strcmp(goodNum,tem) == 0)
		{	
			tem = strtok(NULL, "\t");
			tempGoods = atoi(tem);
			cout << "<货物编号" << goodNum << "的数量为：" << tempGoods << "> " ;
			exactLine = line;			//这个是为了解决如果是最后一行的话，行头会自带回车
			findFlag = 1;
		}
		else
		{
			strcpy(bufftemp[line], buf);
			line++;
		}	
	}
	int flag = type + findFlag;
	switch (flag)
	{
		case 1:
			cout << "<没有该货物，将新建> ";
			goodSum = test(tempGoods, 1);
			break;
		case 2:
			goodSum = test(tempGoods,1);
			break;
		case 3:
			cout << "<没有该货物，将返回菜单>\n" << endl;
			showMenu();
			return;
		case 4:
			goodSum = test(tempGoods,2);
			break;
		default:
			
			break;
	}

	if (!findFlag)
	{
		fprintf(fp, "\n%s\t\t%d", goodNum, goodSum);
		fclose(fp);
		cout << "<修改完成!>\n" << endl;
	}
	else
	{
		fclose(fp);
		remove("goods.txt");
		FILE *fp2;
		fp2 = fopen("goods.txt", "a+");
		for (int i = 0; i < line; i++)
		{
			fprintf(fp2, "%s", bufftemp[i]);
		}
		int goodNewSum = goodSum + tempGoods;
		if (line == exactLine)
		{
			fprintf(fp2, "%s\t\t%d", goodNum, goodNewSum);
		}
		else
		{
			fprintf(fp2, "\n%s\t\t%d", goodNum, goodNewSum);
		}
		fclose(fp2);
		cout << "<修改完成!>\n" << endl;
	}	
	showMenu();
}

