#include "Stack.h"
Stack::Stack(int capbility)
{
	data=new int[capbility];
	last=capbility;
}
Stack::Stack()
{
	delete[]data;
}
void Stack::push(int item) 
{
    data[first] = item;
    first++;
}
int Stack::pop() 
{
    last--;
    return data[last+1];
}
bool Stack::isEmpty() 
{
    return last==0;
}
bool Stack::isFull(int capbility)
{
    return first==capbility+1;
}
