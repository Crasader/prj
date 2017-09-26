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
	auto pMenu = Menu::create(NULL);

	for (int i = 0; i < 3; i++)
	{
		char buffer[20];
		sprintf(buffer, " Menu-%d ", i);

		auto pMenuItem = MenuItemFont::create(
			buffer, CC_CALLBACK_1(HelloWorld::doClick, this));
		pMenuItem->setColor(Color3B(0, 0, 0));
		pMenuItem->setTag(i+1);

		pMenu->addChild(pMenuItem);
	}/*
	auto pMenuItem = MenuItemFont::create(
		"Menu-1", CC_CALLBACK_1(HelloWorld::doClick, this));
	pMenuItem->setColor(Color3B(0, 0, 0));
	pMenuItem->setTag(1);

	auto pMenuItem2 = MenuItemFont::create(
		"Menu-2", CC_CALLBACK_1(HelloWorld::doClick, this));
	pMenuItem2->setColor(Color3B(0, 0, 0));
	pMenuItem2->setTag(2);

	auto pMenuItem3 = MenuItemFont::create(
		"Menu-3", CC_CALLBACK_1(HelloWorld::doClick, this));
	pMenuItem3->setColor(Color3B(0, 0, 0));
	pMenuItem3->setTag(3);
*/
	//auto pMenu = Menu::create(pMenuItem, pMenuItem2, pMenuItem3,NULL);
	/*auto pMenu = Menu::create(NULL);
	pMenu->addChild(pMenuItem);
	pMenu->addChild(pMenuItem2);
	pMenu->addChild(pMenuItem3);
*/
	pMenu->alignItemsHorizontally();

	this->addChild(pMenu);

    return true;
}

void HelloWorld::doClick(Ref* sender)
{
	auto tItem = (MenuItem *)sender;

	int i = tItem->getTag();
	log("%d번째 메뉴 선택", i);
}