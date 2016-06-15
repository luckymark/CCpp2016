#pragma once
#include <sstream>
#include <cmath>
#include <SFML\Graphics.hpp>

template <typename T>
std::string toString(const T& value)
{
	std::stringstream stream;
	stream << value;
	return stream.str();
}

template <typename T>
void setCenterOrigin(T &element) {
	sf::FloatRect bounds = element.getLocalBounds();
	element.setOrigin(std::floor(bounds.left + bounds.width / 2.f), std::floor(bounds.top + bounds.height / 2.f));
}