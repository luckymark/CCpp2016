#include <iostream>
#include "Stack.h"
using std::cout;
using std::endl;
int main() {
    Stack<int, 5> myStack;
    cout << myStack.isEmpty() << " " << myStack.isFull() << endl;
    for (int i = 0; i < 5; ++i) {
        myStack.push(5 * i);
    }
    cout << myStack.isEmpty() << " " << myStack.isFull() << endl;
    cout << myStack.pop() << endl;
    cout << myStack.isEmpty() << " " << myStack.isFull() << endl;
    return 0;
}
