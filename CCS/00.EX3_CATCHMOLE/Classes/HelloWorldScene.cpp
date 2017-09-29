#include "HelloWorldScene.h"
#include "stdlib.h"
#include "time.h"

USING_NS_CC;
Sequence * UpDownAction();

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

	auto wlayer = LayerColor::create(Color4B(0, 0, 0, 255));
	this->addChild(wlayer);

	/////////////////////////////

	srand(time(NULL));

	auto LowerGrass = Sprite::create("Images/grass_lower.png");
	LowerGrass->setAnchorPoint(Vec2(0,0));
	LowerGrass->setZOrder(100);
	this->addChild(LowerGrass);

	auto UpperGrass = Sprite::create("Images/grass_upper.png");
	UpperGrass->setAnchorPoint(Vec2(0, -1));
	UpperGrass->setZOrder(0);
	UpperGrass->setPosition(0, -1);
	this->addChild(UpperGrass);

	for (int i = 0; i < 3; i++)
	{
		auto Mole = Sprite::create("Images/mole_1.png");
		Mole->setAnchorPoint(Vec2(0.5, 0.5));
		Mole->setZOrder(10);
		Mole->setTag(10+i);

		Mole->setPosition(95 + 145 * i, 80);
		Mole->setScale(1);
		this->addChild(Mole);
	}

	/////////////////////////////

	doAction(10);
	doAction(11);
	doAction(12);

    return true;
}

Sequence * UpDownAction()
{
	Sequence *Action_UpDown = Sequence::create(
		EaseIn::create(MoveBy::create(0.50, Vec2(0, 100)),5),
		DelayTime::create(0.25),
		EaseOut::create(MoveBy::create(0.75, Vec2(0, -100)),2.5),
		NULL
	);
	return Action_UpDown;
}

void HelloWorld::doAction(int tag)
{
	auto Action_Rand = Sequence::create(
		DelayTime::create((rand() % 20)/10.0),
		UpDownAction(),
		CallFunc::create(CC_CALLBACK_0(HelloWorld::doAction, this ,tag)),
		NULL
	);
	getChildByTag(tag)->runAction(Action_Rand->clone());
}