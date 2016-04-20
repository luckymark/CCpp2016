#include<iostream>
#include"queue.h"
using namespace std;
int main() {
	Queue queue;
	while(!queue.isFull()) {
		queue.attend(100);
	}
	int n;
	while (!queue.isEmpty()) {
		n = queue.pop();
		cout << n << endl;
	}
	system("pause");
}