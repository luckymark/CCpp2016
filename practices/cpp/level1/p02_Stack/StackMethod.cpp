#include "Stack.h"
#include <iostream>
using namespace std;

Stack::Stack(int size):dataSize(size) {
	data = new int[dataSize];
	cout << "创建成功！" << endl;
}

Stack::~Stack() {
	delete [] data;
}

void Stack::append(){
	cout << "请输入数字：";
	int num;
	cin >> num;
	data[tail] = num;
	tail = tail + 1;
}

void Stack::pop() {
	cout << "出栈数字：" << data[tail - 1] << endl;
	data[tail - 1] = NULL;
	tail = tail - 1;
}

bool Stack::isEmpty() {
	return tail == 0;
}

bool Stack::isFull() {
	return tail == dataSize;
}