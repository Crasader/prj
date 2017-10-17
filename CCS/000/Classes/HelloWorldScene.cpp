#include "HelloWorldScene.h"
#include "Singleton.h"
//#include "SimpleAudioEngine.h"

USING_NS_CC;
using namespace pugi;

#define Enemys Singleton::getInstance()->enemys
#define Bullets Singleton::getInstance()->bullets

#define BlueSky "Images/1945/BlueSky.png"
#define InvincTime 50
#define FireRate 1.0/20
float speed = 2.5;
float cloudScrollSpeed = 240;

int AttackMaxCount = 4;
int AttackCount = AttackMaxCount;
int AttackMaxCD = 10;
int AttackCD = 10;

int isPlayerInvinc = 0;
int PlayerHP = 3;

Scene* HelloWorld::createScene()
{
	return HelloWorld::create();
}

bool HelloWorld::init()
{
	if (!Scene::init())
	{
		return false;
	}

	auto wlayer = LayerColor::create(Color4B(100, 100, 150, 255));
	wlayer->setZOrder(-10);
	this->addChild(wlayer);

	////

	winSize = Director::getInstance()->getWinSize();
	auto texture = Director::getInstance()->getTextureCache()->addImage(BlueSky);
	CloudControl();
	CreateMenu();
	PlayerSet();

	return true;
}

void HelloWorld::StageLoader(int number)
{
	char _addr[100];
	sprintf(_addr, "XML/Stage%d.xml", number);

	std::string fileName = FileUtils::getInstance()->fullPathForFilename(_addr);
	xml_parse_result result = xmlDoc.load_file(fileName.c_str());

	if (!result)
	{
		log("NO SUCH FILE : %s", fileName);
		return;
	}
	
	else log("%s", fileName.c_str());

	xml_node nodeResult = xmlDoc.child("Stage");
	xml_node nodeItem = nodeResult.child("Info");

	StageReader(nodeItem);
}
void HelloWorld::StageReader(xml_node nodeItem)
{
	xml_node NextnodeItem = nodeItem.next_sibling("Info");

	std::string logText = nodeItem.child("Numb").text().get();
	log("%s", logText.c_str());

	std::string symbolName = nodeItem.child("Type").text().get();
	int val = atoi(nodeItem.child("Value").text().get());

	log("%s",symbolName.c_str());

	if (symbolName == "")
	{

	}
	else if (symbolName == "Enemy")
	{
		int x = xmlPosTrans(nodeItem.child("POS_X").text().get(),0);
		int y = xmlPosTrans(nodeItem.child("POS_Y").text().get(),1);

		Enemy *newB = new Enemy(this, Vec2(x,y), val);
	}
	else if (symbolName == "Wait")
	{
		log("WAIT %d", val);

		auto Seq = Sequence::create(
			DelayTime::create(val / 1000.0),
			CallFunc::create(CC_CALLBACK_0(HelloWorld::StageReader, this, NextnodeItem))
				, NULL);
		this->runAction(Seq);

		return;
	}
	else if (symbolName == "_StageEnd")
	{
		log("STAGE END");
		return;
	}

	StageReader(NextnodeItem);
}

int HelloWorld::xmlPosTrans(std::string str,int type)
{
	int result = 0;
	if (type == 0) // x
	{
		if (str.at(0) == '-')
		{
			result = winSize.width - atoi(str.substr(1, str.length()).c_str());
		}
		else if (str.at(0) == '+')
		{
			result = atoi(str.substr(1, str.length()).c_str());
		}
		else if (str == "CENTER")
		{
			result = winSize.width / 2;
		}
		else if (str == "RIGHT")
		{
			result = winSize.width - 50;
		}
		else if (str == "LEFT")
		{
			result = 50;
		}
		else //부호 없음
		{
			result = atoi(str.substr(1, str.length()).c_str());
		}
	}
	else if (type == 1) // y
	{
		if (str.at(0) == '-')
		{
			result = winSize.height - atoi(str.substr(1, str.length()).c_str());
		}
		else if (str.at(0) == '+')
		{
			result = atoi(str.substr(1, str.length()).c_str());
			result += 160;
		}
		else if (str == "CENTER")
		{
			result = winSize.height / 2;
			result += 80;
		}
		else if (str == "TOP")
		{
			result = winSize.height;
		}
		else //부호 없음
		{
			result = atoi(str.substr(1, str.length()).c_str());
			result += 160;
		}

	}

	return result;
}

