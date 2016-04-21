#include <iostream>
#include "IntStack.h"
using namespace std;
int main()
{
    int n;
    cin >> n ;
    IntStack stack(n,0);
    if (!stack.isFull(n)){
         stack.push(100);
    }
    int m;
    if (!stack.isEmpty()){
         m=stack.pop();
    }
    return 0;
}
