#include "Type.hpp"

Type::Type(std::string str)
{
	ifConceled = 0;
	this->setString(str);
	this->setCharacterSize(24);
	this->setColor(sf::Color::White);
	this->setStyle(sf::Text::Bold);
}

Type::~Type()
{
}

void Type::setifConceled(bool ifConceled)
{
	Type::ifConceled = ifConceled;
}

bool Type::getifConceled()
{
	return ifConceled;
}
