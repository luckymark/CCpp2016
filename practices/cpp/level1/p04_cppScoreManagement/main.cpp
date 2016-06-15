#include "Student.h"
#include <iostream>
#include <string>
#include <stdlib.h>
#define NUMOFSTUDENT 100
using namespace std;
Student *student[NUMOFSTUDENT];
void ShowList();
void AddStudent();
void DeleteStudent();
void InputScore(int ID);
void clean();
int main()
{
    for(int i=0;i<NUMOFSTUDENT;i++)
    {
        student[i]=NULL;
    }
    //int num;
    while(1)
    {
        cout<<"请输入相应序号"<<endl;
        cout<<"（1）查看学生名单"<<endl;
		cout<<"（2）选课"<<endl;
		cout<<"（3）退选"<<endl;
		cout<<"（4）录入成绩"<<endl;
		cout<<"（5）退出程序"<<endl;
		int action;
		cin>>action;
		switch(action)
		{
        case 1:
            ShowList();
            break;
        case 2:
            AddStudent();
            clean();
            break;
        case 3:
            DeleteStudent();
            clean();
            break;
        case 4:
            cout<<"请输入学生的学号"<<endl;
            int ID;
            cin>>ID;
            InputScore(ID);
            clean();
            break;
        case 5:
            exit(0);
            break;
        default:
            cout<<"您输入了错误的菜单项，请重新选择！"<<endl;
            break;

		}

    }
    return 0;
}
void ShowList()
{
    for(int i=0;i<NUMOFSTUDENT;i++)
    {
        if(student[i]!=NULL)
        {
            cout<<student[i]->GetName()<<endl;
            cout<<student[i]->GetId()<<endl;
            cout<<student[i]->GetScore()<<endl;
        }
    }
}
void AddStudent()
{
	for(int i=0;i<NUMOFSTUDENT;i++)
	{
		if(student[i]==NULL)
		{
			student[i]=new Student;
			break;
		}
	}
}
void DeleteStudent()
{
    cout<<"请输入学生的学号"<<endl;
    int ID;
    cin>>ID;
    for(int i=0;i<NUMOFSTUDENT;i++)
    {
        if((student[i]!=NULL)&&student[i]->GetId()==ID)
        {
            delete student[i];
            break;
        }
    }
}
void InputScore(int ID)
{
    bool flag=0;
    for(int i=0;i<NUMOFSTUDENT;i++)
    {
        if((student[i]!=NULL)&&student[i]->GetId()==ID)
        {
            flag=1;
            int score;
            cin>>score;
            student[i]->SetScore(score);
            while(1)
            {
                char choose;
                cout<<"是否继续录入？（Y/N）"<<endl;
                cin>>choose;
                if(choose=='Y')
                {
                    InputScore(ID+1);
                    break;
                }
                else
                {
                    break;
                }
            }
            break;
        }
    }
    if(!flag)
    {
        cout<<"没有该学生"<<endl;
    }
}
void clean()
{
    system("cls");
}
