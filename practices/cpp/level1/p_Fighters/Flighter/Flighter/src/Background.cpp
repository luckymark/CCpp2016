#include "Background.hpp"

Background::Background(float y):Flying(0,y,0,0.5,0,0,0)
{
}

Background::~Background()
{
}

void Background::ifBottom()
{
	if (getY() >= 700)
	{
		resetPosition(0, -5500);
	}
}
