#include "System.h"

System::System()
{
    //ctor
}

System::~System()
{
    //dtor
}

void System::showAllStudent(){
    for(int i=0;i<StudentList.size();i++){
        StudentList[i].showImformation();
    }
}

void System::addStudent(Student newStudent){
    StudentList.push_back(newStudent);
}

void System::addNewStudent(){
    Student newStudent;
    newStudent.setImformation();
    StudentList.push_back(newStudent);
}
void System::delateStudent(){
    cout<<"请输入需要删除的学生的学号：";
    int delateID;
    cin>>delateID;
    for(int i=0;i<StudentList.size();i++){
        if(StudentList[i].getID() == delateID){
            StudentList.erase(StudentList.begin()+i);
        }
    }
}

void System::enteringScore(){
    for(int i=0;i<StudentList.size();i++){
        StudentList[i].showImformation();
        cout<<"请输入成绩：";
        int newScore;
        cin>>newScore;
        StudentList[i].setScore(newScore);
    }
}
