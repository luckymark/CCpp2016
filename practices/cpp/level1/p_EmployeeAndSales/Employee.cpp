#include "headers/Employee.hpp"

Employee::Employee(std::string name, int age, int level): m_name(name),
                                                          m_age(age),
                                                          m_level(level){}

double Employee::get_salary() {
    return 1000 * m_level;
}
