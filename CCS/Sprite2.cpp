#include "HelloWorldScene.h"
//#include "SimpleAudioEngine.h"

USING_NS_CC;

Scene* HelloWorld::createScene()
{
    return HelloWorld::create();
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    if ( !Scene::init() )
    {
        return false;
    }

	auto wlayer = LayerColor::create(Color4B(255, 255, 255, 255));
	this->addChild(wlayer);

	/////////////////////////////
/*
	auto parent = Sprite::create("Images/white-512x512.png");
	parent->setTextureRect(Rect(0, 0, 150, 150));
	parent->setPosition(Vec2(240, 160));
	parent->setColor(Color3B(0, 0, 255));
	this->addChild(parent);
*/
	auto pMan = Sprite::create("Images/grossini.png");
	pMan->setPosition(Vec2(240, 160));
	this->addChild(pMan);

	Size parentSize;
	parentSize = pMan->getContentSize();
	
	auto child = Sprite::create("Images/white-512x512.png");
	child->setTextureRect(Rect(0, 0, 50, 5));
	child->setColor(Color3B(255, 0, 0));
	child->setPosition(Vec2(parentSize.width / 2.0, parentSize.height + 10));

	pMan->addChild(child);

	child = Sprite::create("Images/white-512x512.png");
	child->setTextureRect(Rect(0, 0, 55, 10));
	child->setColor(Color3B(150, 150, 150));
	child->setPosition(Vec2(parentSize.width / 2.0, parentSize.height + 10));

	pMan->addChild(child);
	child->setLocalZOrder(-1);

	pMan->setPosition(Vec2(340, 100));
	
	//

	return true;
}
