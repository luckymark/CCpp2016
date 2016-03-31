#include <iostream>
#include "Stack.h"

using namespace std;

int main() {
    Stack stack;
    int n;
    if(!stack.isEmpty()) {
        n= stack.pop();
    }

    if(!stack.isFull()) {
        stack.push(100);
    }
   return 0;
}