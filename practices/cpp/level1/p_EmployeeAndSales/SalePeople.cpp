#include "SalePeople.h"

SalePeople::SalePeople()
{
    //ctor
}

SalePeople::~SalePeople()
{
    //dtor
}

void SalePeople::setSale(int sale){
    this->sale = sale;
}

int SalePeople::money(){
    return level*1000+sale*0.2f;
}
