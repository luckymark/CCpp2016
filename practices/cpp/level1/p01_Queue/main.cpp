#include <iostream>
#include <Queue.h>
using namespace std;

int main()
{
    Queue queue;
    cout<<queue.isEmpty()<<endl;
    queue.append(1);
    cout<<queue.isEmpty()<<endl;
    queue.pop();
    cout<<queue.isEmpty()<<endl;
    for(int i=0;i<99;i++){
        queue.append(i);
    }
    cout<<queue.isFull()<<endl;
    return 0;
}
