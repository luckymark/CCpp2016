#pragma once
class Safearray
{
public:
	bool in(void);
	void input(int n);
	void output(int n);
private:
	int data[100];
	int now = 0;
};

