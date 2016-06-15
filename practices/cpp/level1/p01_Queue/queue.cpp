#include "Queue.h"
#define NUM 100
void Queue::append(int item)
{
	data[head]=item;
	head=(head+1)%NUM;
}
int Queue::pop()
{
	tail=(tail+1)%NUM;
	return data[tail-1];
}
bool Queue::isEmpty()
{
	return(head==tail);
}
bool Queue::isFull()
{
	return ((head+1)%NUM==tail);
}

