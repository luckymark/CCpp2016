//
// Created by Administrator on 2016/6/9.
//

#ifndef P_EMPLOYEEANDSALES_EMPLOYEE_H
#define P_EMPLOYEEANDSALES_EMPLOYEE_H


class Employee {
private:
    std::string name;
    int age;
    int level;
public:
    Employee(std::string mName,int mAge;int mLevel){
        name=mName;
        age=mAge;
        level=mLevel;
    }
    virtual int salary();
};


#endif //P_EMPLOYEEANDSALES_EMPLOYEE_H
