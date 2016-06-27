/**
 * Project Untitled
 */


#ifndef _BUILIDING_H
#define _BUILIDING_H
#include <string>
using namespace std;
class Building {
public:
    Building(string _no,int _floor,int _area):no(_no),floor(_floor),area(_area){ }
    string getNo();

    int getFloor();

    int getArea();
private:
    string no;
    int floor;
    int area;
};

#endif //_BUILIDING_H
