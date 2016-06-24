#include <iostream>
#include "Stack.h"

using namespace std;

int main() {
    Stack stack(10000);
    int n;
    if(!stack.isEmpty()) {
        n= stack.pop();
    }

    if(!stack.isFull()) {
        stack.push(100);
    }
   return 0;
}