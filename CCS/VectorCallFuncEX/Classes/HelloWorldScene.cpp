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

	Vector<FiniteTimeAction*> vact;

	for (int i = 0; i < 5; i++)
	{
		auto act1 = DelayTime::create(3.0f);
		auto act2 = CallFunc::create(CC_CALLBACK_0(HelloWorld::callback1, this, i));

		vact.pushBack(act1);
		vact.pushBack(act2);
	}

	auto action = Sequence::create(vact);
	this->runAction(action);

	/////////////////////////////

    return true;
}

void HelloWorld::callback1(int num)
{
	log("%d", num);
}