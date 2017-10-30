#include "HelloWorldScene.h"
//#include "SimpleAudioEngine.h"

USING_NS_CC;

Scene* HelloWorld::createScene()
{
	auto scene = Scene::create();
	auto layer = HelloWorld::create();

	scene->addChild(layer);

    return scene;
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    if ( !Layer::init() )
    {
        return false;
    }

	auto wlayer = LayerColor::create(Color4B(255, 255, 255, 255));
	this->addChild(wlayer);

	/////////////////////////////

	auto listener = EventListenerTouchAllAtOnce::create();

	listener->onTouchesBegan = CC_CALLBACK_2(HelloWorld::onTouchesBegan, this);
	listener->onTouchesMoved = CC_CALLBACK_2(HelloWorld::onTouchesMoved, this);
	listener->onTouchesEnded = CC_CALLBACK_2(HelloWorld::onTouchesEnded, this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);

	JControlManager::getInstance();
	JControlManager::getInstance()->Initialize(this);

	pMan = Sprite::create("Images/grossini.png");
	pMan->setPosition(Vec2(240, 160));
	this->addChild(pMan);

	this->schedule(schedule_selector(HelloWorld::tick));

    return true;
}

void HelloWorld::tick(float dt)
{
	JControlManager::getInstance()->Update(dt);

	if (JControlManager::getInstance()->GetDistance() == 0.f)
	{
		return;
	}
	else
	{
		float distance = JControlManager::getInstance()->GetDistance() * 0.5f + 0.5f;
		float speed = distance * 100.f * dt;

		Vec2 axis = JControlManager::getInstance()->GetAxis();
		auto velocity_ = axis * speed;

		pMan->setPosition(pMan->getPosition() + velocity_);

		if (axis.x < 0.f)
		{

		}
		else if (axis.x > 0.f)
		{

		}
	}

/*
	float width = pMan->getContentSize().width / 2;
	float height = pMan->getContentSize().height / 2;

	float vx = pMan->getPosition().x + joystick->getVelocity().x * 10;
	float vy = pMan->getPosition().y + joystick->getVelocity().y * 10;

	if ((vx < width) || vx > (480 - width))
	{
		vx = pMan->getPosition().x;
	}

	if ((vy < height) || (vy > (320 - height)))
	{
		vy = pMan->getPosition().y;
	}

	pMan->setPosition(Vec2(vx, vy));
*/

}

void HelloWorld::onTouchesBegan(const std::vector<Touch *>&touches, Event *event)
{
	log("Z");
	Vec2 point;
	Vec2 touchGlPoint;

	for (auto &item : touches)
	{
		auto touch = item;
		point = touch->getLocationInView();
		touchGlPoint = Director::getInstance()->convertToGL(point);

		log("A");
		for (int a = 0; a < MAX_BUTTON; ++a)
		{
			if (JControlManager::getInstance()->IsButtonContainsPoint((eButtonID)a, touchGlPoint))
			{
				JControlManager::getInstance()->btnTouchID_[a] = touch;
				JControlManager::getInstance()->btnState_[a] = BEGIN;
				JControlManager::getInstance()->btnTouchPoint_[a] = touchGlPoint;
			}
		}
		log("B");
	}

	JControlManager::getInstance()->SetTouchState(BEGIN);
	JControlManager::getInstance()->SetTouchPoint(touchGlPoint);
}

void HelloWorld::onTouchesMoved(const std::vector<Touch *>&touches, Event *event)
{
	Vec2 point;
	Vec2 touchGlPoint;

	for (auto &item : touches)
	{
		auto touch = item;
		point = touch->getLocationInView();
		touchGlPoint = Director::getInstance()->convertToGL(point);

		for (int a = 0; a < MAX_BUTTON; a++)
		{
			if (touch == JControlManager::getInstance()->btnTouchID_[a])
			{
				JControlManager::getInstance()->btnState_[a] = MOVE;
				JControlManager::getInstance()->btnTouchPoint_[a] = touchGlPoint;
			}
		}
	}

	JControlManager::getInstance()->SetTouchState(MOVE);
	JControlManager::getInstance()->SetTouchPoint(touchGlPoint);
}

void HelloWorld::onTouchesEnded(const std::vector<Touch *>&touches, Event *event)
{
	Vec2 point;
	Vec2 touchGlPoint;

	for (auto &item : touches)
	{
		auto touch = item;
		point = touch->getLocationInView();
		touchGlPoint = Director::getInstance()->convertToGL(point);

		for (int a = 0; a < MAX_BUTTON; a++)
		{
			if (touch == JControlManager::getInstance()->btnTouchID_[a])
			{
				JControlManager::getInstance()->btnState_[a] = END;
				JControlManager::getInstance()->btnTouchPoint_[a] = touchGlPoint;
			}
		}
	}

	JControlManager::getInstance()->SetTouchState(END);
	JControlManager::getInstance()->SetTouchPoint(touchGlPoint);
}
