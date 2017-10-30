#pragma once
#include "cocos2d.h"
using namespace cocos2d;

class AstarNode : public Sprite
{
public:
	AstarNode *_ParentNode;
	int _X, _Y;

	int StackedDistance = 0;
	int GoalDistance = 0;
	int FullDistance = 0;

	AstarNode() {};
	AstarNode(int X, int Y)
	{
		_X = X; _Y = Y;
	}
	AstarNode(int X, int Y,AstarNode *Parent)
	{
		_ParentNode = Parent;
		AstarNode(X, Y);
	}


	void ShowLabel()
	{
		char _str[100];
		sprintf(_str, "%d", FullDistance);

		auto typeStr = cocos2d::LabelTTF::create(
			_str, "Arial", 16);
		typeStr->setTag(1);
		typeStr->setZOrder(100);
		typeStr->setAnchorPoint(cocos2d::Vec2(0.5, 0.5));
		typeStr->setPosition(cocos2d::Vec2(-16, 32));
		this->addChild(typeStr);

		//

		sprintf(_str, "%d", StackedDistance);

		auto typeStr2 = cocos2d::LabelTTF::create(
			_str, "Arial", 16);
		typeStr2->setTag(1);
		typeStr2->setZOrder(100);
		typeStr2->setAnchorPoint(cocos2d::Vec2(0.5, 0.5));
		typeStr2->setPosition(cocos2d::Vec2(-16, -16));
		this->addChild(typeStr2);

		//

		sprintf(_str, "%d", GoalDistance);

		auto typeStr3 = cocos2d::LabelTTF::create(
			_str, "Arial", 16);
		typeStr3->setTag(1);
		typeStr3->setZOrder(100);
		typeStr3->setAnchorPoint(cocos2d::Vec2(0.5, 0.5));
		typeStr3->setPosition(cocos2d::Vec2(24, -16));
		this->addChild(typeStr3);
	}
};