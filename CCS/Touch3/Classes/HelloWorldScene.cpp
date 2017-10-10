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

	auto pLabel = LabelTTF::create(
		"블럭을 터치해서 드래그",
		"Arial", 20
	);
	pLabel->setPosition(Vec2(240, 280));
	pLabel->setColor(Color3B(0, 0, 0));
	this->addChild(pLabel, 101);

	sprite = Sprite::create("Images/stars2.png");
	sprite->setPosition(Vec2(240, 160) + Vec2(-80, 80));
	sprite->setColor(Color3B(150, 200, 255));
	this->addChild(sprite);

	sprite2 = Sprite::create("Images/stars2.png");
	sprite2->setPosition(Vec2(240, 160));
	sprite2->setColor(Color3B(255, 100, 255));
	this->addChild(sprite2);

	sprite3 = Sprite::create("Images/stars2.png");
	sprite3->setPosition(Vec2(0, 0));
	sprite3->setColor(Color3B(255, 255, 0));
	this->addChild(sprite3);

	sprite4 = Sprite::create("Images/stars2.png");
	sprite4->setPosition(Vec2(180, 160));
	sprite4->setColor(Color3B(0, 0, 0));
	this->addChild(sprite4);

    return true;
}

void HelloWorld::onEnter() {

	Scene::onEnter();

	auto listener = EventListenerTouchOneByOne::create();
	listener->setSwallowTouches(true);

	listener->onTouchBegan = [=](Touch *touch, Event *event)
	{
		log("touch began");

		auto target = static_cast<Sprite *>(event->getCurrentTarget());

		Vec2 locationInNode = target->convertToNodeSpace(touch->getLocation());
		Size s = target->getContentSize();

		Rect rect = Rect(0, 0, s.width, s.height);
		if (rect.containsPoint(locationInNode))
		{
			reZorder(target);

			log("Sprite onTouchBegan x = %f,y = %f", locationInNode.x, locationInNode.y);

			target->setOpacity(180);
			return true;
		}
		return false;
	};

	listener->onTouchMoved = [](Touch * touch, Event * event)
	{
		auto target = static_cast<Sprite *>(event->getCurrentTarget());
		target->setPosition(target->getPosition() + touch->getDelta());
	};

	listener->onTouchEnded = [=](Touch *touch, Event *event)
	{
		auto target = static_cast<Sprite *>(event->getCurrentTarget());
		log("sprite on TouchesEnded");
		target->setOpacity(255);
	};

	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener->clone(), sprite);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener->clone(), sprite2);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener->clone(), sprite3);
}

void HelloWorld::onExit() {
	_eventDispatcher->removeAllEventListeners();
	Scene::onExit();
}
void HelloWorld::reZorder(Sprite * pSender)
{
	sprite->setZOrder(0);
	sprite2->setZOrder(0);
	sprite3->setZOrder(0);

	pSender->setZOrder(1);
}