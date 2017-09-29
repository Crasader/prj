#include "HelloWorldScene.h"
//#include "SimpleAudioEngine.h"

USING_NS_CC;

#define GroundY 100
#define Fly 80

bool isDown = false;
bool isJump = false;
int JumpCount = 0;
double JumpP = 0;

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

	/////////////////////////////19*2 & 30x30

	auto texture = Director::getInstance()->getTextureCache()->addImage("Images/Runner.png");

	Runner = Sprite::createWithTexture(texture, Rect(0, 0, 85, 121));
	Runner->setTextureRect(Rect(0, 0, 30, 30));
	Runner->setPosition(Vec2(100, GroundY));
	Runner->setScale(1.75);
	this->addChild(Runner);

	auto Animation = Animation::create();
	Animation->setDelayPerUnit(1.0/30);

	for (int i = 0; i < 18; i++)
	{
		Animation->addSpriteFrameWithTexture(texture, Rect(30 * i, 0, 30, 30));
	}

	auto Animate = Animate::create(Animation);
	RunAni = RepeatForever::create(Animate->clone());

	//

	//auto Animation2 = Animation::create();
	//Animation2->setDelayPerUnit(1.0 / 30);
	//for (int i = 18; i < 27; i++)
	//{
	//	Animation2->addSpriteFrameWithTexture(texture, Rect(30 * (i%19), 30 * (i/19), 30, 30));
	//}

	//auto Animate2 = Animate::create(Animation2);
	//JumpAni = RepeatForever::create(Animate2->clone());

	Runner->runAction(RunAni);
	this->schedule(schedule_selector(HelloWorld::callEveryFrame), 1 / 60);

    return true;
}

void HelloWorld::callEveryFrame(float a)
{
	if (isJump)
	{
		int gravity;
		JumpP = JumpP - 0.25;

		if (isDown)
			gravity = JumpP;
		else
			gravity = 8-JumpP;

		Runner->setPosition(Vec2(Runner->getPosition().x,
			Runner->getPosition().y + gravity));

		if (GroundY + Fly * JumpCount < Runner->getPosition().y)
		{	//최고높이 도달
			isDown = true;
		}
		else if (GroundY >  Runner->getPosition().y)
		{	//지상높이 도달
			Runner->setPosition(Vec2(Runner->getPosition().x,
				GroundY));

			isDown = false;
			isJump = false;
			JumpCount = 0;
			JumpP = 0;
		}
	}
}

void HelloWorld::onEnter()
{
	Scene::onEnter();

	auto listener = EventListenerTouchOneByOne::create();
	listener->setSwallowTouches(true);

	listener->onTouchBegan = CC_CALLBACK_2(HelloWorld::onTouchBegan, this);
	
	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);
}

bool HelloWorld::onTouchBegan(Touch *touch, Event *event)
{
	if (!isDown && JumpCount == 0)
	{
		JumpCount++;
		isJump = true;
	}
	else if (!isDown && JumpCount == 1)
	{
		JumpCount++;
		JumpP -= 5;
	}

	return true;
}
