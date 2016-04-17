#include <iostream>
#include "queue.h"
#include "Stack.h"

using namespace std;

int main()
{
    Queue queue;
    int n;
    cin>>n;
    if(!queue.isFull()){
        queue.append(n);
    }
    if(!queue.isEmpty()){
        n=queue.pop();
    }
    cout<<n;
    Queue *p=new Queue();
    p->append(100);
    p=&queue;
    return 0;
}
