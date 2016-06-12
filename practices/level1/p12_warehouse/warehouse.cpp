#include<iostream>
#include<fstream>
#include<string>

using namespace std;

int menu();
void list();
void input();
void output();

int main()
{
	int choose = 0;
	while (choose!=4)
	{
		choose = menu();
		switch (choose)
		{
			case 1: {
				system("cls");
				list();
				break;
			};
			case 2: {
				system("cls");
				input();
				break;
			};
			case 3: {
				system("cls");
				output();
				break;
			};
			case 4: {
				break;
			}
			default:
				cout << "错误！";
				system("pause");
				system("cls");
				break;
		}
	}
	
	
	return 0;
}

int menu()
{
	int choose;
	cout << "欢迎光临" << endl;
	cout << "1.存货列表" << endl;
	cout << "2.入库" << endl;
	cout << "3.出库" << endl;
	cout << "4.退出程序" << endl;
	cin >> choose;
	return choose;
}

void list()
{
	fstream file;
	file.open("list.txt",ios::in);
	if (file)
	{
		for (size_t i = 0; i < 100; i++)
		{
			if (file.eof())
			{
				break;
			}
			else
			{
				char line[100];
				file.getline(line, 100);
				cout << line << endl;
			}
		}
		cout << endl;
	}
	else
	{
		cout << "错误！" << endl;
	}
	
	file.close();
}

void input()
{
	cout << "选择入库类型：" << endl << "1.增加数量" << endl << "2.新增种类" << endl << "输入序号：";
	int i;
	cin >> i;
	if (i==1)
	{
		ifstream ifile("list.txt");
		if (ifile)
		{
			int maxnum;
			char data[100][100];
			int quantity[100];
			for (size_t i = 0; i < 100; i++)
			{
				if (ifile.eof())
				{
					maxnum = i - 1;
					break;
				}
				else
				{
					for (size_t j = 0; j < 100; j++)
					{
						if (j == 2)
						{
							ifile >> quantity[i];
						}
						else
						{
							ifile >> data[i][j];
							if (data[i][j] == ';')
							{
								break;
							}
						}
					}
				}
			}
			ifile.close();
			ofstream ofile("list.txt");
			cout << "请输入要放入的货物的序号和数量：";
			int order, num;
			cin >> order >> num;
			quantity[order - 1] = quantity[order - 1] + num;

			for (size_t i = 0; i < maxnum; i++)
			{
				for (size_t j = 0; j < 100; j++)
				{
					if (j == 2)
					{
						ofile << quantity[i];
					}
					else
					{
						ofile << data[i][j];
						if (data[i][j] == ';')
						{
							break;
						}
					}
				}
				ofile << endl;
			}
			cout << "物品放入数量为：" << num << endl << "现总量为：" << quantity[order - 1] << endl;
			ofile.close();
		}
		else
		{
			cout << "list.txt打开失败！" << endl;
			system("pause");
		}
	}
	else
	{
		if (i==2)
		{
			ifstream ifile("list.txt");
			if (ifile)
			{
				int maxnum;
				char line[100];
				for (size_t i = 0; i < 100; i++)
				{
					if (ifile.eof())
					{
						maxnum = i;
						break;
					}
					ifile.getline(line,100);
					cout << line << endl;
				}
				ifile.close();
				ofstream ofile("list.txt",ios::app);
				cout << "Please input the number and name of the wood:";
				string str;
				int num;
				cin >> num >> str;
				ofile << endl << maxnum + 1 << ":" << num << "*" << str << ";" ;
				ofile.close();
			}
			else
			{
				cout << "failed to open list.txt" << endl;
				system("pause");
			}
		}
		else
		{
			cout << "error!";
		}
	}
}

void output()
{
	ifstream ifile("list.txt");
	if (ifile)
	{
		int maxnum;
		char data[100][100];
		int quantity[100];
		for (size_t i = 0; i < 100; i++)
		{
			if (ifile.eof())
			{
				maxnum = i - 1;
				break;
			}
			else
			{
				for (size_t j = 0; j < 100; j++)
				{
					if (j == 2)
					{
						ifile >> quantity[i];
					}
					else
					{
						ifile >> data[i][j];
						if (data[i][j] == ';')
						{
							break;
						}
					}

				}
			}
		}
		ifile.close();

		ofstream ofile("list.txt");
		cout << "请输入需要的货物的序号和数量：";
		int order, num;
		cin >> order >> num;
		if (quantity[order - 1]>num)
		{
			quantity[order - 1] = quantity[order - 1] - num;
			for (size_t i = 0; i < maxnum; i++)
			{
				for (size_t j = 0; j < 100; j++)
				{
					if (j == 2)
					{
						ofile << quantity[i];
					}
					else
					{
						ofile << data[i][j];
						if (data[i][j] == ';')
						{
							break;
						}
					}
				}
				ofile << endl;
			}
			cout << num << "件货物已取出" << endl << "该类现数量为" << quantity[order - 1] << endl;
		}
		else
		{
			for (size_t i = 0; i < maxnum; i++)
			{
				if (i == order - 1)
				{
					continue;
				}
				else
				{
					for (size_t j = 0; j < 100; j++)
					{
						if (i > order - 1)
						{
							if (j==0)
							{
								ofile << i;
								continue;
							}
						}
						
						if (j == 2)
						{
							ofile << quantity[i];
						}
						else
						{
							ofile << data[i][j];
							if (data[i][j] == ';')
							{
								break;
							}
						}
					}
					ofile << endl;
				}
			}
			cout << "该类所有货物已取出，取出数量为：" << quantity[order - 1] << endl;
		}
		ofile.close();
	}
	else
	{
		cout << "list.txt打开失败！" << endl;
		system("pause");
	}
}