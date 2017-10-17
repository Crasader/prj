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
/*
	auto map = TMXTiledMap::create("Images/iso-test-zorder.tmx");
	this->addChild(map, 0, 1);

	Size s = map->getContentSize();
	map->setPosition(Vec2(-s.width / 2, 0));

	nyan = Sprite::create("Images/nyan.png");
	nyan->setScale(0.05);
	map->addChild(nyan, map->getChildren().size());
	int mapWidth = map->getMapSize().width * map->getTileSize().width;
	nyan->setPosition((CC_POINT_PIXELS_TO_POINTS(Vec2(mapWidth / 2, 0))));
	nyan->setAnchorPoint(Vec2(0.5, 0));

	auto move = MoveBy::create(10, Vec2(300, 250));
	auto back = move->reverse();
	auto seq = Sequence::create(move, back, NULL);
	nyan->runAction(RepeatForever::create(seq));

	schedule(schedule_selector(HelloWorld::repositionSprite));*/

	auto map = TMXTiledMap::create("Images/orthogonal-test-zorder.tmx");
	this->addChild(map, 0, 1);

	Size s = map->getContentSize();

	for (int i = 0; i < map->getChildren().size(); i++)
	{
		map->getChildren().at(i)->setOpacity(155 + i);
	}

	
	nyan = Sprite::create("Images/nyan.png");
	nyan->setScale(0.05);
	map->addChild(nyan, map->getChildren().size());
	nyan->setAnchorPoint(Vec2(0.5, 0));

	auto move = MoveBy::create(10, Vec2(400, 320));
	auto back = move->reverse();
	auto seq = Sequence::create(move, back, NULL);
	nyan->runAction(RepeatForever::create(seq));

	schedule(schedule_selector(HelloWorld::repositionSprite));

    return true;
}

void HelloWorld::repositionSprite(float dt)
{
	Vec2 p = nyan->getPosition();
	p = CC_POINT_POINTS_TO_PIXELS(p);
	Node* map = getChildByTag(1);

	//int newZ = 4 - (p.y / 48);
	int newZ = 4 - (p.y - 10) / 81;
	newZ = MAX(newZ, 0);

	map->reorderChild(nyan, newZ);
}