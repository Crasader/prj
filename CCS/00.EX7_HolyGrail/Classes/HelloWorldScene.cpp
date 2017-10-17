#include "HelloWorldScene.h"
#include "Singleton.h"
//#include "SimpleAudioEngine.h"

USING_NS_CC;

#define Monsters Singleton::getInstance()->Monsters
#define Items Singleton::getInstance()->Items
#define Stage_Max 3

Scene* HelloWorld::createScene()
{
    return HelloWorld::create();
}

int PlayerHead = 0;
int CurrentStage = 0;
int PlayerItemType = 0;

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    if ( !Scene::init() )
    {
        return false;
    }

	/////////////////////////////

	layer = LayerColor::create(Color4B(0, 0, 0, 255));
	this->addChild(layer);

	cache = SpriteFrameCache::getInstance();
	cache->addSpriteFramesWithFile("Images/Holygrail.plist");
	winSize = Director::getInstance()->getWinSize();

	CreateMenu();
	setAnimations();
	LoadStage(CurrentStage);

    return true;
}

void HelloWorld::LoadStage(int N)
{
	Monsters.clear();
	Items.clear();

	char words[100];
	sprintf(words, "Tiles/Stage%d.tmx", N);
	tMap = TMXTiledMap::create(words);
	tMap->setTag(150);
	layer->addChild(tMap);

	TMXObjectGroup *Objects = tMap->getObjectGroup("Objects");
	ValueMap& spawnPoint = Objects->getObject("Start");
	ValueVector spawns = Objects->getObjects();
	metainfo = tMap->getLayer("Meta");
	metainfo->setVisible(false);

	Player = Sprite::createWithSpriteFrameName("Hero01.png");
	Player->setPosition(Vec2(spawnPoint["x"].asInt(), spawnPoint["y"].asInt()));
	Player->setPosition(Player->getPosition() + Vec2(0, 1));

	log("%f %f", Player->getPosition().x, Player->getPosition().y);

	Player->setAnchorPoint(Vec2(0, 0));
	layer->addChild(Player);

	Player->runAction(PlayerAnimation.at(PlayerHead)->clone());

	for (int i = 0; i < spawns.size(); i++)
	{
		if (spawns.at(i).asValueMap()["MonsterType"].asInt() != 0)
		{
			Monster *newM = new Monster(layer, &spawns.at(i),
				MonstersAnimation.at(spawns.at(i).asValueMap()["MonsterType"].asInt() - 1));

			Monsters.pushBack(newM);
		}
	}

	for (int i = 0; i < spawns.size(); i++)
	{
		if (spawns.at(i).asValueMap()["ItemType"].asInt() != 0)
		{
			Item *newM = new Item(layer, &spawns.at(i));

			Items.pushBack(newM);
		}
	}
}

void HelloWorld::onEnter()
{
	Scene::onEnter();

	auto listener = EventListenerTouchOneByOne::create();

	listener->setSwallowTouches(true);
	listener->onTouchBegan = CC_CALLBACK_2(HelloWorld::onTouchBegan, this);
	listener->onTouchEnded = CC_CALLBACK_2(HelloWorld::onTouchEnded, this);

	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);
}

