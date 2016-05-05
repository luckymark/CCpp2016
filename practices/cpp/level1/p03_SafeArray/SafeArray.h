#pragma once
#ifndef SafeArray
class SafeArray
{
public:
	SafeArray(int size);
	~SafeArray();
	void query(int mark);
	void edit(int mark);
	void add();
	bool isFull();
	bool isOver(int mark);
private:
	int *data;
	int tail = 0;
	int dataSize;
};
#endif // !SafeArray
