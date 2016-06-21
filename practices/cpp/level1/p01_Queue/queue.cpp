#include"queue.h"

void Queue::append(int item) {
	data[head] = item;
	head1 = (head + 1) % 100;
	head++;
}

int Queue::pop() {
	tail1 = (tail + 1) % 100;
	tail++;
	return data[tail - 1];
}

bool Queue::isEmpty() {
	return (head == tail);
}

bool Queue::isFull() {
	return(head == tail + 100);
}