bool HelloWorld::onTouchBegan(Touch *touch, Event *event)
{
	return true;
}
void HelloWorld::onTouchEnded(Touch *touch, Event *event)
{
	if (Director::getInstance()->isPaused())
	{
		return;
	}

	if (touch->getLocation().x > winSize.width - 128)
	{
		if (ReStart->boundingBox().containsPoint(touch->getLocation()))
		{
			Reset();
		}

		return;
	}

	auto touchPoint = touch->getLocation();
	touchPoint = this->convertToNodeSpace(touchPoint);

	Vec2 PlayerPos = Player->getPosition();
	Vec2 diff = touchPoint - PlayerPos;

	if (abs(diff.x) > abs(diff.y))
	{
		if (diff.x > 0)
		{
			PlayerPos.x += tMap->getTileSize().width;
			if (PlayerHead != 2)
			{
				PlayerHead = 2;
				Player->stopAllActions();
				Player->runAction(PlayerAnimation.at(PlayerHead)->clone());
			}
		}
		else
		{
			PlayerPos.x -= tMap->getTileSize().width;
			if (PlayerHead != 1)
			{
				PlayerHead = 1;
				Player->stopAllActions();
				Player->runAction(PlayerAnimation.at(PlayerHead)->clone());
			}
		}
	}
	else
	{
		if (diff.y > 0)
		{
			PlayerPos.y += tMap->getTileSize().height;
			if (PlayerHead != 3)
			{
				PlayerHead = 3;
				Player->stopAllActions();
				Player->runAction(PlayerAnimation.at(PlayerHead)->clone());
			}
		}
		else
		{
			PlayerPos.y -= tMap->getTileSize().height;
			if (PlayerHead != 0)
			{
				PlayerHead = 0;
				Player->stopAllActions();
				Player->runAction(PlayerAnimation.at(PlayerHead)->clone());
			}
		}
	}

	if ((PlayerPos.x < tMap->getMapSize().width * tMap->getTileSize().width) &&
		(PlayerPos.y < tMap->getMapSize().height * tMap->getTileSize().height) &&
		PlayerPos.y >= 0 && PlayerPos.x >= 0)
	{
		//dragon->setPosition(PlayerPos);
		this->setPlayerPosition(PlayerPos);
	}

	//this->setViewpointCenter(dragon->getPosition());
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

	log("%f %f", tileCoord.x, tileCoord.y);

	if (tileGid)
	{
		Value& properties = tMap->getPropertiesForGID(tileGid);

		if (!properties.isNull())
		{
			bool Check = properties.asValueMap()["isWall"].asBool();
			if (Check == true)
			{
				log("WALL");
				return;
			}
		}
	}

	for (int i = 0; i < Monsters.size(); i++)
	{
		if (Monsters.at(i)->boundingBox().containsPoint(position))
		{
			log("MONSTER!");
			if (Monsters.at(i)->_type == PlayerItemType)
			{
				PlayerItemType = 0;
				ItemUpdate(0);
				Monsters.at(i)->Destroy();
			}
			else
			{
				return;
			}
		}
	}

	for (int i = 0; i < Items.size(); i++)
	{
		if (Items.at(i)->boundingBox().containsPoint(position))
		{
			log("ITEM!!!!!");

			if (Items.at(i)->_type == 5)
			{
				if (PlayerItemType == 4)
				{
					PlayerItemType = 0;
					ItemUpdate(0);

					Items.at(i)->Destroy();
					log("CLEAR!!!");

					Clear();
					return;
				}
				else
				{
					return;
				}
			}

			else if (PlayerItemType == 0)
			{
				PlayerItemType = Items.at(i)->_type;
				ItemUpdate(Items.at(i)->_type);

				Items.at(i)->Destroy();
			}
			else
			{
				return;
			}
		}
	}

	Player->setPosition(position);
}

void HelloWorld::setAnimations()
{
	//Hero%02d.png 01~12
	//1~3 :: motion down - PlayerAnim[0]
	//4~6 :: motion left - PlayerAnim[1]
	//7~9 :: motion right - PlayerAnim[2]
	//10~12 :: motion up - PlayerAnim[3]
	PlayerAnimation = createMultiAnimation("Hero",12,4,2);

	//Demon%01d.png 1~3
	DemonAnimation = createSingleAnimation("Demon", 3, 1);
	MonstersAnimation.pushBack(DemonAnimation);
	
	//Jelly%01d.png 1~3
	JellyAnimation = createSingleAnimation("Jelly", 3, 1);
	MonstersAnimation.pushBack(JellyAnimation);
	
	//Wolf%01d.png 1~3
	WolfAnimation = createSingleAnimation("Wolf", 3, 1);
	MonstersAnimation.pushBack(WolfAnimation);
}
Vector<RepeatForever*> HelloWorld::createMultiAnimation(char *name,int NumOfSprites,int NumOfIdx,int NoD)
{
	cocos2d::Vector<cocos2d::RepeatForever*> MultiAnimation;
	cocos2d::Vector<cocos2d::SpriteFrame*> *MultiAnim;
	MultiAnim = new Vector<SpriteFrame*>[4];

	int temp = NumOfSprites / NumOfIdx;

	char str[100] = { 0 };

	for (int i = 1; i <= NumOfSprites; i++)
	{
		sprintf(str, "%s%%0%dd.png", name, NoD);
		sprintf(str, str, i);

		SpriteFrame* frame = cache->getSpriteFrameByName(str);
		MultiAnim[(i - 1) / temp].pushBack(frame);

		if (i % 3 == 0)
		{
			sprintf(str, "%s%%0%dd.png", name, NoD);
			sprintf(str, str, i - 1);

			SpriteFrame* frame = cache->getSpriteFrameByName(str);
			MultiAnim[(i - 1) / temp].pushBack(frame);

			auto animation = Animation::createWithSpriteFrames(MultiAnim[(i - 1) / temp], 0.3f);
			auto animate = Animate::create(animation);

			MultiAnimation.pushBack(RepeatForever::create(animate->clone()));
		}
	}

	return MultiAnimation;

}
cocos2d::RepeatForever* HelloWorld::createSingleAnimation(char *name, int NumOfSprites, int NoD)
{
	cocos2d::RepeatForever* SingleAnimation;
	cocos2d::Vector<cocos2d::SpriteFrame*> SingleAnim;

	char str[100] = { 0 };
	for (int i = 1; i <= NumOfSprites; i++)
	{
		sprintf(str, "%s%%0%dd.png", name, NoD);
		sprintf(str, str, i);

		SpriteFrame* frame = cache->getSpriteFrameByName(str);
		SingleAnim.pushBack(frame);

		if (i % 3 == 0)
		{
			sprintf(str, "%s%%0%dd.png", name, NoD);
			sprintf(str, str, i-1);

			SpriteFrame* frame = cache->getSpriteFrameByName(str);
			SingleAnim.pushBack(frame);

			auto animation = Animation::createWithSpriteFrames(SingleAnim, 0.5f);
			auto animate = Animate::create(animation);

			SingleAnimation = RepeatForever::create(animate);
		}
	}

	return SingleAnimation;
}


