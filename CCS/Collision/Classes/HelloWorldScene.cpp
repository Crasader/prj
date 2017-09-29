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

	pEnemy = Sprite::create("Images/MagentaSquare.png");
	pEnemy->setPosition(Vec2(400, 160));
	this->addChild(pEnemy);
	this->createBullet();
	this->schedule(schedule_selector(HelloWorld::myTick));

    return true;
}

void HelloWorld::createBullet()
{
	pBullet = Sprite::create("Images/f1.png");
	pBullet->setPosition(Vec2(140, 160));
	this->addChild(pBullet);

	auto myActionForward = MoveBy::create(3, Vec2(200, 0));
	auto myAction = Sequence::create(
		Place::create(Vec2(140, 160)),
		myActionForward, NULL);
	auto rep = RepeatForever::create(myAction);

	pBullet->runAction(rep);
}

void HelloWorld::myTick(float f)
{
	if (pBullet == NULL)
	{
		log("pBullet is NULL");
		this->createBullet();
		return;
	}

	if (pBullet->getBoundingBox().intersectsRect(pEnemy->getBoundingBox()))
	{
		log("COLLISION CHECK");
		pBullet->removeFromParentAndCleanup(true);
		pBullet = NULL;
	}
}


