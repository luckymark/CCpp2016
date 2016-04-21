#include "queue.h"
#include <iostream>

bool Queue::is_Full()
{
	return (head == (tail + 1));
}

bool Queue::is_Empty()
{
	return (head == tail);
}

int Queue::pop() {
	head = (head + 1) % 100;
	return data[head];
}

void Queue::append(int num) {
	tail = (tail + 1) % 100;
	data[tail] = num;
}