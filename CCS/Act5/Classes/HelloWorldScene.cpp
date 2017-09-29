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

	auto pMenuItem = MenuItemFont::create(
		" Action ", CC_CALLBACK_1(HelloWorld::doAction, this));
	pMenuItem->setColor(Color3B::BLACK);

	auto pMenu = Menu::create(pMenuItem, NULL);
	pMenu->setPosition(Vec2(240, 50));
	this->addChild(pMenu);

	pMan = Sprite::create("Images/grossini.png");
	pMan->setPosition(Vec2(50, 160));
	this->addChild(pMan);

    return true;
}

void HelloWorld::doAction(Ref *pSender)
{
	pMan->removeFromParentAndCleanup(true);

	this->removeChildByTag(1, true);
	this->removeChildByTag(2, true);
	this->removeChildByTag(3, true);

	pMan = Sprite::create("Images/grossini.png");

	pMan->setPosition(Vec2(50, 160));
	pMan->setTag(5);
	this->addChild(pMan);

	pMan->setVisible(false);

	auto action = Sequence::create(
		Place::create(Vec2(200, 200)),
		DelayTime::create(1.0),
		Show::create(),
		MoveBy::create(1, Vec2(200, 0)),
		CallFunc::create(CC_CALLBACK_0(HelloWorld::callBack1, this)),
		MoveBy::create(1, Vec2(-200, 0)),
		RemoveSelf::create(),
		DelayTime::create(0.01f),
		CallFunc::create(CC_CALLBACK_0(HelloWorld::callBack2, this, pMan)),
		CallFunc::create(CC_CALLBACK_0(HelloWorld::callBack3, this, pMan, 42)),
		DelayTime::create(2.0),
		RemoveSelf::create(),
		NULL);

	pMan->runAction(action);
}

void HelloWorld::callBack1()
{
	auto label = LabelTTF::create("CALLBACK 1 CALLED", "Marker Felt", 16);
	label->setPosition(Vec2(120, 160));
	label->setColor(Color3B::BLACK);
	label->setScale(2.0f);
	label->setTag(1);

	this->addChild(label);
}
void HelloWorld::callBack2(Node *sender)
{
	auto label = LabelTTF::create("CALLBACK 2 CALLED", "Marker Felt", 16);
	label->setPosition(pMan->getPosition());
	label->setColor(Color3B::RED);
	label->setScale(1.5f);
	label->setTag(2);

	this->addChild(label);

	auto tItem = (Sprite *)sender;
	int i = tItem->getTag();
	log("tag num : %d", i);
}
void HelloWorld::callBack3(Node *sender,long data)
{
	auto label = LabelTTF::create("CALLBACK 3 CALLED", "Marker Felt", 16);
	label->setPosition(Vec2(360, 120));
	label->setColor(Color3B::BLUE);
	label->setScale(2.5f);
	label->setTag(3);

	this->addChild(label);
}