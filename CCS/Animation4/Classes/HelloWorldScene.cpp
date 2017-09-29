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

	auto cache = SpriteFrameCache::getInstance();

	cache->addSpriteFramesWithFile("Animations/grossini_family.plist");
	cache->addSpriteFramesWithFile("Animations/grossini.plist");

	auto pSprite = SpriteFrame::create("Animations/block9.png", Rect(0, 0, 96, 96));
	cache->addSpriteFrame(pSprite, "blocks12.png");

	auto pWoman = Sprite::createWithSpriteFrameName("grossinis_sister1.png");
	pWoman->setPosition(Vec2(120, 220));
	this->addChild(pWoman);

	auto pMan = Sprite::createWithSpriteFrameName("grossini_dance_01.png");
	pMan->setPosition(Vec2(240, 220));
	this->addChild(pMan);

	auto pBox = Sprite::createWithSpriteFrameName("blocks12.png");
	pBox->setPosition(Vec2(360, 220));
	this->addChild(pBox);

	auto texture = Director::getInstance()->getTextureCache()->addImage("animations/grossini_dance_atlas.png");

	auto pMan2 = Sprite::createWithTexture(texture, Rect(0, 0, 85, 121));
	pMan2->setPosition(Vec2(120, 100));
	this->addChild(pMan2);

	auto texture2 = Director::getInstance()->getTextureCache()->addImage("animations/dragon_animation.png");

	auto pDragon = Sprite::createWithTexture(texture2, Rect(0, 0, 130, 140));
	pDragon->setPosition(Vec2(240, 100));
	this->addChild(pDragon);

	Director::getInstance()->getTextureCache()->addImageAsync("animations/blocks9.png",
		CC_CALLBACK_1(HelloWorld::imageLoaded, this));


    return true;
}

void HelloWorld::imageLoaded(Ref *pSender)
{
	auto tex = static_cast<Texture2D*> (pSender);
	auto sprite = Sprite::createWithTexture(tex);
	sprite->setPosition(Vec2(360, 100));
	this->addChild(sprite);
}