#include "SafeArray.h"
#include <iostream>

using namespace std;

SafeArray::SafeArray(int size) :dataSize(size) {
	data = new int[dataSize];
	cout << "创建成功！" << endl;
}

SafeArray::~SafeArray() {
	delete[] data;
}

void SafeArray::add() {
	cout << "数组角标: " << tail << "  请输入数字: ";
	int num;
	cin >> num;
	data[tail] = num;
	tail++;
}

void SafeArray::query(int mark) {
	cout << "数组角标: " << mark << "  数字为： " << data[mark] << endl;
}

void SafeArray::edit(int mark) {
	cout << "数组角标: " << mark << "  原数字为： " << data[mark] << endl;
	cout << "要修改为？  ";
	int num;
	cin >> num;
	data[mark] = num;
}

bool SafeArray::isFull() {
	return tail == dataSize;
}

bool SafeArray::isOver(int mark) {
	return mark > dataSize - 1;
}