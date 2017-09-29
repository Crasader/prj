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
	pMan->setPosition(Vec2(240, 160));
	this->addChild(pMan);

	auto animation = Animation::create();
	animation->setDelayPerUnit(0.1f);

	char Resorce[100];

	for (int i = 1; i < 10; i++)
	{
		sprintf(Resorce, "Animations/grossini_dance_0%d.png", i);
		animation->addSpriteFrameWithFile(Resorce);
	}
	for (int i = 10; i < 15; i++)
	{
		sprintf(Resorce, "Animations/grossini_dance_%d.png", i);
		animation->addSpriteFrameWithFile(Resorce);
	}

	auto animate = Animate::create(animation);
	auto rep = RepeatForever::create(animate->clone());

	pMan->runAction(rep);



    return true;
}
