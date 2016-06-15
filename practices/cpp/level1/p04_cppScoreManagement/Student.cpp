#include "Student.h"
#include<iostream>
#include<string>
using namespace std;
Student::Student()
{


}

Student::~Student()
{

}
void Student::SetName(string name)
{
    this->name=name;
}
void Student::SetId(int id)
{
    this->id=id;
}
void Student::SetScore(int score)
{
    this->score=score;
}
string Student::GetName()
{
    return name;
}
int Student::GetId()
{
    return id;
}
int Student::GetScore()
{
    return score;
}
