#pragma once
#include "cocos2d.h"

class block : public cocos2d::Sprite
{
public:
	int _type;
	//0. 6 Empty
	//1. 9 Block

	//2. 0 Goal
	//3. 5 Start

	int _X;
	int _Y;

	block() {};

	block(int type, int x, int y)
	{
		_type = type;
		this->setTexture("metaset10way.png");

		_X = x;
		_Y = y;

		Set();
	}

	void Set()
	{
		int temp = 6;

		switch (_type)
		{
			case 0: temp = 6; break;
			case 1: temp = 9; break;
			case 2: temp = 0; break;
			case 3: temp = 5; break;
		}

		this->setTextureRect
		(cocos2d::Rect((temp % 5) * 33, (temp / 5) * 33, 32, 32));
	}

	void ChangeSprite()
	{
		if (_type == 0)
			_type = 1;
		else
			_type = 0;

		Set();
	}


	void ChangeSprite(int x)
	{
		_type = x;
		Set();
	}

};