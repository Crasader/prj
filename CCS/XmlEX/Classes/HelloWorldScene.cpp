#include "HelloWorldScene.h"
//#include "SimpleAudioEngine.h"
#include "tinyxml2/tinyxml2.h"

USING_NS_CC;
using namespace tinyxml2;

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

	FileUtils* util = FileUtils::getInstance();

	std::string path = util->fullPathForFilename("Stage0.xml");
	tinyxml2::XMLDocument *doc = new tinyxml2::XMLDocument();
	XMLError error = doc->LoadFile(path.c_str());

	if (error != 0)
	{
		log("Error Number : %d", error);
		return false;
	}

	XMLElement* root = doc->RootElement();
	XMLElement* key = root->FirstChildElement("total");

	if (key)log("key Element = %s", key->GetText());

	key = key->NextSiblingElement("page");
	if (key)log("key Element = %s", key->GetText());

	key = key->NextSiblingElement("per");
	if (key)log("key Element = %s", key->GetText());


	XMLElement * array = key->NextSiblingElement();
	XMLElement * child = array->FirstChildElement();
	while (child)
	{
		XMLElement* child2 = child->FirstChildElement();
		while (child2)
		{
			log("Child Element : %s", child2->GetText());
			child2 = child2->NextSiblingElement();
		}
		child = child->NextSiblingElement();
	}
	delete doc;

    return true;
}
