#pragma once

#include"SFML\Graphics.hpp"
#include<string>
#include<iostream>

class Type:public sf::Text
{
public:
	Type(std::string str);
	~Type();
	void setifConceled(bool ifConceled);
	bool getifConceled();
private:
	bool ifConceled;
};