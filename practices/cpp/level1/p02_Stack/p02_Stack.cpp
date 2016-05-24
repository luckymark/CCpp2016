#include <iostream>
#include "Stack.h"
using namespace std;

int main() {
	int num, cap;
	cin >> cap;
	Stack stack(cap);
	while (!stack.isFull()) {
		cin >> num;
		stack.append(num);
	}

	while (!stack.isEmpty()) {
		int n = stack.pop();
		cout << n << ' ';
	}
	system("pause");
}