#include <iostream>
#include "Stack.h"
using namespace std;
int main()
{
    Stack stack(123);
    for(int i=1;!stack.is_full();i++)
    {
        stack.push(i);
    }
    for(int i=1;!stack.is_empty();i++)
    {
        cout<<stack.pop()<<endl;//判断能否按预定的出栈
    }
    return 0;
}
