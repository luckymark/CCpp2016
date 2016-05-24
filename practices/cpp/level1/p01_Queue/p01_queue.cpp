#include <iostream>
#include "queue.h"

using namespace std;

int main() {
	Queue queue;
	if (!queue.is_Full()) {
		queue.append(100);
	}
	if (!queue.is_Empty()) {
		cout << queue.pop();
	}
	system("pause");
	return 0;
}