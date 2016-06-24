#include "Employee.hpp"

class Sales: public Employee {
private:
public:
    Sales(std::string name, int age, int level): Employee(name, age, level) {}
    virtual double get_salary();
};
