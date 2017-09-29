#include "TestScene2.h"

using namespace cocos2d;

Scene* TestScene2::createScene()
{
	return TestScene2::create();
}

// on "init" you need to initialize your instance
bool TestScene2::init()
{
	if (!Scene::init())
	{
		return false;
	}

	auto wlayer = LayerColor::create(Color4B(0, 255, 255, 255));
	this->addChild(wlayer);

	/////////////////////////////

	auto item1 = MenuItemFont::create(
		"Close 2", CC_CALLBACK_1(TestScene2::doClose, this));
	item1->setColor(Color3B::BLACK);

	auto pMenu = Menu::create(item1, NULL);
	pMenu->setPosition(Vec2(240, 50));
	this->addChild(pMenu);

	return true;
}

void TestScene2::doClose(Ref *pSender)
{
	Director::getInstance()->popScene();
}