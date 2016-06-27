/**
 * Project Untitled
 */


#ifndef _TEACHBUILDING_H
#define _TEACHBUILDING_H

#include "Building.h"
#include <string>
using namespace std;

class TeachBuilding: public Building {
public:
    TeachBuilding(string no,int floor,int area,int classRoomNum):Building(no,floor,area)
    {
        this->classRoomNum=classRoomNum;
    }
    int getClassRoomNum();
private:
    int classRoomNum;
};

#endif //_TEACHBUILDING_H
