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

	auto pLabel = LabelTTF::create(
		"블럭을 터치해서 드래그",
		"Arial", 20
	);
	pLabel->setPosition(Vec2(240, 280));
	pLabel->setColor(Color3B(0, 0, 0));
	this->addChild(pLabel,101);

	sprite = new Monster();
	sprite->setTexture("Images/stars2.png");
	sprite->setPosition(Vec2(240, 160) + Vec2(-80, 80));
	sprite->setColor(Color3B(150, 200, 255));

	sprite->color = Color3B(150, 200, 255);

	sprite->setPriority(30);
	this->addChild(sprite);

	sprite2 = new Monster();
	sprite2->setTexture("Images/stars2.png");
	sprite2->setPosition(Vec2(240, 160));
	sprite2->setColor(Color3B(255, 100, 255));

	sprite2->color = Color3B(255, 100, 255);

	sprite2->setPriority(20);
	this->addChild(sprite2);

	sprite3 = new Monster();
	sprite3->setTexture("Images/stars2.png");
	sprite3->setPosition(Vec2(0, 0));
	sprite3->setColor(Color3B(255, 255, 0));
	sprite3->setPriority(40);

	sprite3->color = Color3B(255, 255, 0);


	this->addChild(sprite3);

    return true;
}
