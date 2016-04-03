#ifndef _STACK_HPP
#define _STACK_HPP

#include <assert.h>

class Stack{
public:
	Stack(int maxSize){
		data = new int[maxSize];
		assert(maxSize < 1e7); // Memory is limit
	}
	~Stack(){
		delete [] data;
	}
	void push(int value);
	bool empty();
	int top();
	void pop();
private:
	int *data,_top = 0;
};

#endif
