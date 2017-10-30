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

	winSize = Director::getInstance()->getWinSize();

	player = Sprite::create("turret.png");
	player->setPosition(Vec2(player->getContentSize().width / 2 + 80, winSize.height / 2));
	this->addChild(player);

	projectiles.clear();
	bProjectile = false;

	auto listener = EventListenerTouchOneByOne::create();
	listener->setSwallowTouches(true);
	listener->onTouchBegan = CC_CALLBACK_2(HelloWorld::onTouchBegan, this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);

    return true;
}

bool HelloWorld::onTouchBegan(Touch * touch, Event * event)
{
	if (bProjectile)
	{
		return true;
	}
	else
	{
		bProjectile = true;
	}

	auto touchPoint = touch->getLocation();

	auto nextProjectile = Sprite::create("bullet2.png");
	nextProjectile->retain();

	Vec2 shootVector = touchPoint - player->getPosition();
	float shootAngle = shootVector.getAngle();
	float cocosAngle = CC_RADIANS_TO_DEGREES(-1 * shootAngle);

	float curAngle = player->getRotation();
	float rotateDiff = cocosAngle - curAngle;
	if (rotateDiff > 180)
		rotateDiff -= 360;
	if (rotateDiff < -180)
		rotateDiff += 360;
	float rotateSpeed = 0.5f / 180;
	float rotateDuration = fabsf(rotateDiff * rotateSpeed);

	nextProjectile->setRotation(cocosAngle);

	auto actRotate1 = RotateTo::create(rotateDuration, cocosAngle);
	auto seqAct1 = Sequence::create(actRotate1,
		CallFunc::create(CC_CALLBACK_0(HelloWorld::finishRotate, this, nextProjectile, shootVector)), NULL);
	player->runAction(seqAct1);
}

void HelloWorld::finishRotate(Ref* sender, Vec2 dir)
{
	Sprite *sprite = (Sprite *)sender;

	Vec2 nPos1 = Vec2(player->getContentSize().width, player->getContentSize().height / 2);
	Vec2 nPos2 = player->convertToWorldSpace(nPos1);

	sprite->setPosition(nPos2);

	this->addChild(sprite);

	dir.normalize();
	Vec2 overshotVector = dir * 420;

	auto actMove2 = MoveBy::create(1.0f, overshotVector);
	auto seqAct2 = Sequence::create(actMove2,
		CallFunc::create(CC_CALLBACK_0(HelloWorld::spriteMoveFinished, this, sprite)), NULL);
	sprite->runAction(seqAct2);

	projectiles.pushBack(sprite);
	bProjectile = false;
}

void HelloWorld::spriteMoveFinished(Ref* sender)
{
	Sprite* sprite = (Sprite *)sender;
	this->removeChild(sprite, true);

	projectiles.eraseObject(sprite);
	sprite->release();
}