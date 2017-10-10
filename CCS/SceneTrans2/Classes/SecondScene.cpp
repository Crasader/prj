#include "SecondScene.h"
#include "HelloWorldScene.h"

using namespace cocos2d;

Scene * SecondScene::createScene()
{
	return SecondScene::create();
}


// on "init" you need to initialize your instance
bool SecondScene::init()
{
	if (!Scene::init())
	{
		return false;
	}

	auto wlayer = LayerColor::create(Color4B(255, 255, 255, 255));
	this->addChild(wlayer);

	/////////////////////////////

	auto item1 = MenuItemFont::create("close Scene2",
		CC_CALLBACK_1(SecondScene::doClose, this));
	item1->setColor(Color3B(0, 0, 0));

	auto pMenu = Menu::create(item1, NULL);
	pMenu->setPosition(Vec2(240, 50));

	this->addChild(pMenu);

	log("SECOND SCENE INIT");

	return true;
}

void SecondScene::doClose(Object *pSender)
{
	auto pScene = HelloWorld::createScene();
	Director::getInstance()->replaceScene(pScene);
}
void SecondScene::onEnter()
{
	Scene::onEnter();
	log("SecondScene :: ON ENTER");
}
void SecondScene::onEnterTransitionDidFinish()
{
	Scene::onEnterTransitionDidFinish();
	log("SecondScene :: ONENTERTRANFINISH");
}
void SecondScene::onExitTransitionDidStart()
{
	Scene::onExitTransitionDidStart();
	log("SecondScene :: ONEXITTRANSTART");
}
void SecondScene::onExit()
{
	Scene::onExit();
	log("SecondScene :: ONEXIT");
}
SecondScene::~SecondScene()
{
	log("SecondScene :: DEALLOC");
}