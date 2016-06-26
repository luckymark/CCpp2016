#include "SafeArray.h"
#include <iostream>
#define SIZE 100
using namespace std;
int main()
{
	SafeArray<int> safeArray(SIZE);
	safeArray.insert(5, 100);
	int x = safeArray.get(5);
	cout << x << ' ' << safeArray[5] << endl;
	return 0;
}