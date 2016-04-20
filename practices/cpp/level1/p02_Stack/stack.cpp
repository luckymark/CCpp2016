#include"stack.h"
void Stack::push(int item) {
	data[head] = item;
	head++;
}
int Stack::pop() {
	tail--;
	return data[tail + 1];
}
bool Stack::isEmpty() {
	return tail == 0;
}
bool Stack::isFull(int num) {
	return head ==num+1;
}