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

	auto pMan = Sprite::create("Images/grossini.png");

	pMan->setPosition(Point(240, 160));

	this->addChild(pMan,2);


	auto p2 = Sprite::create("Images/grossinis_sister1.png");

	p2->setPosition(Point(250, 160));

	this->addChild(p2,1);

	p2->setLocalZOrder(3);


    return true;
}
