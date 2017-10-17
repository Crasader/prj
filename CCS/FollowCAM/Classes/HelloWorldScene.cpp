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


	auto nyan = Sprite::create("Images/Nyan.png");
	nyan->setPosition(Vec2(50, 160));
	nyan->setScale(0.1);
	this->addChild(nyan);

	auto R1 = Sprite::create("Images/Nyan.png");
	R1->setPosition(Vec2(25, 160));
	R1->setScale(0.1);
	this->addChild(R1);

	auto R2 = Sprite::create("Images/Nyan.png");
	R2->setPosition(Vec2(960 - 25, 160));
	R2->setScale(0.1);
	this->addChild(R2);

	auto move = MoveBy::create(2, Vec2(480 * 2 - 100, 0));
	auto moveBack = move->reverse();
	auto seq = Sequence::create(move, moveBack, NULL);
	auto rep = RepeatForever::create(seq);

	nyan->runAction(rep);


	//
	this->runAction(Follow::create(nyan, Rect(0, 0, 480 * 2, 320)));
	//

    return true;
}
