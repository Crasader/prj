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

	auto pLabel = LabelTTF::create("Hello World!", "Arial", 64);

	pLabel->setPosition(Point(240, 160));

	pLabel->setColor(Color3B(0, 0, 0));

	pLabel->setOpacity(255);

	this->addChild(pLabel);

	//
	pLabel = LabelTTF::create("abcdefg :D\nqie!!", "Arial", 32);

	pLabel->setRotation3D(Vec3(30, 0, 0));

	pLabel->setPosition(Point(240, 80));

	pLabel->setColor(Color3B(255, 0, 255));

	pLabel->setOpacity(255);

	this->addChild(pLabel);

	//
	pLabel = LabelTTF::create("Such Cocos", "Arial", 22);

	pLabel->setRotation3D(Vec3(0, 40, 0));

	pLabel->setPosition(Point(120, 230));

	pLabel->setColor(Color3B(255, 0, 255));

	pLabel->setOpacity(255);

	this->addChild(pLabel);

	pLabel = LabelTTF::create("So C++", "Arial", 48,Size(300,200),TextHAlignment::CENTER, TextVAlignment::CENTER);

	pLabel->setRotation3D(Vec3(-40, -30, 0));

	pLabel->setPosition(Point(380, 280));

	pLabel->setColor(Color3B(0, 0, 255));

	pLabel->setOpacity(255);

	this->addChild(pLabel);

	pLabel = LabelTTF::create("동해물과백두산이마르고닳도록하느님이보우하사우리나라만세", 
		"Arial", 48, Size(300, 200), TextHAlignment::CENTER, TextVAlignment::CENTER);

	pLabel->setRotation3D(Vec3(0, 0, 0));

	pLabel->setPosition(Point(240, 200));

	pLabel->setColor(Color3B(0, 0, 0));

	pLabel->setOpacity(255);

	this->addChild(pLabel);

    return true;
}
