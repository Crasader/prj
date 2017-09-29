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

	//

	pBall = Sprite::create("Images/r1.png");
	pBall->setPosition(Vec2(50, 100));
	pBall->setScale(0.7f);
	this->addChild(pBall);

	pMan = Sprite::create("Images/grossini.png");
	pMan->setPosition(Vec2(50, 150));
	pMan->setScale(0.5f);
	this->addChild(pMan);
	
	pWomen1 = Sprite::create("Images/grossinis_sister1.png");
	pWomen1->setPosition(Vec2(50, 220));
	pWomen1->setScale(0.5f);
	this->addChild(pWomen1);
	
	pWomen2 = Sprite::create("Images/grossinis_sister2.png");
	pWomen2->setPosition(Vec2(50, 280));
	pWomen2->setScale(0.5f);
	this->addChild(pWomen2);

    return true;
}

void HelloWorld::doAction(Ref *pSender)
{
	pBall->setPosition(Vec2(50, 100));
	pMan->setPosition(Vec2(50, 150));
	pWomen1->setPosition(Vec2(50, 220));
	pWomen2->setPosition(Vec2(50, 280));

	//doAction_Ease();
	//doAction_Elastic();
	//doAction_Bounce();
	doAction_Speed();

	return;
}
void HelloWorld::doAction_Ease()
{
	auto move = MoveBy::create(3.0f, Vec2(400, 0));

	auto ease_in = EaseIn::create(move->clone(), 3.0f);
	auto ease_out = EaseOut::create(move->clone(), 3.0f);
	auto ease_inout = EaseInOut::create(move->clone(), 3.0f);

	pBall->runAction(move);
	pMan->runAction(ease_in);
	pWomen1->runAction(ease_out);
	pWomen2->runAction(ease_inout);
}

void HelloWorld::doAction_Elastic()
{
	auto move = MoveBy::create(3.0f, Vec2(400, 0));

	auto ease_in = EaseElasticIn::create(move->clone(), 0.4f);
	auto ease_out = EaseElasticOut::create(move->clone(), 0.4f);
	auto ease_inout = EaseElasticInOut::create(move->clone(), 0.4f);

	pBall->runAction(move);
	pMan->runAction(ease_in);
	pWomen1->runAction(ease_out);
	pWomen2->runAction(ease_inout);
}

void HelloWorld::doAction_Bounce()
{
	auto move = MoveBy::create(3.0f, Vec2(400, 0));

	auto ease_in = EaseBounceIn::create(move->clone());
	auto ease_out = EaseBounceOut::create(move->clone());
	auto ease_inout = EaseBounceInOut::create(move->clone());

	pBall->runAction(move);
	pMan->runAction(ease_in);
	pWomen1->runAction(ease_out);
	pWomen2->runAction(ease_inout);
}

void HelloWorld::doAction_Speed()
{
	auto move = MoveBy::create(3.0f, Vec2(400, 0));

	auto ease_in = Speed::create(move->clone(),0.5);
	auto ease_out = Speed::create(move->clone(),2.0);
	auto ease_inout = Speed::create(move->clone(),3.0);

	pBall->runAction(move);
	pMan->runAction(ease_in);
	pWomen1->runAction(ease_out);
	pWomen2->runAction(ease_inout);
}