void HelloWorld::onEnter()
{
	Scene::onEnter();

	srand(time(NULL));

	listener = EventListenerTouchOneByOne::create();
	listener->setSwallowTouches(true);

	listener->onTouchBegan = CC_CALLBACK_2(HelloWorld::onTouchBegan, this);
	listener->onTouchMoved = CC_CALLBACK_2(HelloWorld::onTouchMoved, this);
	listener->onTouchEnded = CC_CALLBACK_2(HelloWorld::onTouchEnded, this);

	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);
}
void HelloWorld::PlayerSet()
{
	for (int i = 1; i < 4; i++)
	{
		auto life = Sprite::create("Images/1945/life.png");
		life->setAnchorPoint(Vec2(0.5, 0.5));
		life->setPosition(Vec2(-10 + 30 * i, 135));
		life->setScale(0.03);
		life->setZOrder(120);
		life->setTag(100 + i);
		this->addChild(life);
	}

	//

	Player = Sprite::create("Images/1945/invisible_Hand.png");
	Player->setAnchorPoint(Vec2(0.5, 0.5));
	Player->setPosition(Vec2(160, 210));
	Player->setZOrder(10);
	this->addChild(Player);

	auto Player_Image = Sprite::create("Images/1945/P2.png");
	Player_Image->setPosition(Vec2(30, 30));
	Player->addChild(Player_Image);
	//
}
void HelloWorld::CreateMenu()
{
	auto Black = Sprite::create("Images/1945/Black.png");
	Black->setAnchorPoint(Vec2(0, 0));
	pCircleBase = Sprite::create("Images/1945/moveCircle.png");
	pCircleBase->setAnchorPoint(Vec2(0.5, 0.5));
	pCircleBase->setPosition(Vec2(160, 80));
	pCircleBase->setScale(0.25f);
	pCircleBase->setColor(Color3B::YELLOW);
	pCircleArrow = Sprite::create("Images/1945/moveCircle4.png");
	pCircleArrow->setColor(Color3B::GREEN);
	pCircleArrow->setAnchorPoint(Vec2(1, 0));
	pCircleArrow->setPosition(Vec2(255, 255));
	pCircleArrow->setRotation(-45);
	pCircleArrow->setVisible(false);

	auto pMenuItem = MenuItemFont::create(
		"EXIT", CC_CALLBACK_1(HelloWorld::ExitClick, this)
	);
	pMenuItem->setColor(Color3B::WHITE);
	pMenuItem->setAnchorPoint(Vec2(1, 0));;
	pMenuItem->setPosition(Vec2(-15, 15));
	pMenuItem->setZOrder(999);

	auto pMenu = Menu::create(pMenuItem, NULL);
	pMenu->setAnchorPoint(Vec2(0.5, 0.5));
	pMenu->setPosition(320, 0);
	pMenu->setZOrder(300);
	this->addChild(pMenu, 21);
	this->addChild(Black, 20);

	this->addChild(pCircleBase, 301);
	pCircleBase->addChild(pCircleArrow);


	touchText = LabelTTF::create("Touch \n&\n Drag", "Arial", 24);
	touchText->setZOrder(1000);
	touchText->setPosition(160, 80);
	touchText->setColor(Color3B(180, 180, 255));

	auto act = Sequence::create(
		ScaleTo::create(0.4, 1.1),
		ScaleTo::create(0.4, 0.9),
		NULL);
	auto actRep = RepeatForever::create(act);
	touchText->runAction(actRep);

	this->addChild(touchText);

}
void HelloWorld::CloudControl()
{
	CloudCallBack();
	auto Clouds = Sprite::create(BlueSky);
	Clouds->setAnchorPoint(Vec2(0, 0));
	Clouds->setZOrder(-1);
	this->addChild(Clouds);

	auto CloudSeq = Sequence::create(
		MoveBy::create(640 / cloudScrollSpeed, Vec2(0, -640)),
		CallFunc::create(CC_CALLBACK_0(HelloWorld::CloudCallBack, this)),
		RemoveSelf::create(),
		NULL
	);
	Clouds->runAction(CloudSeq);
}
void HelloWorld::CloudCallBack()
{
	auto Clouds2 = Sprite::create(BlueSky);
	Clouds2->setPosition(Vec2(0, 640));
	Clouds2->setAnchorPoint(Vec2(0, 0));
	Clouds2->setZOrder(-1);
	this->addChild(Clouds2);

	auto CloudSeq2 = Sequence::create(
		MoveBy::create(1280 / cloudScrollSpeed, Vec2(0, -1280)),
		Place::create(Vec2(0, 640)),
		NULL
	);
	auto CloudRep2 = RepeatForever::create(CloudSeq2);

	Clouds2->runAction(CloudRep2);

}

