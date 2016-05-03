#include <iostream>
#include "Stack.h"
int main() {
    int capbility = 100;
    Stack stack(capbility);
    if (!stack.is_full()) {
        stack.append(10);
    }
    if (!stack.is_empty()) {
        std::cout<<stack.pop();
    }
    return 0;
}
