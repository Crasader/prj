#include "HelloWorldScene.h"
#include "SecondScene.h"
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

	auto item1 = MenuItemFont::create("pushScene",
		CC_CALLBACK_1(HelloWorld::doChangeScene, this));
	item1->setColor(Color3B(0, 0, 0));

	auto pMenu = Menu::create(item1, NULL);
	pMenu->setPosition(Vec2(240, 50));

	this->addChild(pMenu);
	log("First SCENE INIT");

    return true;
}

void HelloWorld::doChangeScene(Object *pSender)
{
	auto pScene = SecondScene::createScene();
	Director::getInstance()->replaceScene(pScene);
}
void HelloWorld::onEnter()
{
	Scene::onEnter();
	log("HELLOWORLD :: ON ENTER");
}
void HelloWorld::onEnterTransitionDidFinish()
{
	Scene::onEnterTransitionDidFinish();
	log("HELLOWORLD :: ONENTERTRANFINISH");
}
void HelloWorld::onExitTransitionDidStart()
{
	Scene::onExitTransitionDidStart();
	log("HELLOWORLD :: ONEXITTRANSTART");
}
void HelloWorld::onExit()
{
	Scene::onExit();
	log("HELLOWORLD :: ONEXIT");
}
HelloWorld::~HelloWorld()
{
	log("HELLOWORLD :: DEALLOC");
}