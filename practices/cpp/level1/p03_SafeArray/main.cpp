#include <iostream>

using namespace std;
#include <SafeArray.h>
int main()
{
    SafeArray array(3);
    for(int i=0;i<3;i++){
        array.setItem(i,i+10);
    }
    for(int i=0;i<3;i++){
        cout<<array.getItem(i)<<endl;
    }
    array.setItem(4,10);
    array.getItem(4);
    return 0;
}