//

void HelloWorld::Update(float time)
{
	PlayerMove();
	EnemyMove();
	ShotMove();
}
void HelloWorld::PlayerFire(float time)
{
	//Fire
	if (isPlayerInvinc <= -10)
	{
		return;
	}

	if (AttackCount > 0)
	{
		for (int i = 0; i < 3; i++)
		{
			createBullet(Vec2(Player->getPosition() + Vec2(20 + 40 * (AttackCount % 2 * -1), 30)), 0);
		}

		AttackCount--;
	}
	else
	{
		if (AttackCD == 0)
		{
			AttackCount = AttackMaxCount;
			AttackCD = AttackMaxCD;
		}
		else
			AttackCD--;
	}
}

void HelloWorld::PlayerMove()
{
	//PlayerMove

	if (isPlayerInvinc > 0)
		isPlayerInvinc--;

	if (bOnTouch == true && bDistance == true)
	{
		Vec2 move;
		move.x = sinf(CC_DEGREES_TO_RADIANS(degreeA));
		move.y = cosf(CC_DEGREES_TO_RADIANS(degreeA));
		Player->setRotation3D(Vec3(0, 20 * move.x, 0));

		if (Player->getPosition().x + speed * move.x > 295 ||
			Player->getPosition().x + speed * move.x < 25)
		{
			move.x = 0;
		}
		if (Player->getPosition().y + speed * move.y > 625 ||
			Player->getPosition().y + speed * move.y < 192)
		{
			move.y = 0;
		}

		Player->setPosition(
			Vec2(Player->getPosition().x + speed * move.x,
				Player->getPosition().y + speed * move.y));
	}

}
void HelloWorld::EnemyMove()
{
	//EnemyMove
	for (int j = Enemys.size() - 1; j >= 0; j--)
	{
		if (Enemys.at(j)->_life <= 0)
		{//remove

			if (Enemys.at(j)->_RemoveBy != 1)
			{
				ExplosionShow(Enemys.at(j)->getPosition());
			}

			Enemys.at(j)->Destroy();
		}
		else
		{
			Enemys.at(j)->Move();
		}
	}
}
void HelloWorld::ShotMove()
{
	//ShotMove

	for (int i = Bullets.size() - 1; i >= 0; i--)
	{
		if (Bullets.at(i)->_life == 0)
		{//remove
			Bullets.at(i)->Destroy();
		}
		else
		{
			Bullets.at(i)->Move();

			if (Bullets.at(i)->_isPlayers == 1)
			{
				for (int j = Enemys.size() - 1; j >= 0; j--)
				{
					if (Bullets.at(i)->boundingBox().intersectsRect(Enemys.at(j)->boundingBox()))
					{
						//미사일과 적 비행기가 부딪혔을 때

						//적 비행기 삭제
						Enemys.at(j)->_life--;

						if (Enemys.at(j)->getNumberOfRunningActions() == 0)
							Enemys.at(j)->runAction(Blink::create(0.3, 3));

						//미사일 삭제
						Bullets.at(i)->Destroy();
						break;
					}
				}
			}
			else if (isPlayerInvinc == 0 && Bullets.at(i)->boundingBox().intersectsRect(Player->boundingBox()))
			{
				if (PlayerHP <= 0)
				{
					ExplosionShow(Player->getPosition());
					ExplosionShow(Player->getPosition() + Vec2(20,40));
					ExplosionShow(Player->getPosition() + Vec2(-30, -10));
					ExplosionShow(Player->getPosition() + Vec2(10, -30));

					isPlayerInvinc = -10;
					Player->setVisible(false);

					auto gameoverSeq = Sequence::create(
						DelayTime::create(2),
						CallFunc::create(CC_CALLBACK_0(HelloWorld::GameOver, this)),
						NULL);
					this->runAction(gameoverSeq);
				}
				else
				{
					//getChildByTag(100+PlayerHP)-> removeFromParent();
					auto spinact = RotateBy::create(0.6, -135);
					getChildByTag(100 + PlayerHP)->runAction(spinact);
					getChildByTag(100 + PlayerHP)->setColor(Color3B(150,150,150));

					PlayerHP--;

					if (Player->getNumberOfRunningActions() == 0)
						Player->runAction(Blink::create(0.8, 4));
					isPlayerInvinc = InvincTime;
				}

				//미사일 삭제
				Bullets.at(i)->Destroy();
				break;
			}
		}
	}
}

