#include "HelloWorldScene.h"
//#include "SimpleAudioEngine.h"

USING_NS_CC;

#define SSL schedule_selector
#define MapScrollSpeed 5

int count = 0;

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

	layer = LayerColor::create(Color4B(0, 0, 0, 255));
	this->addChild(layer);

	/////////////////////////////

	tMap2 = TMXTiledMap::create("Tiles/Tile.tmx");
	tMap2->setPosition(Vec2(tMap2->getMapSize().width * tMap2->getTileSize().width, 0));
	metainfo = tMap2->getLayer("Meta");
	metainfo->setVisible(false);
	layer->addChild(tMap2, 0, 11);

	tMap = TMXTiledMap::create("Tiles/Tile.tmx");
	layer->addChild(tMap, 0, 11);
	metainfo = tMap->getLayer("Meta");
	metainfo->setVisible(false);


	TMXObjectGroup *objects = tMap->getObjectGroup("Object");
	ValueMap& spawnPoint = objects->getObject("Start");

	int x = spawnPoint["x"].asInt();
	int y = spawnPoint["y"].asInt();

	Nyan = Sprite::create("Images/Nyan.png");
	Nyan->setScale(0.1);
	Nyan->setAnchorPoint(Vec2(0, 0));
	Nyan->setPosition(Vec2(x, y));
	this->addChild(Nyan, 1, 100);

	this->schedule(SSL(HelloWorld::moveBackground));

    return true;
}

void HelloWorld::moveBackground(float t)
{
	tMap->setPosition(Vec2(tMap->getPosition().x - MapScrollSpeed, tMap->getPosition().y));
	tMap2->setPosition(Vec2(tMap2->getPosition().x - MapScrollSpeed, tMap2->getPosition().y));

	Vec2 tileCoord = this->tileCoordForPosition(Vec2(-tMap->getPosition().x, Nyan->getPosition().y));
	int tileGid = this->metainfo->getTileGIDAt(tileCoord);

	if (tileGid)
	{
		log("으악 %d", count++);
	}

	if (tMap2->getPosition().x == 0)
	{
		tMap->setPosition(Vec2(tMap2->getMapSize().width * tMap2->getTileSize().width, 0));
		
		TMXTiledMap *temp = tMap;
		tMap = tMap2;
		tMap2 = temp;
	}
}

Vec2 HelloWorld::tileCoordForPosition(Vec2 position)
{
	int x = position.x / tMap->getTileSize().width;
	if (x == tMap->getMapSize().width) x -= 1;

	int y = ((tMap->getMapSize().height * tMap->getTileSize().height) - position.y)
		/ tMap->getTileSize().height;

	return Vec2(x, y);
}