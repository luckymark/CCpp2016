#include<iostream>
#include<string>
#include"Student.h"

using namespace std;

void inputscore(Student *students[], int num);

int main()
{
	Student *students[1000];
	for (size_t i = 0; i < 1000; i++)
	{
		students[i] = NULL;
	}

	int num;
	while (1)
	{
		cout << "Please input the number of which thing you want to do" << endl;
		cout << "1.�鿴ѧ������" << endl << "2.ѡ��" << endl << "3.��ѡ" << endl << "4.¼��ɼ�" << endl << "5.�˳�����" << endl << ":";
		int t;
		cin >> t;
		switch (t)
		{
		case 1:
			for (size_t i = 0; i < 1000; i++)
			{
				if (students[i] != NULL)
				{
					cout << "������" << students[i]->get_name() << endl << "ѧ�ţ�" << students[i]->get_ID() << endl << "������" << students[i]->get_score() << endl << endl;
				}
			}
			break;
		case 2:
			for (size_t i = 0; i < 1000; i++)
			{
				if (students[i] == NULL)
				{
					students[i] = new Student;
					break;
				}
			}
			break;
		case 3:
			cout << "Please input the ID of the student" << endl << ":";
			cin >> num;
			for (size_t i = 0; i < 1000; i++)
			{
				if ((students[i] != NULL) && (students[i]->get_ID() == num))
				{
					delete students[i];
					students[i] = NULL;
					break;
				}
			}
			break;
		case 4:
			cout << "Please input the beginning ID of the scores" << endl << ":";
			cin >> num;
			inputscore(students, num);
			break;
		case 5:
			return 0;
			break;
		default:
			break;
		}
	}
}

void inputscore(Student *students[], int num)
{
	bool ifhave = 0;
	for (size_t i = 0; i < 1000; i++)
	{
		if ((students[i]!=NULL) && (students[i]->get_ID() == num))
		{
			ifhave = 1;
			int score;
			cout << "ID  " << num << ":";
			cin >> score;
			students[i]->set_score(score);

			while (1)
			{
				char con;
				cout << "If continue?(Y/N)" << endl << ":";
				cin >> con;
				if (con == 'Y' || con == 'y')
				{
					inputscore(students, num + 1);
					break;
				}
				if (con == 'N' || con == 'n')
				{
					break;
				}
			}
			break;
		}
	}
	if (ifhave == 0)
	{
		cout << "This is the end of the list." << endl;
	}
}