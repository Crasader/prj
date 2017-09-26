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

	for (int i = 1; i < 3; i++)
	{
		char text[20];
		sprintf(text, " Menu - %d ", i);

		auto pMenuItem = MenuItemFont::create(
			text,CC_CALLBACK_1(HelloWorld::doClick,this)
		);
		pMenuItem->setColor(Color3B::BLACK);
		pMenuItem->setTag(i);
		pMenu->addChild(pMenuItem);
	}

	pMenu->alignItemsVertically();
	this->addChild(pMenu);

    return true;
}

void HelloWorld::doClick(Ref *sender)
{
	Sprite *pCat;
	auto tItem = (MenuItem *)sender;
	int i = tItem->getTag();

	switch (i)
	{
	case 1:
		 pCat = Sprite::create("Images/praying-cat.jpg");
		pCat->setPosition(Point(90, 160));
		pCat->setScale(0.25f, 0.25f);
		pCat->setTag(11);

		this->addChild(pCat); break;

	case 2:
		 pCat = (Sprite*)this->getChildByTag(11);
		this->removeChild(pCat, true); break;
	}
}