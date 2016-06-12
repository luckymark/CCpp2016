#ifndef STACK_H
#define STACK_H

#include<vector>
#include<iostream>
using namespace std;
class Stack
{
public:
    Stack();
    Stack(int length);
    void push(int item);
    int pop();
    bool isEmpty();
    bool isFull();
private:
    vector<int> data;
    int length = 100;

};

#endif // STACK_H
