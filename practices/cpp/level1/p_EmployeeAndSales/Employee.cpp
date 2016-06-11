#include "Employee.h"

Employee::Employee()
{
    //ctor
}

Employee::~Employee()
{
    //dtor
}

int Employee::money(){
    return level*1000;
}

void Employee::setImformation(std::string name,int age,int level){
    this->age = age;
    this->level = level;
    this->name = name;
}