//

bool HelloWorld::onTouchBegan(Touch *touch, Event *event)
{
	if (isGameOver == 1)
		return false;

	auto touchPoint = touch->getLocation();

	bool bTouch = pCircleBase->getBoundingBox().containsPoint(touchPoint);
	if (bTouch)
	{
		bOnTouch = true;
		pCircleArrow->setVisible(true);
	}
	return true;
}
void HelloWorld::onTouchMoved(Touch *touch, Event *event)
{
	if (bFirstTouch == false)
	{
		bFirstTouch = true;

		touchText->setVisible(false);
		touchText->stopAllActions();
		this->removeChild(touchText);
		pCircleBase->setColor(Color3B::WHITE);

		//CreateEnemyLoop();

		schedule(schedule_selector(HelloWorld::Update));
		schedule(schedule_selector(HelloWorld::PlayerFire), FireRate);
		StageLoader(0);
	}

	if (isGameOver == 1)
		return;

	auto touchPoint = touch->getLocation();

	int distance = sqrt(pow(touchPoint.x - pCircleBase->getPosition().x, 2) +
		pow(touchPoint.y - pCircleBase->getPosition().y, 2));

	if (distance >= 25) bDistance = true;
	else bDistance = false;

	if (bOnTouch == true)
	{
		degreeA =
			atan2(pCircleBase->getPosition().y - touchPoint.y,
				pCircleBase->getPosition().x - touchPoint.x);

		degreeA = 270 - degreeA * 180 / M_PI;
		float degree = degreeA + 45;

		pCircleArrow->setRotation(degree);
	}
}
void HelloWorld::onTouchEnded(Touch *touch, Event *event)
{
	if (isGameOver == 1)
		return;

	bOnTouch = false;
	pCircleArrow->setVisible(false);
}
void HelloWorld::ExitClick(Ref *sender)
{
	Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
	exit(0);
#endif
}

void HelloWorld::createBullet(Vec2 position, int type)
{
	Bullet *newB = new Bullet(this, position, type);
}
void HelloWorld::GameOver()
{
	isGameOver = 1;

	auto GameOver = Sprite::create("Images/1945/GameOver.png");
	GameOver->setAnchorPoint(Vec2(0.5,0.5));
	GameOver->setPosition(Vec2(160, 320));
	GameOver->setZOrder(600);
	this->addChild(GameOver);

	auto GameOverBlack = Sprite::create("Images/1945/Black.png");
	GameOverBlack->setAnchorPoint(Vec2(0, 0));
	GameOverBlack->setPosition(Vec2(0, 480));
	GameOverBlack->setZOrder(599);
	this->addChild(GameOverBlack);

	this->unschedule(schedule_selector(HelloWorld::Update));
	this->unschedule(schedule_selector(HelloWorld::PlayerFire));
	this->removeChild(pCircleArrow);
	
	Director::getInstance()->pause();
}
void HelloWorld::ExplosionShow(Vec2 Position)
{
	auto Explomation = Animation::create();
	Explomation->addSpriteFrameWithFileName("Images/exps/exp_01.png");
	Explomation->addSpriteFrameWithFileName("Images/exps/exp_02.png");
	Explomation->addSpriteFrameWithFileName("Images/exps/exp_03.png");
	Explomation->addSpriteFrameWithFileName("Images/exps/exp_04.png");
	Explomation->addSpriteFrameWithFileName("Images/exps/exp_05.png");

	Explomation->setDelayPerUnit(0.15f);

	//에니메이션 생성
	auto Explomate = Animate::create(Explomation);

	//애니메이션과 리무브액션 2개의 액션을 하나의 시퀀스로 등록후 runAction 실행
	auto Exploseq = Sequence::create(Explomate, RemoveSelf::create(), NULL);

	auto Explo = Sprite::create("Images/exps/exp_01.png");
	Explo->setAnchorPoint(Vec2(0.5, 0.5));
	Explo->setPosition(Vec2(Position.x, Position.y));
	Explo->setZOrder(10);
	this->addChild(Explo);
	Explo->runAction(Exploseq->clone());
}
