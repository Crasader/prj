#pragma once

#include "cocos2d.h"

class Monster : public cocos2d::Sprite
{
public:
	Monster();

	void setPriority(int fixedPriority);
	void setPriorityWithThis(bool useNodePriority);

	virtual void onEnter();
	virtual void onExit();

	cocos2d::Color3B color;

private:
	cocos2d::EventListener *_listener;
	int _fixedPriority;
	bool _useNodePriority;
};