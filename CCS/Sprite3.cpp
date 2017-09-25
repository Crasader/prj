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

	auto parent = Sprite::create("Images/white-512x512.png");

	parent->setTextureRect(Rect(0, 0, 150, 150));
	parent->setPosition(Vec2(240, 160));
	parent->setColor(Color3B(0, 0, 255));

	parent->setScale(2.5f); //크기
	//parent->setOpacity(255); //투명도
	parent->setAnchorPoint(Vec2(0.5f, 0.5f)); //앵커
	parent->setVisible(true); //표시여부
	parent->setRotation(135.0f); //회전
	parent->setFlippedX(true); //뒤집기

	this->addChild(parent);

	for (int i = 0; i < 10; i++)
	{
		auto temp = Sprite::create("Images/white-512x512.png");
		temp->setTextureRect(Rect(0, 0, 150, 150));
		temp->setPosition(Vec2(240, 160));
		temp->setAnchorPoint(Vec2(0.5f, 0.5f)); //앵커
		temp->setColor(Color3B(i * 25, 0, 255 - i * 25));
		temp->setScale(2.5f - 0.15f * i);
		temp->setRotation(135.0f + 25.0f * i); //회전
		
		this->addChild(temp);
	}

	return true;
}
