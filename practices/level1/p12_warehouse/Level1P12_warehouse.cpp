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
		cout << "������������������";
		cin >> good;
		if (good < 0) {
			cout << "<����������������룡>" << endl;
			test(goodHave, 1);
		}
		else
		{
			return good;
		}
		break;
	case 2:
		cout << "������������������";
		cin >> good;
		if (good > goodHave)
		{
			cout << "<��治�㣬���������룡>" << endl;
			test(goodHave, 2);
		}
		else if(good < 0)
		{
			cout << "<����������������룡>" << endl;
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
	cout << "=====  ������ѡ��˵�����:  ====" << endl;
	cout << "<1.��ʾ����б�>   <2.���>" << endl;
	cout << "<3.����>       <4.�˳�����>" << endl;
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
		cout << "<�������������ѡ��>" << endl;
		showMenu();
		break;
	}
}

void showAllGoods() {
	FILE *fp;
	fp = fopen("goods.txt", "a+");
	cout << "\n<����>\t\t<���>\n";
	char mystring[100];
	while (fgets(mystring, 100, fp) != NULL) {
		cout << mystring;
	}
	cout << "\n";
	fclose(fp);
	cout << "<չʾ���!>\n" << endl;
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
	cout << "\n<���������:>";
	cin >> goodNum;
	while (fgets(buf, 100, fp) != NULL)
	{
		strcpy(buff, buf);
		tem = strtok(buff, del);
		if (strcmp(goodNum,tem) == 0)
		{	
			tem = strtok(NULL, "\t");
			tempGoods = atoi(tem);
			cout << "<������" << goodNum << "������Ϊ��" << tempGoods << "> " ;
			exactLine = line;			//�����Ϊ�˽����������һ�еĻ�����ͷ���Դ��س�
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
			cout << "<û�иû�����½�> ";
			goodSum = test(tempGoods, 1);
			break;
		case 2:
			goodSum = test(tempGoods,1);
			break;
		case 3:
			cout << "<û�иû�������ز˵�>\n" << endl;
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
		cout << "<�޸����!>\n" << endl;
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
		cout << "<�޸����!>\n" << endl;
	}	
	showMenu();
}

