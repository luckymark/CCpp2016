#pragma once

class Switch
{
public:
	Switch();
	~Switch();
	virtual void set(bool onandoff);
	virtual bool get();
private:
	bool onandoff;
};

Switch::Switch()
{
}

Switch::~Switch()
{
}

inline void Switch::set(bool onandoff)
{
	Switch::onandoff = onandoff;
}

inline bool Switch::get()
{
	return onandoff;
}
