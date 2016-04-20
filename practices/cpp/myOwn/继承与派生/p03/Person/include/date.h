/**
 * Project Untitled
 */


#ifndef _DATE_H
#define _DATE_H
#include <cstdio>
class date {
public:
    date(int _year,int _month,int _day):year(_year),month(_month),day(_day){ }
    void show();

    int getYear();

    int getMonth();

    int getDay();
private:
    int year;
    int month;
    int day;
};

#endif //_DATE_H
