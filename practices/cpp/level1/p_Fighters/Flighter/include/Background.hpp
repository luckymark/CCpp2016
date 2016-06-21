#pragma once

#include<SFML\Graphics.hpp>
#include"Flying.hpp"
#include<iostream>
#include<string>

class Background:public Flying
{
public:
	Background(float y);
	~Background();
	void ifBottom();
private:
};