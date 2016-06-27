/**
 * Project Untitled
 */


#ifndef _PERSON_H
#define _PERSON_H
#include "date.h"
#include <string>
#include <iostream>
using namespace std;
class Person {
public:

    /**
     * @param string _name
     * @param string _ID
     * @param int _age
     * @param int _sex
     * @param date _bir
     */
    Person(string _name,string _ID, int _age, int _sex, date _bir):name(_name),ID(_ID),age(_age),sex(_sex),birthday(_bir){ };

    string getName();

    int getAge();


    string getID();

    date getBirthday();
private:
    string name;
    string ID;
    int age;
    int sex;
    date birthday;
};

#endif //_PERSON_H
