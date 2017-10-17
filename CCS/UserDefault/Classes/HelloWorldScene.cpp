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

	//UserDefault::getInstance()->setStringForKey("STR_KEY", "VALUE1");
	//UserDefault::getInstance()->setIntegerForKey("INT_KEY", 10);
	//UserDefault::getInstance()->setFloatForKey("FLOAT_KEY", 2.3f);
	//UserDefault::getInstance()->setDoubleForKey("DOUBLE_KEY", 2.4f);
	//UserDefault::getInstance()->setBoolForKey("BOOL_KEY", true);

	std::string ret = UserDefault::getInstance()->getStringForKey("STR_KEY");
	log("string key : ", ret.c_str());

	int i = UserDefault::getInstance()->getIntegerForKey("INT_KEY");
	log("%d", i);

	float f = UserDefault::getInstance()->getFloatForKey("FLOAT_KEY");
	log("%f", f);

	double d = UserDefault::getInstance()->getDoubleForKey("DOUBLE_KEY");
	log("%f", d);

	bool b = UserDefault::getInstance()->getBoolForKey("BOOL_KEY");
	if (b)
	{
		log("bool is true");
	}
	else
	{
		log("bool is false");
	}

/*
	UserDefault::getInstance()->setStringForKey("STR_KEY", "VALUE2");
	UserDefault::getInstance()->setIntegerForKey("INT_KEY", 105);
	UserDefault::getInstance()->setFloatForKey("FLOAT_KEY", 25.3f);
	UserDefault::getInstance()->setDoubleForKey("DOUBLE_KEY", 23.4f);
	UserDefault::getInstance()->setBoolForKey("BOOL_KEY", false);

	UserDefault::getInstance()->flush();

	 i = UserDefault::getInstance()->getIntegerForKey("INT_KEY");
	log("%d", i);

	 f = UserDefault::getInstance()->getFloatForKey("FLOAT_KEY");
	log("%f", f);

	 d = UserDefault::getInstance()->getDoubleForKey("DOUBLE_KEY");
	log("%f", d);

	 b = UserDefault::getInstance()->getBoolForKey("BOOL_KEY");
	if (b)
	{
		log("bool is true");
	}
	else
	{
		log("bool is false");
	}
*/



    return true;
}
