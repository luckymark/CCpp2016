#include <iostream>
#include <Stack.h>
using namespace std;

int main()
{
    Stack stack(100);
    cout<<stack.isEmpty()<<endl;
    stack.push(1);
    cout<<stack.isEmpty()<<endl;
    stack.pop();
    cout<<stack.isEmpty()<<endl;
    for(int i=0;i<100;i++){
        stack.push(i);
    }
    cout<<stack.isFull()<<endl;
}
