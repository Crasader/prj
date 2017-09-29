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

	MenuItemFont::setFontSize(28);

	auto pMenuItem = MenuItemFont::create(
		" Action ", CC_CALLBACK_1(HelloWorld::doAction, this));
	pMenuItem->setColor(Color3B::BLACK);

	auto pMenu = Menu::create(pMenuItem, NULL);
	pMenu->setPosition(Vec2(240, 50));
	this -> addChild(pMenu);

	pMan = Sprite::create("Images/grossini.png");
	pMan->setPosition(Vec2(50, 230));
	this->addChild(pMan);

	pWoman = Sprite::create("Images/grossinis_sister1.png");
	pWoman->setPosition(Vec2(50, 110));
	this->addChild(pWoman);

    return true;
}


void HelloWorld::doAction(Ref *pSender)
{
	doAction_Move();
	  //doAction_Jump();
	  //doAction_Rotate();
	  //doAction_Scale();
	  //doAction_Tint();
	  //doAction_Place();
	  //doAction_Blink();
	  //doAction_Show();
	  //doAction_FadeInOut();

}

void HelloWorld::doAction_Move()
{
	MoveTo *myActionTo;
	MoveBy *myActionBy;

	if (temp == 0)
	{
		temp = 1;
		 myActionTo = MoveTo::create(2, Vec2(400, 0));
		 myActionBy = MoveBy::create(2, Vec2(400, 0));
	}
	else
	{
		temp = 0;
		 myActionTo = MoveTo::create(2, Vec2(50, 230));
		 myActionBy = MoveBy::create(2, Vec2(-400, 0));
	}

	pMan->runAction(myActionTo);
	pWoman->runAction(myActionBy);

	doAction_Rotate();
}
void HelloWorld::doAction_Jump()
{
	auto myActionTo = JumpTo::create(2, Vec2(400, 0), 150, 30);
	auto myActionBy = JumpBy::create(2, Vec2(400, 0), 150, 3);

	pMan->runAction(myActionTo);
	pWoman->runAction(myActionBy);
}
void HelloWorld::doAction_Rotate()
{
	pMan->runAction(RotateTo::create(2, Vec3(1080, 0, 0)));
	pWoman->runAction(RotateBy::create(2, Vec3(1080, 0, 0)));
}

void HelloWorld::doAction_Scale()
{
	auto myActionTo = ScaleTo::create(2, 2.0);
	auto myActionBy = ScaleBy::create(2, 2.0);

	pMan->runAction(myActionTo);
	pWoman->runAction(myActionBy);
}
void HelloWorld::doAction_Tint()
{
	auto myActionTo = TintTo::create(2, 128,128,128);
	auto myActionBy = TintBy::create(2, 128,128,128);

	pMan->runAction(myActionTo);
	pWoman->runAction(myActionBy);
}
void HelloWorld::doAction_Place()
{
	auto myAction = Place::create(Vec2(300, 200));
	pMan->runAction(myAction);
}
void HelloWorld::doAction_Blink()
{
	auto myAction = Blink::create(2, 25);
	pMan->runAction(myAction);
}
void HelloWorld::doAction_Show()
{
	if (pMan->isVisible())
	{
		auto myAction = Hide::create();
		pMan->runAction(myAction);
	}
	else
	{
		auto myAction = Show::create();
		pMan->runAction(myAction);
	}
}
void HelloWorld::doAction_FadeInOut()
{
	if (pMan->getOpacity() == 0)
	{
		auto myAction = FadeIn::create(1.5);
		pMan->runAction(myAction);
	}
	else
	{
		auto myAction = FadeOut::create(1.5);
		pMan->runAction(myAction);
	}
}