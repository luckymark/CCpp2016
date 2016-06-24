#pragma once

#include"Switch.h"

class Fun :public Switch
{
public:
	Fun();
	~Fun();
	void set_speed(int speed);
	int get_speed();
	virtual void set(bool onandoff);
	virtual bool get();
private:
	int speed;
};

Fun::Fun()
{
}

Fun::~Fun()
{
}

inline void Fun::set_speed(int speed)
{
	Fun::speed = speed;
}

inline int Fun::get_speed()
{
	return speed;
}

inline void Fun::set(bool onandoff)
{
	Switch::set(onandoff);
	if (onandoff == 1)
	{
		speed = 1;
	}
	else
	{
		speed = 0;
	}
}

inline bool Fun::get()
{
	return Switch::get();
}
