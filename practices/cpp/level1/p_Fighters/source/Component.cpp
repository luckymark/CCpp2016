#include "Component.hpp"

GUI::Component::Component() :mIsActive(false), mIsSelected(false) {

}

GUI::Component::~Component()
{
}


bool GUI::Component::isSelected() const
{
	return mIsSelected;
}

void GUI::Component::select()
{
	mIsSelected = true;
}

void GUI::Component::deselect()
{
	mIsSelected = false;
}

bool GUI::Component::isActivate() const
{
	return mIsActive;
}

void GUI::Component::activate()
{
	mIsActive = true;
}

void GUI::Component::deactivate()
{
	mIsActive = false;
}

