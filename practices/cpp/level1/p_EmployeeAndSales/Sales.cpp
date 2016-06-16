#include "headers/Sales.hpp"

double Sales::get_salary() {
    return Employee::get_salary() * 1.2;
}
