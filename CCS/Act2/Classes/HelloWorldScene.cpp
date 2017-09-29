#include "HelloWorldScene.h"
//#include "SimpleAudioEngine.h"

USING_NS_CC;

Action * ActionReverse(Action *act)
{
	auto act2 = act->reverse();
	return act2;
}


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

	pMan = Sprite::create("Images/grossini.png");
	pMan->setPosition(Vec2(50, 160));
	this->addChild(pMan);

	this->ActionSequence(this);
	//ActionSpawn(this);
	//ActionRepeat(this);
}
void HelloWorld::ActionSequence(Ref *pSender)
{
	auto action = Sequence::create(
		MoveBy::create(2, Vec2(400, 0)),
		RotateBy::create(2, 540),
		MoveBy::create(2, Vec2(-400, 0)),
		RotateBy::create(2, -540),
		NULL);

	//pMan->runAction(action);
	pMan->runAction(ActionReverse(action));
}

void HelloWorld::ActionSpawn(Ref *pSender)
{
	auto action = Spawn::create(
		MoveBy::create(2, Vec2(400, 0)),
		JumpBy::create(2, Vec2(0,100),150,5),
		MoveBy::create(2, Vec2(-400, 0)),
		RotateBy::create(2, -36540),
		NULL);

	pMan->runAction(action);
}

void HelloWorld::ActionRepeat(Ref *pSender)
{
	auto myActionForward = MoveBy::create(2, Vec2(400, 0));
	auto myActionBack = myActionForward->reverse();
	auto myAction = Sequence::create(myActionForward, myActionBack,DelayTime::create(1), NULL);

	//auto rep1 = Repeat::create(myAction, 3);
	auto rep1 = RepeatForever::create(myAction);

	pMan->runAction(rep1);
}