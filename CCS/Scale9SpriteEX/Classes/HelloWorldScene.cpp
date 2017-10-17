#include "HelloWorldScene.h"
//#include "SimpleAudioEngine.h"

using namespace cocos2d;
using namespace cocos2d::extension;

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

	Sprite *pSprite1 = Sprite::create("test9.png");
	pSprite1->setPosition(Vec2(140, 160));
	this->addChild(pSprite1);

	Texture2D *texture = Director::getInstance()->getTextureCache()->addImage("test9.png");

	auto pSpriteTop = Sprite::createWithTexture(texture, Rect(0, 0, 50, 20));
	pSpriteTop->setPosition(Vec2(240, 300));
	this->addChild(pSpriteTop);

	auto pSpriteBottom = Sprite::createWithTexture(texture, Rect(0, 30, 50, 20));
	pSpriteBottom->setPosition(Vec2(240, 20));
	this->addChild(pSpriteBottom);

	auto pSpriteMiddle = Sprite::createWithTexture(texture, Rect(0, 20, 50, 10));
	pSpriteMiddle->setPosition(Vec2(240, 160));
	this->addChild(pSpriteMiddle);

	Scale9Sprite* pSprite2 = Scale9Sprite::create("test9.png", Rect(0, 0, 50, 50), Rect(0, 20, 50, 10));

	pSprite2->setPosition(Vec2(340, 160));
	pSprite2->setContentSize(Size(50, 300));
	this->addChild(pSprite2);

    return true;
}
