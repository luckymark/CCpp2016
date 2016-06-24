#pragma once

#include"Iterator.h"

class Queue
	{
		friend class Iterator;
	public:
		Queue();
		void append(int item);
		int pop();
		bool isEmpty();
		bool isFull();
	private:
		int data[100];
		int head;
		int tail;
		int head1;
		int tail1;
	};