#include <iostream>
#include "Stack.h"
using namespace std;

int main() {
	int num, cap;
	cin >> cap;
	Stack stack;

	for (int tmp = 0; tmp <= cap - 1; tmp++) {
		cin >> num;
		stack.append(num);
	}

	while (!stack.isEmpty()) {
		int n = stack.pop();
		cout << n << ' ';
	}
	system("pause");
}