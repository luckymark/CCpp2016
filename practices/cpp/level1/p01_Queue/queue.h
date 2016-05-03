#pragma once
class Queue {

public:
	bool is_Full();
	bool is_Empty();
	int pop();
	void append(int num);
private:
	int data[100];
	int head = 0;
	int tail = 0;
};