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

	auto wlayer = LayerColor::create(Color4B(125, 125, 125, 255));
	this->addChild(wlayer);

	/////////////////////////////

	TTFConfig ttfConfig1("fonts/Scissor Cuts.ttf", 40);
	TTFConfig ttfConfig2("fonts/Scissor Cuts.ttf", 40, GlyphCollection::DYNAMIC, nullptr, true);

	auto label1 = Label::createWithTTF(
		ttfConfig1,
		"Normal",
		TextHAlignment::CENTER,
		480);

	label1->setPosition(Vec2(240, 160));
	label1->setColor(Color3B::WHITE);
	this->addChild(label1);

	label1 = Label::createWithTTF(
		ttfConfig2,
		"GLOW!",
		TextHAlignment::CENTER,
		480);

	label1->setPosition(Vec2(240, 160 + 50));
	label1->setColor(Color3B::GREEN);
	label1->enableGlow(Color4B::YELLOW);
	this->addChild(label1);

	label1 = Label::createWithTTF(
		ttfConfig1,
		"shaDow!",
		TextHAlignment::RIGHT,
		480);

	label1->setPosition(Vec2(240, 160 - 100));
	label1->setColor(Color3B::RED);
	label1->enableShadow(Color4B::BLACK);
	this->addChild(label1);


	auto label2 = Label::createWithTTF(
		ttfConfig2,
		"OutLine",
		TextHAlignment::LEFT,
		480);

	label2->setPosition(Vec2(240, 160 - 50));
	label2->setColor(Color3B::WHITE);
	label2->enableOutline(Color4B::BLUE,2);
	this->addChild(label2);


    return true;
}
