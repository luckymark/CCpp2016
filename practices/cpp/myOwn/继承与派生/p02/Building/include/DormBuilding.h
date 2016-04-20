/**
 * Project Untitled
 */


#ifndef _DORMBUILDING_H
#define _DORMBUILDING_H

#include "Building.h"
#include <string>
using namespace std;
class DormBuilding: public Building {
public:
    DormBuilding(string no,int floor,int area,int dormRoomNum,int stuNum):Building(no,floor,area)
    {
        this->dormRoomNum=dormRoomNum;
        this->stuNum=stuNum;
    }
    int getDormRoomNum();

    int getStuNum();
private:
    int dormRoomNum;
    int stuNum;
};

#endif //_DORMBUILDING_H
