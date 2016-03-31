#include "Stack.hpp"

void Stack::push(int value){
	data[_top] = value;
	_top++;
}
bool Stack::empty(){
	return _top == 0;
}
int Stack::top(){
	assert(!this->empty());
	return data[_top-1];
}
void Stack::pop(){
	assert(!this->empty());
	--_top;
}