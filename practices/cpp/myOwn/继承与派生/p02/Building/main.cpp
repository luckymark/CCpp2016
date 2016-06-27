#include <iostream>
#include <string>
#include "Building.h"
#include "DormBuilding.h"
#include "TeachBuilding.h"
using namespace std;
int main()
{
    Building b1("xionglinlin",5,800);
    DormBuilding d1("11dong",6,900,300,2000);
    TeachBuilding t1("pinxuelou",5,800,100);
    return 0;
}
