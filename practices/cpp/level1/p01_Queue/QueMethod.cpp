#include "Queue.h"
#include <iostream>
using namespace std;

void Queue::append() {
	cout << "���������ݣ�";
	int num;
	cin >> num;
	data[head] = num;
	head = (head + 1) % 100;
}

int Queue::pop() {
	cout << "���һ�������ǣ�" << data[tail] << endl;
	data[tail] = NULL;
	tail = (tail + 1) % 100;
	return data[tail - 1];
}

bool Queue::isEmpty() {
	return (head == tail);
}

bool Queue::isFull() {
	return ((head + 1) % 100 == tail);
}