#pragma once
class SafeArray
{
private:
	int *data;
	int pos;
public:
	SafeArray(int n);
	~SafeArray();
	void get(int n);
	void set(int p,int n);
	bool judge(int n, int max);
};