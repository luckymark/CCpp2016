#include <iostream>
#include "safeArray.h"
using namespace std;

int main() {
	int size;
	cin >> size;
	SafeArray a(size);
	a.set(5, 7);
	int x = a.get(5);
	cout << x;
	x = a.get(100);
	cout << x;
	system("pause");
	return 0;
}