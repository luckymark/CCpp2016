#ifndef _STACK_HPP
#define _STACK_HPP

#include <assert.h>
#include <stdio.h>

struct Node{
    int value;
    int *next;
};

class GeniusStack{
public:
    void push(int value);
    int top();
    void pop();
    bool empty();

    ~GeniusStack(){
        while(data != NULL){
            Node *nxt = data->next;
            delete nxt;
            data = nxt;
        }
    }
private:
    Node *data = NULL;
    int size = 0;
};

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
