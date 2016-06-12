#include "Student.h"

Student::Student()
{
    //ctor
}

Student::Student(int ID,string name,int score)
{
    this->ID = ID;
    this->name = name;
    this->score = score;
}

void Student::setImformation(){
    int ID;
    string name;
    int score = 0;
    cout<<"请输入学生学号："<<endl;
    cin>>ID;
    cout<<"请输入学生名字："<<endl;
    cin>>name;

    this->ID = ID;
    this->name = name;
    this->score = score;
}

Student::~Student()
{
    //dtor
}

void Student::showImformation(){
    cout<<name<<" 学号:"<<ID<<" 分数:"<<score<<endl;
}

int Student::setScore(int score){
    this->score = score;
}
