#include "HelloWorldScene.h"
//#include "SimpleAudioEngine.h"

USING_NS_CC;

#define SSL schedule_selector

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

	////////////////////////////
	nNum = 0;

	this->schedule(SSL(HelloWorld::callEveryFrame));
	this->schedule(schedule_selector(HelloWorld::myTickOnce), 3.0f);
	this->schedule(schedule_selector(HelloWorld::myTick), 1.0f);

    return true;
}

void HelloWorld::callEveryFrame(float f)
{
	nNum++;
	if (nNum > 60)
	{
		nNum = 1;
	}
	log("fps..%d", nNum);
}

void HelloWorld::myTick(float f)
{
	log("tick");
}

void HelloWorld::myTickOnce(float f)
{
	log("tickOnceAfterDealy");
}
