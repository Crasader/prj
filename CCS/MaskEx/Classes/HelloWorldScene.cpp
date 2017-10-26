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

	auto mask = Sprite::create("Images/nyan.png");
	mask->setScale(0.4f);

	auto content = Sprite::create("Images/Calendar3.png");

	auto clipper = ClippingNode::create();
	clipper->setStencil(mask);
	clipper->setAlphaThreshold(0.05f);
	clipper->setPosition(Vec2(240, 160));
	clipper->addChild(content);

	this->addChild(clipper);

    return true;
}
