#pragma once

#include"Switch.h"

class Light :public Switch
{
public:
	Light();
	~Light();
	virtual bool get();
	virtual void set(bool onandoff);
	int get_level();
	void set_level(int level);
private:
	int level;
};

Light::Light()
{
}

Light::~Light()
{
}

inline bool Light::get()
{
	return Switch::get();
}

inline void Light::set(bool onandoff)
{
	Switch::set(onandoff);
}

inline int Light::get_level()
{
	return level;
}

inline void Light::set_level(int level)
{
	Light::level = level;
}
