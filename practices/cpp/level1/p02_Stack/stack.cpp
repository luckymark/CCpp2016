#include"stack.h"
Stack::Stack(int n, int head) :head(head)
{
	data = new int[n];
}
void Stack::push(int n)
{
	data[head] = n;
	head++;
}
int Stack::pop()
{
	int middle = head;
	head--;
	return data[middle];
}
bool Stack::isEmpty()
{
	return head == 0;
}
bool Stack::isFull(int n)
{
	return head == n;
}
Stack::~Stack()
{
	delete []data;
}