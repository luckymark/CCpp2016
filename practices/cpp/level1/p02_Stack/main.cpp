#include<iostream>
#include"stack.h"
using namespace std;
int main() {
    int num;
    cout << "input the size of the stack" << endl;
    cin >> num;
    Stack s(num);
    while (!s.isFull(num)) {
    	s.push(100);
    }
    while (!s.isEmpty()) {
    	int n;
    	n = s.pop();
	cout << n << endl
    }
    system("pause");
}
