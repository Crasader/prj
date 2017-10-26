#include "block.h"
using namespace cocos2d;

block::block(int type, int getX, int getY)
{
	X = getX;  Y = getY;
	_type = type;
	if (_type != 10)
	{
		char _addr[100] = "crystals/resources-auto/%d.png";
		sprintf(_addr, _addr, _type);
		this->setTexture(_addr);
	}
	else
	{
		char _addr[100] = "crystals/resources-auto/bomb.png";
		sprintf(_addr, _addr, _type);
		this->setTexture(_addr);

		auto light = Sprite::create("crystals/resources-auto/bomb-hi.png");
		light->setPosition(40, 40);
		light->setOpacity(0);

		auto act = Sequence::create(
			FadeIn::create(0.5),
			FadeOut::create(0.5),
			NULL);

		auto rep = RepeatForever::create(act);
		light->runAction(rep);

		this->addChild(light);
	}
	this->setZOrder(2);
	this->setAnchorPoint(Vec2(0.5, 0.5));
	this->setRotation(180);

	_down = 0;
}