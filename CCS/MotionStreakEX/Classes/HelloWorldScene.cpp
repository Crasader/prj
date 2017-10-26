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

	/////////////////////////////
	//fade,minseg,stroke,color,path
	//m_pStreak = MotionStreak::create(5.0f, 1.0f, 10.0f, Color3B::GREEN, "Images/streak2.png");
	//m_pStreak = MotionStreak::create(5.0f, 1.0f, 10.0f, Color3B::GREEN, "Images/streak.png");
	m_pStreak = MotionStreak::create(5.0f, 1.0f, 10.0f, Color3B::WHITE, "Images/nyan.png");

	this->addChild(m_pStreak);


    return true;
}

void HelloWorld::onEnter()
{
	Scene::onEnter();

	auto listener = EventListenerTouchOneByOne::create();
	listener->setSwallowTouches(true);

	listener->onTouchBegan = CC_CALLBACK_2(HelloWorld::onTouchBegan, this);
	listener->onTouchMoved = CC_CALLBACK_2(HelloWorld::onTouchMoved, this);

	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);
}

void HelloWorld::onExit()
{
	Scene::onExit();
}

bool HelloWorld::onTouchBegan(Touch* touch, Event* event)
{
	m_pStreak->reset();
	auto touchPoint = touch->getLocation();

	m_pStreak->setPosition(touchPoint);
	return true;
}

void HelloWorld::onTouchMoved(Touch *touch, Event *event)
{
	auto touchPoint = touch->getLocation();
	m_pStreak->setPosition(touchPoint);
}