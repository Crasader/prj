
#include "Item.h"
#include "HelloWorldScene.h"
#include "Singleton.h"


Item::Item(cocos2d::Layer *layer, cocos2d::Value *va)
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
	//auto D = Sprite::createWithSpriteFrameName("W_Sword015.png");
	_addr = setType(va->asValueMap()["ItemType"].asInt());
	//auto D = Sprite::createWithSpriteFrameName(setType(va->asValueMap()["ItemType"].asInt()));
	auto D = Sprite::createWithSpriteFrameName(_addr);
	D->setAnchorPoint(cocos2d::Vec2(0, 0));
	D->setPosition(cocos2d::Vec2(0, 0));

	this->addChild(D);

}

char* Item::setType(int type)
{
	_type = type;

	if (_type == 1)
	{
		return("W_Sword015.png");
	}
	else if (_type == 2)
	{
		return("W_Mace008.png");
	}
	else if (_type == 3)
	{
		return("W_Sword001.png");
	}
	else if (_type == 4)
	{
		return("I_Key02.png");
	}
	else if (_type == 5)
	{
		return("I_Chest01.png");
	}

	return("");
}

void Item::Destroy()
{
	Singleton::getInstance()->Items.eraseObject(this);
	_layer->removeChild(this);

	free(this);
}