#pragma once
#include "cocos2d.h"
#include "Monster.h"

class Item : public Monster
{
public:
	char* setType(int _type);

	Item() {};
	Item(cocos2d::Layer *layer, cocos2d::Value *va);

	void Destroy();
};