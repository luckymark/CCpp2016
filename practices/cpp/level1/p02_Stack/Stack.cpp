#include "Stack.hpp"
void Stack::push(int value){
	data[top] = value;
	top++;
}
bool Stack::empty(){
	return top == 0;
}
int Stack::top(){
	assert(top);
	return data[top-1];
}
void Stack::pop(){
	assert(top);
	--top;
}