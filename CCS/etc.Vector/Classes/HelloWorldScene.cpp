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
	if (!Scene::init())
	{
		return false;
	}

	auto wlayer = LayerColor::create(Color4B(255, 255, 255, 255));
	this->addChild(wlayer);

	/////////////////////////////

	//myVector1();
	//myVector2();
	myVector3();

	return true;
}

void HelloWorld::myVector1()
{
	std::vector<std::string> names;

	names.push_back("ABC");
	names.push_back("123");
	names.push_back("xyz");
	names.push_back("xA3");

	std::vector<std::string>::iterator it = names.begin();

	for (; it != names.end(); ++it)
	{
		log("%s", (*it).c_str());
	}

	for (std::vector<std::string>::iterator it = names.begin(); it != names.end(); ++it)
	{
		log("%s", (*it).c_str());
	}

	for (int i = 0; i < names.size(); i++)
	{
		log("%s", names[i].c_str());
		log("%s", names.at(i).c_str());
		names.erase(names.erase(names.begin()) + i);
	}
	names.clear();
}

void HelloWorld::myVector2()
{
	auto img11 = Sprite::create("Images/grossini.png");
	auto img12 = Sprite::create("Images/grossinis_sister1.png");
	auto img13 = Sprite::create("Images/grossinis_sister2.png");

	img11->setTag(11);
	img12->setTag(12);
	img13->setTag(13);

	std::vector<cocos2d::Sprite*>pictures1;

	pictures1.push_back(img11);
	pictures1.push_back(img12);
	pictures1.push_back(img13);

	int i = 1;

	std::vector<Sprite*>::iterator it = pictures1.begin();

	for (; it != pictures1.end(); ++it)
	{
		auto obj = (Sprite*)(*it);
		obj->setScale(0.5f);
		obj->setPosition(Vec2(120 * i, 240));
		this->addChild(obj);
		i++;
	}

	for (std::vector<Sprite*>::iterator it = pictures1.begin(); it != pictures1.end(); ++it)
	{
		auto obj = (Sprite*)(*it);
		log("Tag1 ... %d", obj->getTag());
	}

	/*for (int i = 0; i < pictures1.size(); i++)
	{
		pictures1.erase(pictures1.begin() + i);
	}
*/
	pictures1.erase(pictures1.begin() + 0);
	pictures1.erase(pictures1.begin() + 0);
	pictures1.erase(pictures1.begin() + 0);

	log("Count1 ... %d", pictures1.size());
	pictures1.clear();
}

void HelloWorld::myVector3()
{

	auto img11 = Sprite::create("Images/grossini.png");
	auto img12 = Sprite::create("Images/grossinis_sister1.png");
	auto img13 = Sprite::create("Images/grossinis_sister2.png");

	img11->setTag(11);
	img12->setTag(12);
	img13->setTag(13);

	Vector<cocos2d::Sprite*>pictures1;

	pictures1.pushBack(img11);
	pictures1.pushBack(img12);
	pictures1.pushBack(img13);

	int i = 1;

	Vector<Sprite*>::iterator it = pictures1.begin();

	for (; it != pictures1.end(); ++it)
	{
		auto obj = (Sprite*)(*it);
		obj->setScale(0.5f);
		obj->setPosition(Vec2(120 * i, 240));
		this->addChild(obj);
		i++;
	}

	for (Vector<Sprite*>::iterator it = pictures1.begin(); it != pictures1.end(); ++it)
	{
		auto obj = (Sprite*)(*it);
		log("Tag1 ... %d", obj->getTag());
	}

	for (int i = 0; i < pictures1.size(); i++)
	{
		auto obj = (Sprite*)pictures1.at(i);
		pictures1.eraseObject(obj);
	}

	log("Count1 ... %d", pictures1.size());
	pictures1.clear();
}