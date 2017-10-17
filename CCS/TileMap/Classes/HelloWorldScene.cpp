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

	winSize = Director::getInstance()->getWinSize();
	tMap = TMXTiledMap::create("Tiles/untitled.tmx");
	background = tMap->getLayer("Background");
	items = tMap->getLayer("Items");
	metainfo = tMap->getLayer("MetaInfo");
	metainfo->setVisible(false);

	this->addChild(tMap, 0, 11);

	TMXObjectGroup *objects = tMap->getObjectGroup("Objects");
	ValueMap& spawnPoint = objects->getObject("SpawnPoint");

	int x = spawnPoint["x"].asInt();
	int y = spawnPoint["y"].asInt();

	dragonPos = Vec2(x, y);
	this->createDragon();

	return true;
}


void HelloWorld::onEnter()
{
	Scene::onEnter();

	auto listener = EventListenerTouchOneByOne::create();

	listener->setSwallowTouches(true);
	listener->onTouchBegan = CC_CALLBACK_2(HelloWorld::onTouchBegan, this);
	listener->onTouchMoved = CC_CALLBACK_2(HelloWorld::onTouchMoved, this);
	listener->onTouchEnded = CC_CALLBACK_2(HelloWorld::onTouchEnded, this);

	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);
}

void HelloWorld::onExit()
{
	_eventDispatcher->removeEventListenersForType(EventListener::Type::TOUCH_ONE_BY_ONE);
	Scene::onExit();
}

bool HelloWorld::onTouchBegan(Touch *touch, Event *event)
{
	//auto touchPoint = touch->getLocation();
	return true;
}

void HelloWorld::onTouchMoved(Touch *touch, Event *event)
{
	//Vec2 diff = touch->getDelta();

	//Node *node = this->getChildByTag(11);
	//Vec2 currentPos = node->getPosition();

	//Vec2 newPos = currentPos + diff;
	//if (newPos.x < -160)
	//{
	//	newPos.x = -160;
	//}
	//if (newPos.x > 0)
	//{
	//	newPos.x = 0;
	//}
	//newPos.y = 0;

	//node->setPosition(newPos);

}

void HelloWorld::onTouchEnded(Touch *touch, Event *event)
{
	log("ENDED");
	auto touchPoint = touch->getLocation();
	touchPoint = this->convertToNodeSpace(touchPoint);

	Vec2 PlayerPos = dragon->getPosition();
	Vec2 diff = touchPoint - PlayerPos;

	if (abs(diff.x) > abs(diff.y))
	{
		if (diff.x > 0)
		{
			PlayerPos.x += tMap->getTileSize().width;
			dragon->setFlippedX(true);
		}
		else
		{
			PlayerPos.x -= tMap->getTileSize().width;
			dragon->setFlippedX(false);
		}
	}
	else
	{
		if (diff.y > 0)
		{
			PlayerPos.y += tMap->getTileSize().height;
		}
		else
		{
			PlayerPos.y -= tMap->getTileSize().height;
		}
	}

	if ((PlayerPos.x < tMap->getMapSize().width * tMap->getTileSize().width) &&
		(PlayerPos.y < tMap->getMapSize().height * tMap->getTileSize().height) &&
		PlayerPos.y >= 0 && PlayerPos.x >= 0)
	{
		//dragon->setPosition(PlayerPos);
		this->setPlayerPosition(PlayerPos);
	}

	this->setViewpointCenter(dragon->getPosition());
}

void HelloWorld::setViewpointCenter(Vec2 position)
{
	int x = MAX(position.x, winSize.width / 2);
	int y = MAX(position.y, winSize.height / 2);

	x = MIN(x, (tMap->getMapSize().width * tMap->getTileSize().width) - winSize.width / 2);
	y = MIN(y, (tMap->getMapSize().height * tMap->getTileSize().height) - winSize.height / 2);

	Vec2 actualPosition = Vec2(x,y);
	Vec2 centerOfView = Vec2(winSize.width / 2, winSize.height / 2);
	Vec2 viewPoint = centerOfView - actualPosition;

	this->setPosition(viewPoint);
}

void HelloWorld::createDragon()
{
	auto texture = Director::getInstance()->getTextureCache()->addImage("Images/dragon_animation.png");
	auto animation = Animation::create();
	animation->setDelayPerUnit(0.1f);

	for (int i = 0; i < 6; i++)
	{
		int index = i % 4;
		int rowIndex = i / 4;

		animation->addSpriteFrameWithTexture(
			texture, Rect(index * 130, rowIndex * 140 + 70, 110, 70));
	}

	dragon = Sprite::createWithTexture(texture, Rect(0, 70, 110, 70));
	dragon->setPosition(dragonPos);
	dragon->setAnchorPoint(Vec2(0, 0));
	dragon->setScale(0.5);
	this->addChild(dragon);

	auto animate = Animate::create(animation);
	auto rep = RepeatForever::create(animate);
	dragon->runAction(rep);

	//dragon = Sprite::create("Images/Blue.png");
	//dragon->setPosition(dragonPos);
	//dragon->setAnchorPoint(Vec2(0, 0));
	//this->addChild(dragon);
}

Vec2 HelloWorld::tileCoordForPosition(Vec2 position)
{
	int x = position.x / tMap->getTileSize().width;
	int y = ((tMap->getMapSize().height * tMap->getTileSize().height) - position.y)
		/ tMap->getTileSize().height;

	return Vec2(x, y);
}

void HelloWorld::setPlayerPosition(Vec2 position)
{
	Vec2 tileCoord = this->tileCoordForPosition(position);

	int tileGid = this->metainfo->getTileGIDAt(tileCoord);

	if (tileGid)
	{
		Value& properties = tMap->getPropertiesForGID(tileGid);

		if (!properties.isNull())
		{
			/*std::string wall = properties.asValueMap()["Wall"].asString();
			if (wall == "YES")
			{
				log("WALL");
				return;
			}*/
			bool wall = properties.asValueMap()["isWall"].asBool();
			if (wall==true)
			{
				log("WALL");
				return;
			}

			bool item = properties.asValueMap()["isItem"].asBool();
			if (item == true)
			{
				log("ITEM!");

				this->metainfo->removeTileAt(tileCoord);
				items->removeTileAt(tileCoord);
				
			}
		}
	}

	dragon->setPosition(position);
}