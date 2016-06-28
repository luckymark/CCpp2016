#include "Stack.h"
#include <iostream>
using namespace std;
int main()
{
	Stack<int>test(10);
	test.push(1);
	test.push(2);
	test.push(3);
	while (!test.isEmpty())
		cout << test.pop() << ' ' << endl;
	return 0;
}