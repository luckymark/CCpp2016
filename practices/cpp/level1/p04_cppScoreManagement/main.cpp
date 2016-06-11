#include <iostream>
#include<Student.h>
#include<System.h>
using namespace std;

int main()
{
    System system;
    Student student1(20150602,"YYY",0);
    Student student2(2015002,"YY",0);
    Student student3(2010602,"Y",0);
    system.addStudent(student1);
    system.addStudent(student2);
    system.addStudent(student3);
    bool exit = false;
    while(!exit){
        cout<<"---------------------------------------------------"<<endl;
        cout<<"1.查看所有学生信息"<<endl;
        cout<<"2.添加学生"<<endl;
        cout<<"3.删除学生"<<endl;
        cout<<"4.录入成绩"<<endl;
        cout<<"5.退出"<<endl;
        cout<<"请选择功能菜单："<<endl;
        cout<<"---------------------------------------------------"<<endl;
        int choose = 0;
        cin>>choose;
        switch(choose){
            case 1:system.showAllStudent();break;
            case 2:system.addNewStudent();break;
            case 3:system.delateStudent();break;
            case 4:system.enteringScore();break;
            case 5:exit = true;break;
        }
    }
    return 0;
}
