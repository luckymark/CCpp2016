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
				cout << "����";
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
	cout << "��ӭ����" << endl;
	cout << "1.����б�" << endl;
	cout << "2.���" << endl;
	cout << "3.����" << endl;
	cout << "4.�˳�����" << endl;
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
		cout << "����" << endl;
	}
	
	file.close();
}

void input()
{
	cout << "ѡ��������ͣ�" << endl << "1.��������" << endl << "2.��������" << endl << "������ţ�";
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
			cout << "������Ҫ����Ļ������ź�������";
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
			cout << "��Ʒ��������Ϊ��" << num << endl << "������Ϊ��" << quantity[order - 1] << endl;
			ofile.close();
		}
		else
		{
			cout << "list.txt��ʧ�ܣ�" << endl;
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
		cout << "��������Ҫ�Ļ������ź�������";
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
			cout << num << "��������ȡ��" << endl << "����������Ϊ" << quantity[order - 1] << endl;
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
			cout << "�������л�����ȡ����ȡ������Ϊ��" << quantity[order - 1] << endl;
		}
		ofile.close();
	}
	else
	{
		cout << "list.txt��ʧ�ܣ�" << endl;
		system("pause");
	}
}