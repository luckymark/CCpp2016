#include <iostream>
#include "SafeArray.h"
using namespace std;
int main()
{
    SafeArray a(100);
    a.pop(101,5);
    a.pop(55,6);
    cout<<a.load(110)<<endl;//测试是否报错
    cout<<a.load(55)<<endl;//测试添加的数能否输出
    return 0;
}
