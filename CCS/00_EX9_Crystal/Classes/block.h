#pragma once

#include "cocos2d.h"

class block : public cocos2d::Sprite
{
public:
	int X, Y;//보드상의 위치
	
	int _down;
	int _type;

	block();
	block(int _type, int X, int Y);
};