#include "stdafx.h"
#include "Stack.h"
bool Stack::isFull(void){
	return(now == 100);
}
bool Stack::isEmpty(void) {
	return(now == 0);
}
void Stack::push(int n) {
	if (!isFull()) {
		data[now] = n;
		now++;
	}
}
void Stack::pop(void) {
	if (!isEmpty())
		now--;
}