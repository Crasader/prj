#include "HelloWorldScene.h"
//#include "SimpleAudioEngine.h"

USING_NS_CC;

Scene* HelloWorld::createScene()
{
    return HelloWorld::create();
}

Vec2 HelloWorld::Vec21(float x, float y)
{
	Vec2 origin = Director::getInstance()->getVisibleOrigin();
	if (y >= Director::getInstance()->getWinSize().height)
	{
		return Vec2(x + origin.x, y - origin.y);
	}	
	else
		return Vec2(x + origin.x, y + origin.y);
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

	Size size1 = Director::getInstance()->getWinSize();
	Size size2 = Director::getInstance()->getVisibleSize();

	log("SIZE1 : %f...%f", size1.width, size1.height);
	log("SIZE2 : %f...%f", size2.width, size2.height);

	auto pBack = Sprite::create("HelloWorld.png");
	pBack->setPosition(Vec2(size1.width / 2, size1.height / 2));
	this->addChild(pBack);

	auto pBox1 = Sprite::create("blocks.png");
	pBox1->setPosition(Vec2(0, size1.height / 2));
	this->addChild(pBox1);


	auto pBox2 = Sprite::create("blocks.png");
	pBox2->setPosition(Vec2(size1.width, size1.height / 2));
	this->addChild(pBox2);

	////////////////////////////////////////////////

	auto pBox31 = Sprite::create("blocks.png");
	pBox31->setPosition(Vec2(size1.width/2 - 50,0));
	this->addChild(pBox31);

	auto pBox32 = Sprite::create("blocks.png");
	pBox32->setPosition(Vec21(size1.width / 2 + 50, 0));
	this->addChild(pBox32);

	////////////////////////////////////////////////////

	auto pBox41 = Sprite::create("blocks.png");
	pBox41->setPosition(Vec2(size1.width / 2 - 50, size1.height));
	this->addChild(pBox41);

	auto pBox42 = Sprite::create("blocks.png");
	pBox42->setPosition(Vec21(size1.width / 2 + 50, size1.height));
	this->addChild(pBox42);

    return true;
}
