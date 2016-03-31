#ifndef _STACK_HPP
#define _STACK_HPP

class Stack{
public:
	Stack(int maxSize){
		data = new int[maxSize];
		assert(maxSize < 1e7); // Memory is limit
		top = 0;
	}
	~Stack(){
		delete [] data;
	}
	void push(int value);
	bool empty();
	int top();
	void pop();
private:
	int *data,top;
};

#endif