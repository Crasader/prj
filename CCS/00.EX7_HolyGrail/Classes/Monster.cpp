#include "Monster.h"
#include "HelloWorldScene.h"
#include "Singleton.h"


Monster::Monster(cocos2d::Layer *layer,cocos2d::Value *va, cocos2d::RepeatForever* Animation)
{
	_layer = layer;
	std::string _addr = "Images/blacks.png";
	this->setScale(1);
	this->setAnchorPoint(cocos2d::Vec2(0, 0));	
	this->setTexture(_addr);
	this->setPosition(cocos2d::Vec2(va->asValueMap()["x"].asInt(),
		va->asValueMap()["y"].asInt()));
	_layer->addChild(this);

	//setType(va->asValueMap()["MonsterType"].asInt())
	auto D = Sprite::createWithSpriteFrameName(setType(va->asValueMap()["MonsterType"].asInt()));
	D->setAnchorPoint(cocos2d::Vec2(0, 0));
	D->setPosition(cocos2d::Vec2(0, 0));

	this->addChild(D);

	D->runAction(Animation->clone());
}

char* Monster::setType(int type)
{
	_type = type;

	if (_type == 1)
	{
		return("Demon1.png");
	}
	else if (_type == 2)
	{
		return("Jelly1.png");
	}
	else if (_type == 3)
	{
		return("Wolf1.png");
	}

	return("");
}

void Monster::Destroy()
{
	Singleton::getInstance()->Monsters.eraseObject(this);
	_layer->removeChild(this);

	free(this);
}