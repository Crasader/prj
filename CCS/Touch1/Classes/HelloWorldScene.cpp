﻿#include "HelloWorldScene.h"
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
    if ( !Scene::init() )
    {
        return false;
    }

	auto wlayer = LayerColor::create(Color4B(255, 255, 255, 255));
	this->addChild(wlayer);

	/////////////////////////////


	pMan = Sprite::create("Images/grossini.png");
	pMan->setPosition(Vec2(240, 160));
	this->addChild(pMan);

	pCircleBase = Sprite::create("Images/moveCircle.png");
	pCircleBase->setPosition(Vec2(70, 70));
	pCircleBase->setAnchorPoint(Vec2(0.5, 0.5));
	pCircleBase->setScale(0.3);
	this->addChild(pCircleBase);

	pCircleArrow = Sprite::create("Images/moveCircle4.png");
	pCircleArrow->setPosition(Vec2(255, 260));
	pCircleArrow->setAnchorPoint(Vec2(0, 0));
	pCircleArrow->setScale(1);
	pCircleBase->addChild(pCircleArrow);

    return true;
}

void HelloWorld::onEnter()
{
	Scene::onEnter();

	auto listener = EventListenerTouchOneByOne::create();
	listener->setSwallowTouches(true);

	listener->onTouchBegan = CC_CALLBACK_2(HelloWorld::onTouchBegan, this);
	listener->onTouchMoved = CC_CALLBACK_2(HelloWorld::onTouchMoved, this);
	listener->onTouchEnded = CC_CALLBACK_2(HelloWorld::onTouchEnded, this);

	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);
}

void HelloWorld::onExit()
{
	_eventDispatcher->removeEventListener(listener);

	Scene::onExit();
}

bool HelloWorld::onTouchBegan(Touch *touch, Event *event)
{
	auto touchPoint = touch->getLocation();

	log("onTouchBegan id = %d, x = %f, y = %f",
		touch->getID(), touchPoint.x, touchPoint.y);

	bool bTouch = pCircleBase->getBoundingBox().containsPoint(touchPoint);
	if (bTouch)
	{
		log("SPRITECLICKED");
		OnTouch = true;
	}
	return true;
}

void HelloWorld::onTouchMoved(Touch *touch, Event *event)
{
	auto touchPoint = touch->getLocation();

//	log("onTouchMoved id = %d, x = %f, y = %f",
//		touch->getID(), touchPoint.x, touchPoint.y);
	
	bool bTouch = pCircleBase->getBoundingBox().containsPoint(touchPoint);

	if (OnTouch == true)
	{
		float degreeA =
			atan2(pCircleBase->getPosition().y - touchPoint.y,
				pCircleBase->getPosition().x - touchPoint.x);

		degreeA = degreeA * 180 / M_PI;
		float degree = 225 - degreeA;

		pCircleArrow->setRotation(degree);
		//log("Degree : %f",degree);

		pMan->setPosition(
			Vec2(pMan->getPosition().x + sinf(CC_DEGREES_TO_RADIANS(270 - degreeA)),
				pMan->getPosition().y + cosf(CC_DEGREES_TO_RADIANS(270 - degreeA))));
		log("cos : %f", cos(degreeA));
/*
		auto act = Place::create(
			Vec2(pMan->getPosition().x + cos(degreeA),
				pMan->getPosition().y + sin(degreeA)));

		pMan->runAction(act);*/
	}

	if (bTouch)
	{
		log("SPRITECLICKED");
		OnTouch = true;
	}

}
void HelloWorld::onTouchEnded(Touch *touch, Event *event)
{
	auto touchPoint = touch->getLocation();

//	log("onTouchEnded id = %d, x = %f, y = %f",
//		touch->getID(), touchPoint.x, touchPoint.y);

	OnTouch = false;
}
void HelloWorld::onTouchCancelled(Touch *touch, Event *event)
{
	auto touchPoint = touch->getLocation();

	log("onTouchCancelled id = %d, x = %f, y = %f",
		touch->getID(), touchPoint.x, touchPoint.y);
}