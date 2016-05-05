#include "SafeArray.h"
#include <iostream>

using namespace std;

SafeArray::SafeArray(int size) :dataSize(size) {
	data = new int[dataSize];
	cout << "�����ɹ���" << endl;
}

SafeArray::~SafeArray() {
	delete[] data;
}

void SafeArray::add() {
	cout << "����Ǳ�: " << tail << "  ����������: ";
	int num;
	cin >> num;
	data[tail] = num;
	tail++;
}

void SafeArray::query(int mark) {
	cout << "����Ǳ�: " << mark << "  ����Ϊ�� " << data[mark] << endl;
}

void SafeArray::edit(int mark) {
	cout << "����Ǳ�: " << mark << "  ԭ����Ϊ�� " << data[mark] << endl;
	cout << "Ҫ�޸�Ϊ��  ";
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