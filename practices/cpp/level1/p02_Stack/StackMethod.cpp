#include "Stack.h"
#include <iostream>
using namespace std;

Stack::Stack(int size):dataSize(size) {
	data = new int[dataSize];
	cout << "�����ɹ���" << endl;
}

Stack::~Stack() {
	delete [] data;
}

void Stack::append(){
	cout << "���������֣�";
	int num;
	cin >> num;
	data[tail] = num;
	tail = tail + 1;
}

void Stack::pop() {
	cout << "��ջ���֣�" << data[tail - 1] << endl;
	data[tail - 1] = NULL;
	tail = tail - 1;
}

bool Stack::isEmpty() {
	return tail == 0;
}

bool Stack::isFull() {
	return tail == dataSize;
}