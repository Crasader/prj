#pragma once
#include "cocos2d.h"

class Card : public cocos2d::Sprite
{
public :
	int _type;
	int _number;
	bool _isGone;
	cocos2d::Sprite *_Back;

	Card() { _isGone = false; };
	Card(int type, int number,cocos2d::Sprite *Back)
	{
		Card();

		_type = type;
		_number = number;
		_Back = Back;
	}
};