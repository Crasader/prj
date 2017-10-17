#pragma once
#include "cocos2d.h"

class Monster : public cocos2d::Sprite
{
public:
	std::string _addr;
	int _type; cocos2d::Layer *_layer;

	Monster() {};
	Monster(cocos2d::Layer *layer, cocos2d::Value *va, cocos2d::RepeatForever* Animation);

	char* setType(int _type);
	void Destroy();
};