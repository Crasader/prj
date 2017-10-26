#include "HelloWorldScene.h"
//#include "SimpleAudioEngine.h"

USING_NS_CC;
using namespace ui;

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

	auto sprite1 = Sprite::create("Images/grossini.png");
	auto sprite2 = Sprite::create("Images/grossinis_sister1.png");
	sprite1->setPosition(Vec2(40, 80));
	sprite2->setPosition(Vec2(920, 80));

	auto layer = LayerColor::create(Color4B(255, 0, 255, 255));
	layer->setAnchorPoint(Vec2::ZERO);
	layer->setPosition(Vec2(0, 0));
	layer->setContentSize(Size(960, 160));

	layer->addChild(sprite1);
	layer->addChild(sprite2);

	auto sprite3 = Sprite::create("Images/nyan.png");
	sprite3->setPosition(Vec2(0, 80));
	layer->addChild(sprite3);

	auto scrollView = ScrollView::create();

	scrollView->setSize(Size(480, 160));
	scrollView->setInnerContainerSize(layer->getContentSize());
	scrollView->setDirection(ScrollView::Direction::NONE);
	scrollView->addChild(zlayer);
	scrollView->setBounceEnabled(true);
	scrollView->setScrollBarAutoHideEnabled(false);
	scrollView->addEventListener(CC_CALLBACK_2(HelloWorld::scrollEvent, this));
	scrollView->jumpToPercentHorizontal(0);
	scrollView->setPosition(Vec2(0, 100));
	this->addChild(scrollView);

    return true;
}

void HelloWorld::scrollEvent(Ref* pSender, ScrollView::EventType event)
{
	switch (event)
	{
	case ScrollView::EventType::BOUNCE_BOTTOM:
		log("BOUNCE_BOT");
		break;
	case ScrollView::EventType::SCROLLING:
		log("SCROOOOOOOOOOOOL");
		break;
	case ScrollView::EventType::CONTAINER_MOVED:
		log("CON MOVEEEE");
		break;
	case ScrollView::EventType::BOUNCE_LEFT:
		log("BOUNCE LEFT");
		break;
	case ScrollView::EventType::BOUNCE_RIGHT:
		log("BOUNCE RIGHT");
		break;
	case ScrollView::EventType::BOUNCE_TOP:
		log("BOUNCE TOP");
		break;
	}
}