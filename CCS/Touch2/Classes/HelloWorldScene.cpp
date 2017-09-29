#include "HelloWorldScene.h"
//#include "SimpleAudioEngine.h"
#include <math.h>

USING_NS_CC;

bool OnTouch = false;

Scene* HelloWorld::createScene()
{
	return HelloWorld::create();
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
	if (!Scene::init())
	{
		return false;
	}

	auto wlayer = LayerColor::create(Color4B(255, 255, 255, 255));
	this->addChild(wlayer);

	/////////////////////////////


	pMan = Sprite::create("Images/grossini.png");
	pMan->setPosition(Vec2(240, 160));
	this->addChild(pMan);

	return true;
}

void HelloWorld::onEnter()
{
	Scene::onEnter();

	auto listener = EventListenerTouchAllAtOnce::create();

	listener->onTouchesBegan = CC_CALLBACK_2(HelloWorld::onTouchesBegan, this);
	listener->onTouchesMoved = CC_CALLBACK_2(HelloWorld::onTouchesMoved, this);
	listener->onTouchesEnded = CC_CALLBACK_2(HelloWorld::onTouchesEnded, this);

	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);
}

void HelloWorld::onExit()
{
	_eventDispatcher->removeEventListener(listener);

	Scene::onExit();
}

bool HelloWorld::onTouchesBegan(const std::vector<cocos2d::Touch*> &touches, Event *event)
{
	auto touchPoint = touches[0]->getLocation();
	touchPoint = this->convertToWindowSpace(touchPoint);

	log("onTouchBegan id = %d, x = %f, y = %f",
		touches[0]->getID(), touchPoint.x, touchPoint.y);

	bool bTouch = pMan->getBoundingBox().containsPoint(touchPoint);
	if (bTouch)
	{
		log("SPRITECLICKED");
		OnTouch = true;
	}
	return true;
}

void HelloWorld::onTouchesMoved(const std::vector<cocos2d::Touch*> &touches, Event *event)
{
	auto touchPoint = touches[0]->getLocation();
	touchPoint = this->convertToWindowSpace(touchPoint);

	//	log("onTouchMoved id = %d, x = %f, y = %f",
	//		touch->getID(), touchPoint.x, touchPoint.y);

}
void HelloWorld::onTouchesEnded(const std::vector<cocos2d::Touch*> &touches, Event *event)
{
	auto touchPoint = touches[0]->getLocation();
	touchPoint = this->convertToWindowSpace(touchPoint);

	//	log("onTouchEnded id = %d, x = %f, y = %f",
	//		touch->getID(), touchPoint.x, touchPoint.y);

	OnTouch = false;
}
void HelloWorld::onTouchesCancelled(const std::vector<cocos2d::Touch*> &touches, Event *event)
{
	auto touchPoint = touches[0]->getLocation();
	touchPoint = this->convertToWindowSpace(touchPoint);

	log("onTouchCancelled id = %d, x = %f, y = %f",
		touches[0]->getID(), touchPoint.x, touchPoint.y);
}