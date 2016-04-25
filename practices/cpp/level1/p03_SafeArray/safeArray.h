#pragma once
class SafeArray {
public:
	SafeArray(int cap);
	int get(int location);
	void set(int location, int num);

private:
	int *data;
	int size;
};