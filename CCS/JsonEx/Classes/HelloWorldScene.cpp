#include "HelloWorldScene.h"
#include "json/rapidjson.h"
#include "json/document.h"
#include "json/stringbuffer.h"
#include "json/prettywriter.h"
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

	FileUtils* util = FileUtils::getInstance();

	std::string jsonData = util->getStringFromFile("data2.json");

	rapidjson::Document doc;
	doc.Parse<0>(jsonData.c_str());
	if (doc.HasParseError())
	{
		log("PARSEERR %S\n", doc.GetParseError());
		return false;
	}

	std::string str = doc["string"].GetString();
	log("name = %s", str.c_str());

	int n1 = doc["integer"].GetInt();
	log("i = %d", n1);

	bool n2 = doc["bool"].GetBool();
	log("n26 = %d", n2);

	float n3 = doc["float"].GetFloat();
	log("n3 = %f", n3);

	const rapidjson::Value &arr = doc["array"];
	if (arr.IsArray())
	{
		for (rapidjson::SizeType i = 0; i < arr.Size(); i++)
		{
			auto name = arr[i]["name"].GetString();
			auto age = arr[i]["age"].GetInt();
			log("name : %s, age : %d", name, age);
		}
	}


    return true;
}
