#include <iostream>
#include "Queue.h"
using namespace std;
int main()
{
    Queue queue;
    if (queue.isFull()){
        queue.append(100);
    }
    int n;
    if (queue.isEmpty()){
        n=queue.pop();
    }
    return 0;
}
