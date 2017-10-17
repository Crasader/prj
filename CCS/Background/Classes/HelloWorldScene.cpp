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

	layer1 = Layer::create();
	this->addChild(layer1);

	layer2 = Layer::create();
	this->addChild(layer2);

	//auto go = MoveBy::create(4, Vec2(-512, 0));
	//auto goBack = go->reverse();
	//auto seq = Sequence::create(go, goBack, NULL);
	//auto act = RepeatForever::create(seq);

	//wlayer->runAction(act);

	winSize = Director::getInstance()->getWinSize();

	createBackground();
	createDragon();
	createArrowButtons();

    return true;
}

void HelloWorld::createBackground()
{
	auto background1 = Sprite::create("Images/background1.png");
	background1->setAnchorPoint(Vec2(0, 0));
	background1->setPosition(Vec2(0, 0));

	auto background2 = Sprite::create("Images/background2.png");
	background2->setAnchorPoint(Vec2(0, 0));
	background2->setPosition(Vec2(512, 0));

	background1->getTexture()->setAntiAliasTexParameters();
	background2->getTexture()->setAntiAliasTexParameters();

	layer1->addChild(background1);
	layer1->addChild(background2);
}
void HelloWorld::createDragon()
{
	auto texture = Director::getInstance()->getTextureCache()->addImage("Images/dragon_animation.png");
	auto animation = Animation::create();
	animation->setDelayPerUnit(0.1f);

	for (int i = 0; i < 6; i++)
	{
		int index = i % 4;
		int rowIndex = i / 4;

		animation->addSpriteFrameWithTexture(
			texture, Rect(index * 130, rowIndex * 140 + 70, 110, 70));
	}

	dragon = Sprite::createWithTexture(texture, Rect(0, 70, 110, 70));
	dragon->setPosition(Vec2(240, 160));
	layer1->addChild(dragon);

	auto animate = Animate::create(animation);
	auto rep = RepeatForever::create(animate);
	dragon->runAction(rep);
}

void HelloWorld::createArrowButtons()
{
	leftSprite = Sprite::create("Images/b1.png");
	leftSprite->setPosition(Vec2(180, 30));

	layer2->addChild(leftSprite, 2);

	leftPressedSprite = Sprite::create("Images/b2.png");
	leftPressedSprite->setPosition(leftSprite->getPosition());

	layer2->addChild(leftPressedSprite, 1);

	rightSprite = Sprite::create("Images/f1.png");
	rightSprite->setPosition(Vec2(300, 30));

	layer2->addChild(rightSprite, 2);

	rightPressedSprite = Sprite::create("Images/f2.png");
	rightPressedSprite->setPosition(rightSprite->getPosition());

	layer2->addChild(rightPressedSprite, 1);
}

void HelloWorld::onEnter()
{
	Scene::onEnter();

	listener = EventListenerTouchOneByOne::create();
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
	isLeftPressed = false;
	isRightPressed = false;

	if (this->isTouchInside(leftSprite, touch) == true)
	{
		leftSprite->setVisible(false);
		isLeftPressed = true;
	}
	else if (this->isTouchInside(rightSprite, touch) == true)
	{
		rightSprite->setVisible(false);
		isRightPressed = true;
	}

	if (isLeftPressed == true || isRightPressed == true)
	{
		this->startMovingBackground();
	}
	return true;
}

void HelloWorld::onTouchMoved(Touch *touch, Event *event)
{
	if (isLeftPressed == true && this->isTouchInside(leftSprite, touch) == false)
	{
		leftSprite->setVisible(true);
		this->stopMovingBackground();
	}
	else if (isRightPressed == true && this->isTouchInside(rightSprite, touch) == false)
	{
		rightSprite->setVisible(true);
		this->stopMovingBackground();
	}
}

void HelloWorld::onTouchEnded(Touch *touch, Event *event)
{
	if (isLeftPressed == true || isRightPressed == true)
	{
		this->stopMovingBackground();
	}
	if (isLeftPressed == true)
		leftSprite->setVisible(true);
	if (isRightPressed == true)
		rightSprite->setVisible(true);
}

bool HelloWorld::isTouchInside(Sprite *sprite, Touch *touch)
{
	auto touchPoint = touch->getLocation();
	bool bTouch = sprite->getBoundingBox().containsPoint(touchPoint);
	return bTouch;
}

void HelloWorld::startMovingBackground()
{
	if (isLeftPressed == true && isRightPressed == true)
	{
		return;
	}

	log("START MOVING");

	this->schedule(schedule_selector(HelloWorld::moveBackground));
}
void HelloWorld::stopMovingBackground()
{
	log("stop Moving");
	this->unschedule(schedule_selector(HelloWorld::moveBackground));
}
void HelloWorld::moveBackground(float t)
{
	log("Moving Backgorund");

	auto moveStep = 3;
	if (isLeftPressed)
	{
		moveStep = -3;
		dragon->setFlippedX(false);
	}
	else
	{
		dragon->setFlippedX(true);
	}

	auto newPos = Vec2(dragon->getPosition().x + moveStep, dragon->getPosition().y);

	if (newPos.x < 20)
	{
		newPos.x = 512 * 2 - 10;
	}
	else if (newPos.x > 512 * 2 - 10)
	{
		newPos.x = 20;
	}

	dragon->setPosition(newPos);
	layer1->runAction(Follow::create(dragon, Rect(0, 0, 512 * 2, 320)));
}
