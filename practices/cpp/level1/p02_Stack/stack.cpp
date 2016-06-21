#include"stack.h"

Stack::Stack(int x)
{
	quantity = x;
}

int Stack::pop()
{
	head--;
	return data[head];
}

int Stack::push(int item)
{
	data[head] = item;
	head++;;
	return 0;
}

bool Stack::isEmpty()
{
	return(head == tail);
}

bool Stack::isFull()
{
	return (head == tail + quantity);
}
