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

	auto pMenuItem = MenuItemImage::create(
		"Images/btn-play-normal.png",
		"Images/btn-play-selected.png",
		CC_CALLBACK_1(HelloWorld::menuSelect, this)
	);

	auto pMenu = Menu::create(pMenuItem, NULL);

	//pMenu->setPosition(Vec2::ZERO);
	pMenu->setAnchorPoint(Vec2(1.0f, 1.0f));

	this->addChild(pMenu);

    return true;
}

void HelloWorld::menuSelect(Ref * Sender)
{
	log("메뉴선택됨");
}