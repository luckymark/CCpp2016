#include <iostream>
#include "Queue.h"
using namespace std;
int main()
{
    Queue queue;
    for(int i=1;!queue.isFull();i++)
    {
        queue.append(i);
    }
    int n;
    if(!queue.isEmpty())
    {
        n=queue.pop();
    }
    cout<<n<<endl;//输出1，证明出列成功
    return 0;
}
