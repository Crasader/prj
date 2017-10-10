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

	pMan = Sprite::create("Images/pea.png");
	pMan->setPosition(Vec2(240, 160));
	pMan->setScale(3.0f);
	this->addChild(pMan);
	bSelect = false;

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
	_eventDispatcher->removeAllEventListeners();
	Scene::onExit();
}

bool HelloWorld::onTouchBegan(Touch * touch, Event * event)
{
	auto touchPoint = touch->getLocation();
	bSelect = pMan->getBoundingBox().containsPoint(touchPoint);
	return true;
}

void HelloWorld::onTouchMoved(Touch * touch, Event * event)
{
	if (bSelect)
	{
		Vec2 oldPoint = touch->getPreviousLocation();
		Vec2 nowPoint = touch->getLocation();

		Vec2 firstVector = oldPoint - pMan->getPosition();
		float firstRotateAngle = -firstVector.getAngle();
		float previousTouch = CC_RADIANS_TO_DEGREES(firstRotateAngle);

		Vec2 secondVector = nowPoint - pMan->getPosition();
		float secondRotateAngle = -secondVector.getAngle();
		float currentTouch = CC_RADIANS_TO_DEGREES(secondRotateAngle);

		gRotation += currentTouch - previousTouch;
		gRotation = fmod(gRotation, 360.0f);
		
		pMan->setRotation(gRotation);
	}
}

void HelloWorld::onTouchEnded(Touch * touch, Event * event)
{
	bSelect = false;
}