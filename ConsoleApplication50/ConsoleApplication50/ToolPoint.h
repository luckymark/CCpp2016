#pragma once
#include"Plane.h"
#include"Texture.h"
#include"Bullet.h"
class ToolPoint:public Plane
{
public:
	void heartBeat();
	ToolPoint(float x, float y);
private:
	Texture A;//µÀ¾ß²ÄÖÊ
};

