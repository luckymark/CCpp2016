#include <iostream>
#include <cstdio>
#include "safearray.h"
using namespace std;
int main(){
    int p,a;
    SafeArray data(100);

    cin>>p>>a;
    data.getIn(p,a);

    cin>>p;
    cout>>data.getOut(p)>>endl;
}
