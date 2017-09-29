#include "HelloWorldScene.h"
//#include "SimpleAudioEngine.h"

USING_NS_CC;
#define SSR schedule_selector

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
	
	auto item1 = MenuItemFont::create("start",
		CC_CALLBACK_1(HelloWorld::doStart, this));
	item1->setColor(Color3B::BLACK);

	auto item2 = MenuItemFont::create("pause",
		CC_CALLBACK_1(HelloWorld::doPause, this));
	item2->setColor(Color3B::BLACK);

	auto item3 = MenuItemFont::create("resume",
		CC_CALLBACK_1(HelloWorld::doResume, this));
	item3->setColor(Color3B::BLACK);
	
	auto item4 = MenuItemFont::create("change",
		CC_CALLBACK_1(HelloWorld::doChange, this));
	item4->setColor(Color3B::BLACK);

	auto item5 = MenuItemFont::create("stop",
		CC_CALLBACK_1(HelloWorld::doStart, this));
	item5->setColor(Color3B::BLACK);

	auto pMenu = Menu::create(item1, item2, item3, item4, item5, NULL);

	pMenu->alignItemsVertically();

	this->addChild(pMenu);

	bChange = false;

    return true;
}

void HelloWorld::doStart(Ref *pSender)
{
	this->schedule(SSR(HelloWorld::tick1), 1.0f);
	this->schedule(SSR(HelloWorld::tick2), 1.0f);
}
void HelloWorld::doPause(Ref *pSender)
{
	Director::getInstance()->getScheduler()->pauseTarget(this);
}
void HelloWorld::doResume(Ref *pSender)
{
	Director::getInstance()->getScheduler()->resumeTarget(this);
}
void HelloWorld::doChange(Ref *pSender)
{
	if (bChange == true)
	{
		bChange = false;
		this->unschedule(SSR(HelloWorld::tick2));
		this->schedule(SSR(HelloWorld::tick2), 2.0f);
	}
	else
	{
		bChange = true;
		this->unschedule(SSR(HelloWorld::tick2));
		this->schedule(SSR(HelloWorld::tick2), 3.0f);
	}
}
void HelloWorld::doStop(Ref *pSender)
{
	this->unschedule(SSR(HelloWorld::tick1));
	this->unschedule(SSR(HelloWorld::tick2));
}
void HelloWorld::tick1(float f)
{
	log("TICK1!");
}
void HelloWorld::tick2(float f)
{
	log("TICK2@");
}