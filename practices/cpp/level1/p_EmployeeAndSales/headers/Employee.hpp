#ifndef EMPLOYEE_HPP
#define EMPLOYEE_HPP

#include <string>

class Employee {
private:
    
public:
    std::string m_name;
    int m_age;
    int m_level;
    Employee(std::string name, int age, int level);
    virtual double get_salary();
};

#endif