void HelloWorld::CreateMenu()
{
	 Black = Sprite::create("Images/menu_layer.png");
	Black->setAnchorPoint(Vec2(0, 0));
	Black->setPosition(Vec2(winSize.width - 128, 0));
	Black->setScale(2);
	this->addChild(Black, 100);

	itemSlot = Sprite::create("Images/item_box.png");
	itemSlot->setAnchorPoint(Vec2(0,0));
	itemSlot->setPosition(Vec2(0, 320 - 64));
	itemSlot->setScale(0.5f);
	Black->addChild(itemSlot);

	ReStart = Sprite::create("Images/SideB2.png");
	ReStart->setAnchorPoint(Vec2(0, 0));
	ReStart->setPosition(Vec2(winSize.width - 109, 20));
	ReStart->setScale(2.0f);
	this->addChild(ReStart,500);

	char Text[100];
	sprintf(Text, "Stage %d", CurrentStage);
	StageText = LabelTTF::create(Text, "Arial", 12);
	StageText->setAnchorPoint(Vec2(0, 0));
	StageText->setPosition(Vec2(12, 64));
	StageText->setScale(1.0f);
	Black->addChild(StageText);
}

void HelloWorld::ItemUpdate(int _type)
{
	char addr[100];
	if (_type == 0)
	{
		itemSlot->removeChildByTag(100);
		return;
	}
	if (_type == 1)
	{
		sprintf(addr,"W_Sword015.png");
	}
	else if (_type == 2)
	{
		sprintf(addr, "W_Mace008.png");
	}
	else if (_type == 3)
	{
		sprintf(addr, "W_Sword001.png");
	}
	else if (_type == 4)
	{
		sprintf(addr, "I_Key02.png");
	}
	else if (_type == 5)
	{
		sprintf(addr, "I_Chest01.png");
	}
	log("%s", addr);

	if(PlayerItemType!=0)
	itemSlot->removeChildByTag(100);

	auto temp = Sprite::createWithSpriteFrameName(addr);
	temp->setAnchorPoint(Vec2(0.5, 0.5));
	temp->setPosition(Vec2(itemSlot->getContentSize().width / 2, itemSlot->getContentSize().height / 2));
	temp->setTag(100);
	itemSlot->addChild(temp);
}

void HelloWorld::Reset()
{
	Monsters.clear();
	Items.clear();

	Player->stopAllActions();
	layer->removeChild(Player);
	layer->removeChild(tMap);

	 PlayerHead = 0;
	 PlayerItemType = 0;
	 ItemUpdate(0);

	LoadStage(CurrentStage);

	Black->removeChild(StageText,false);

	char Text[100];
	sprintf(Text, "Stage %d", CurrentStage);
	StageText = LabelTTF::create(Text, "Arial", 12);
	StageText->setAnchorPoint(Vec2(0, 0));
	StageText->setPosition(Vec2(12, 64));
	StageText->setScale(1.0f);
	Black->addChild(StageText);
}

void HelloWorld::Clear()
{
	CurrentStage++;
	if (Stage_Max < CurrentStage)
	{
		log("다깸!");

		auto end = Sprite::create("Images/End.png");
		end->setAnchorPoint(Vec2(0, 0));
		this->addChild(end);

		Director::getInstance()->pause();
		return;
	}

	Reset();
}