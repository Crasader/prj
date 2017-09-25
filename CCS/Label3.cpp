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

	auto pLabel1 = LabelTTF::create("Hello World!!", "Arial", 34);
	pLabel1->setPosition(Point(240, 250));
	pLabel1->setColor(Color3B(0, 0, 0));
	this->addChild(pLabel1);

	auto pLabel2 = LabelBMFont::create("HELLO!", "futura-48.fnt");
	pLabel2->setPosition(Point(240, 150));
	this->addChild(pLabel2);

	auto pLabel3 = LabelAtlas::create("1234", "fps_images.png", 16, 32, '.');
	pLabel3->setPosition(Point(240, 50));
	this->addChild(pLabel3);

    return true;
}
