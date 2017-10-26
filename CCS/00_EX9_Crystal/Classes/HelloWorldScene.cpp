#include "HelloWorldScene.h"
//#include "SimpleAudioEngine.h"

USING_NS_CC;
#define PlayTime 30

TTFConfig ScoreFontConfig("fonts/Marker Felt.ttf", 20);

int HelpCountDown = 3;

int Time_Remain;
int BlockAdds[8] = { 0 };
int CurrentScore = 0;
int iHighScore;

Vec2 BombPoint = Vec2(-1, -1);
bool CreateBomb = false;

bool inGame = 0;

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

	/////////////////////////////

	winSize = Director::getInstance()->getWinSize();

	auto Background = Sprite::create("gamescene/resources-auto/background.png");
	Background->setPosition(Vec2::ZERO);
	Background->setAnchorPoint(Vec2::ZERO);
	Background->setScale(1);
	this->addChild(Background);

	CreateTitle();

	return true;
}
void HelloWorld::onEnter()
{
	Scene::onEnter();

	srand(time(NULL));

	listener = EventListenerTouchOneByOne::create();
	listener->setSwallowTouches(true);

	listener->onTouchBegan = CC_CALLBACK_2(HelloWorld::onTouchBegan, this);

	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);
}

bool HelloWorld::onTouchBegan(Touch *touch, Event *event)
{
	if (inGame == 0)
		return false;

	auto touchPoint = touch->getLocation();

	if (Layer_Play)
	{
		int temp = -1;

		for (int i = 0; i < 80; i++)
		{
			if (Board[i % 8][i / 8]->getBoundingBox().containsPoint(touchPoint))
			{
				temp = i; break;
			}
		}

		if (temp != -1)
		{
			RemoveCheck(Board[temp % 8][temp / 8]->_type, temp % 8, temp / 8);
		}
	}

	//

	for (int i = HelpGroup.size() - 1; i >= 0; i--)
	{
		Layer_Play->removeChild(HelpGroup.at(i));
		HelpGroup.eraseObject(HelpGroup.at(i));
	}

	HelpCountDown = 3;
	if (!this->isScheduled(schedule_selector(HelloWorld::HelpSchedule)))
	{
		this->schedule(schedule_selector(HelloWorld::HelpSchedule), 1);
	}
	

	return true;
}

Vector<block*> HelloWorld::SearchFloodGroup(int type, int _x, int _y)
{
	Vector<block*> FloodGroup;
	//log("Type : %d ,X : %d ,Y : %d", type, _x, _y);
	//log("Class X : %d ,Y : %d", Board[_x][_y]->X, Board[_x][_y]->Y);

	FloodGroup.pushBack(Board[_x][_y]);

	if (type == 10)	//touch bomb
	{
		for (int x = 0; x < 8; x++)
		{
			if (!FloodGroup.contains(Board[x][_y]) && Board[x][_y] && Board[x][_y]->_type != 10)
			{
				FloodGroup.pushBack(Board[x][_y]);
			}
		}
		for (int y = 0; y < 10; y++)
		{
			if (!FloodGroup.contains(Board[_x][y]) && Board[_x][y] && Board[_x][y]->_type != 10)
			{
				FloodGroup.pushBack(Board[_x][y]);
			}
		}
	}
	else //not bomb!
	{
		for (int i = 0; i < FloodGroup.size(); i++) // flood
		{
			int x = FloodGroup.at(i)->X;
			int y = FloodGroup.at(i)->Y;

			if (x + 1 < 8 && Board[x + 1][y]->_type == type && !FloodGroup.contains(Board[x + 1][y]))
			{
				FloodGroup.pushBack(Board[x + 1][y]);
			}

			if (x - 1 >= 0 && Board[x - 1][y]->_type == type && !FloodGroup.contains(Board[x - 1][y]))
			{
				FloodGroup.pushBack(Board[x - 1][y]);
			}

			if (y + 1 < 10 && Board[x][y + 1]->_type == type && !FloodGroup.contains(Board[x][y + 1]))
			{
				FloodGroup.pushBack(Board[x][y + 1]);
			}

			if (y - 1 >= 0 && Board[x][y - 1]->_type == type && !FloodGroup.contains(Board[x][y - 1]))
			{
				FloodGroup.pushBack(Board[x][y - 1]);
			}
		}
	}

	return FloodGroup;
}

void HelloWorld::HelpSchedule(float f)
{
	if (HelpCountDown == 0)
	{
		if(inGame == true)
		CreateHelp();
	}
	else
	{
		HelpCountDown--;
	}
}
void HelloWorld::CreateHelp()
{
	this->unschedule(schedule_selector(HelloWorld::HelpSchedule));
	Vector<block*> FloodGroup;

	for (int i = 0; i < 80; i++)
	{ 
		FloodGroup = SearchFloodGroup(
			Board[i%8][i/8]->_type, Board[i % 8][i / 8]->X, Board[i % 8][i / 8]->Y);
	
		if (FloodGroup.size() >= 3)
		{
			break;
		}
	}

	if (FloodGroup.size() >= 3)
	{
		log("K");
		for (int i = 0; i < FloodGroup.size(); i++)
		{
			auto Helprite = Sprite::create("crystals/resources-auto/hint.png");
			Helprite->setAnchorPoint(Vec2(0.5, 0.5));
			Helprite->setPosition(FloodGroup.at(i)->getPosition());

			auto Act = Sequence::create(
				FadeOut::create(0.8),
				FadeIn::create(0.8),
				NULL);

			auto Rep = RepeatForever::create(Act);

			Helprite->runAction(Rep);

			Layer_Play->addChild(Helprite);
			HelpGroup.pushBack(Helprite);
		}
	}
	else
	{
		return; //더이상 지울게 없음
	}

	//FloodGroup[1].eraseObject(FloodGroup[1].at(2));
}

void HelloWorld::RemoveCheck(int type, int _x, int _y)
{
	Vector<block*> FloodGroup = SearchFloodGroup( type,  _x,  _y);

	log("RG Size = %d", FloodGroup.size());
	if (FloodGroup.size() >= 3) // 크기 조건. 폭탄일때는 3개가 넘지 않을 수 없다
	{
		for (int i = FloodGroup.size() - 1; i >= 0; i--)
		{
			//Layer_Play->removeChild(FloodGroup.at(i));
			FloodGroup.at(i)->setVisible(false);

			Board[FloodGroup.at(i)->X][FloodGroup.at(i)->Y] = NULL;

			CurrentScore += 100;
			log("Removed x,y : %d %d", FloodGroup.at(i)->X, FloodGroup.at(i)->Y);

			CreateParticleAt(Vec2(FloodGroup.at(i)->getPosition().x, FloodGroup.at(i)->getPosition().y), 0);

			if (type == 10)
			{
				if(_x == FloodGroup.at(i)->X)
				 CreateParticleAt(Vec2(FloodGroup.at(i)->X * 80 + 40, FloodGroup.at(i)->Y * 80 + 40), 2);

				else if (_y == FloodGroup.at(i)->Y)
					CreateParticleAt(Vec2(FloodGroup.at(i)->X * 80 + 40, FloodGroup.at(i)->Y * 80 + 40), 3);
			}

		}

		if (type != 10 && FloodGroup.size() >= 6) // 폭탄 생성. 폭탄으로는 폭탄이 생기지 않는다.
		{
			CreateBomb = true;
			BombPoint = Vec2(_x, _y);
			log("BP %f %f", BombPoint.x, BombPoint.y);
			CreateBlock(_x, _y);

			for (int i = FloodGroup.size() - 1; i >= 0; i--)
			{
				CreateParticleAt(Vec2(FloodGroup.at(i)->getPosition().x, FloodGroup.at(i)->getPosition().y), 1);
			}
		}

		RefreshBoard();
	}

}

void HelloWorld::CreateTitle()
{
	Layer_Title = LayerColor::create(Color4B(0, 0, 0, 0));
	this->addChild(Layer_Title);

	auto TitleSprite = Sprite::create("mainscene/resources-auto/logo.png");
	TitleSprite->setAnchorPoint(Vec2(0.5, 0.5));
	TitleSprite->setPosition(Vec2(winSize.width / 2, winSize.height / 2 + 250));
	TitleSprite->setTag(0);
	TitleSprite->setZOrder(100);
	Layer_Title->addChild(TitleSprite);

	auto pMenuItem = MenuItemImage::create(
		"mainscene/resources-auto/btn-play.png",
		"mainscene/resources-auto/btn-play-down.png",
		CC_CALLBACK_0(HelloWorld::doClick_Play, this)
	);
	pMenuItem->setTag(1);

	auto pMenuItem2 = MenuItemImage::create(
		"mainscene/resources-auto/btn-about.png",
		"mainscene/resources-auto/btn-about-down.png",
		CC_CALLBACK_0(HelloWorld::doClick_About, this)
	);
	pMenuItem2->setTag(2);

	auto pMenu = Menu::create(pMenuItem, pMenuItem2, NULL);
	pMenu->alignItemsVerticallyWithPadding(-20);
	pMenu->setPosition(winSize.width / 2, winSize.height / 3);
	pMenu->setAnchorPoint(Vec2(0.5, 1));
	pMenu->setTag(3);
	pMenu->setZOrder(100);
	Layer_Title->addChild(pMenu);

	if (!UserDefault::getInstance()->getIntegerForKey("HighScore"))
	{
		UserDefault::getInstance()->setIntegerForKey("HighScore", 0);
	}

	iHighScore = UserDefault::getInstance()->getIntegerForKey("HighScore");
	char hs[100];
	sprintf(hs, "%d", iHighScore);

	auto highScore = Label::createWithBMFont("fonts/scorefont.fnt", hs);
	highScore->setPosition(Vec2(winSize.width / 2, 50));
	Layer_Title->addChild(highScore);

	TTFConfig ScoreTextFontConfig("fonts/Marker Felt.ttf", 20);
	auto highScore_Text = Label::createWithTTF(
		ScoreTextFontConfig, "HIGH SCORE", TextHAlignment::CENTER, 480);
	highScore_Text->setPosition(Vec2(winSize.width / 2, 10));
	highScore_Text->setAnchorPoint(Vec2(0.5, 0));
	Layer_Title->addChild(highScore_Text);

	for (int i = 0; i < 3; i++)
	{
		Sprite *Target;

		if (i == 0)
			Target = (Sprite*)Layer_Title->getChildByTag(i);
		else
			Target = (Sprite*)Layer_Title->getChildByTag(3)->getChildByTag(i);

		Target->setScale(0);

		auto Act = Sequence::create(
			DelayTime::create(0.15 * i),
			EaseElasticOut::create(ScaleTo::create(0.15, 1, 1), 0.4f),
			NULL
		);
		Target->runAction(Act);
	}

	BackgroundEffect_Main_JewelFall();
	BackgroundEffect_Main_Star();
}
void HelloWorld::doClick_Play()
{
	for (int i = 0; i < 3; i++)
	{
		Sprite *Target;

		if(i==0)
			Target = (Sprite*)Layer_Title->getChildByTag(i);
		else
			Target = (Sprite*)Layer_Title->getChildByTag(3)->getChildByTag(i);

		auto CloudSeq = Sequence::create(
			DelayTime::create(0.15 * i),
			ScaleTo::create(0.15,0,0),
			NULL
		);
		Target->runAction(CloudSeq);
	}

	auto DestroyTitleLayer = Sequence::create(
		DelayTime::create(0.8),
		RemoveSelf::create(),
		//CallFunc::create(CC_CALLBACK_0(HelloWorld::CreateTitle, this)),
		CallFunc::create(CC_CALLBACK_0(HelloWorld::CreatePlay, this)),
		NULL
	);

	Layer_Title->runAction(DestroyTitleLayer);
}
void HelloWorld::doClick_About()
{

}

void HelloWorld::CreatePlay()
{
	Layer_Play = LayerColor::create(Color4B(0, 0, 0, 0));
	this->addChild(Layer_Play);

	HeaderSprite = Sprite::create("gamescene/resources-auto/header.png");
	HeaderSprite->setAnchorPoint(Vec2(1, 1));
	HeaderSprite->setPosition(Vec2(winSize.width, winSize.height + 400));
	HeaderSprite->setTag(0);
	HeaderSprite->setZOrder(100);
	Layer_Play->addChild(HeaderSprite);

	auto TimerSprite = Sprite::create("gamescene/resources-auto/timer.png");

	TimerRemain = ProgressTimer::create(TimerSprite);
	TimerRemain->setType(ProgressTimer::Type::BAR);
	TimerRemain->setMidpoint(Vec2(0, 0));
	TimerRemain->setBarChangeRate(Vec2(1, 0));
	TimerRemain->setPercentage(100);

	TimerRemain->setAnchorPoint(Vec2(0.5,0.5));
	TimerRemain->setPosition(Vec2(winSize.width / 2, 45));
	TimerRemain->setTag(5);
	HeaderSprite->addChild(TimerRemain);

	auto Score = Label::createWithBMFont("fonts/scorefont.fnt", std::to_string(CurrentScore));
	Score->setAnchorPoint(Vec2(1, 1));
	Score->setPosition(Vec2(winSize.width - 15, HeaderSprite->getContentSize().height));
	Score->setScale(2);
	Score->setTag(1);
	HeaderSprite->addChild(Score);

	auto pMenuItem = MenuItemImage::create(
		"gamescene/resources-auto/btn-pause.png",
		"gamescene/resources-auto/btn-pause-down.png",
		CC_CALLBACK_0(HelloWorld::doClick_Stop, this)
	);
	pMenuItem->setTag(2);

	auto pMenu = Menu::create(pMenuItem, NULL);
	pMenu->setAnchorPoint(Vec2(0.5, 0.5));
	pMenu->setPosition(Vec2(36,HeaderSprite->getContentSize().height-36));
	pMenu->setTag(3);
	HeaderSprite->addChild(pMenu);

	HeaderSprite = (Sprite*)Layer_Play->getChildByTag(0);
	auto Act = Sequence::create(
		MoveBy::create(1, Vec2(0, -400)),
		NULL
	);
	HeaderSprite->runAction(Act);

	CreateBoard();

	auto CreateBoardAct = Sequence::create(
		DelayTime::create(0.15 * 10 + 0.3 + 0.3),
		CallFunc::create([&]() 
		{
		auto GoSprite = Sprite::create("gamescene/resources-auto/go.png");
		GoSprite->setPosition(Vec2(winSize.width / 2, winSize.height / 2));
		GoSprite->setScale(0);
		GoSprite->setZOrder(300);

		auto Act = Sequence::create(
			EaseElasticOut::create(ScaleTo::create(0.4, 1.5, 1.5), 0.4f),
			ScaleTo::create(0.2, 0, 0),
			NULL);

		Layer_Play->addChild(GoSprite);
		GoSprite->runAction(Act);
		
		inGame = 1;
		}),
		DelayTime::create(1),
		CallFunc::create([&]() 
		{
			inGame = 1; HelpCountDown = 3; Time_Remain = PlayTime;
			BackgroundEffect_Game_Star();
			BackgroundEffect_Game_Star();
			BackgroundEffect_Game_Light();
			this->schedule(schedule_selector(HelloWorld::HelpSchedule), 1);
			this->schedule(schedule_selector(HelloWorld::Timer), 1);
		}),
		NULL
	);

	Layer_Play->runAction(CreateBoardAct);
}

void HelloWorld::Timer(float f)
{
	Time_Remain--;

	TimerRemain->setPercentage((Time_Remain * 100 / PlayTime));

	if (Time_Remain == 0)
	{
		doClick_Stop();
	}
}

void HelloWorld::doClick_Stop()
{
	Layer_Play->stopAllActions();
	auto Target = (Sprite*)Layer_Play->getChildByTag(0);
	auto Act = Sequence::create(
		MoveBy::create(0.5, Vec2(0,400)),
		NULL
	);
	Target->runAction(Act);

	auto DestroyTitleLayer = Sequence::create(
		DelayTime::create(2),
		RemoveSelf::create(),
		//CallFunc::create(CC_CALLBACK_0(HelloWorld::CreateTitle, this)),
		CallFunc::create(CC_CALLBACK_0(HelloWorld::CreateTitle, this)),
		NULL
	);

	for (int i = HelpGroup.size() - 1; i >= 0; i--)
	{
		Layer_Play->removeChild(HelpGroup.at(i));
		HelpGroup.eraseObject(HelpGroup.at(i));
	}

	StopAction();
	Layer_Play->runAction(DestroyTitleLayer);
	inGame = 0;

	if (iHighScore < CurrentScore)
	{
		UserDefault::getInstance()->setIntegerForKey("HighScore", CurrentScore);
	}
	CurrentScore = 0;

	if (this->isScheduled(schedule_selector(HelloWorld::HelpSchedule)))
	{
		this->unschedule(schedule_selector(HelloWorld::HelpSchedule));
	}

	if (this->isScheduled(schedule_selector(HelloWorld::Timer)))
	{
		this->unschedule(schedule_selector(HelloWorld::Timer));
	}

}

void HelloWorld::StopAction()
{
	for (int i = 0; i < 80; i++)
	{
		if (Board[i % 8][i / 8])
		{
			float toX = winSize.width * 1.5 - rand() % ((int)winSize.width * 2);
			float toY = rand() % 100;

			auto Act = JumpTo::create(2, Vec2(toX, -200), rand()%500, 1);

			Board[i % 8][i / 8]->runAction(Act);
		}
	}
}

void HelloWorld::CreateBoard()
{
	for (int y = 0; y < 10; y++)
	{
		log("%d", y);
		for (int x = 0; x < 8; x++)
		{
			CreateBlock(x, y, y);
		}
	}
}

void HelloWorld::RefreshBoard()
{
	int check = -1;

	for (int x = 0; x < 8; x++)
	{
		for (int y = 0; y < 10; y++)
		{
			if (!Board[x][y])
			{
				for (int i = y; i < 10; i++)
				{
					if(Board[x][i]) Board[x][i]->_down++;
				}
				BlockAdds[x] ++;
			}
		}
	}

	for (int x = 0; x < 8; x++)
	{
		for (int y = 0; y < 10; y++)
		{
			if (Board[x][y] && Board[x][y]->_down != 0)
			{
				Board[x][y]->Y -= Board[x][y]->_down;
				Board[x][y - Board[x][y]->_down] = Board[x][y];

				auto Act = MoveBy::create(0.3, Vec2(0, -Board[x][y]->_down * 80));
				Board[x][y]->runAction(Act);

				Board[x][y]->_down = 0;
			}
		}

		for (int i = 1; i <= BlockAdds[x]; i++)
		{
			CreateBlock(x, 10 - i);
		}
		BlockAdds[x] = 0;
	}

	HeaderSprite->removeChild(HeaderSprite->getChildByTag(1),true);

	auto Score = Label::createWithBMFont("fonts/scorefont.fnt", std::to_string(CurrentScore));
	Score->setAnchorPoint(Vec2(1, 1));
	Score->setPosition(Vec2(winSize.width - 15, HeaderSprite->getContentSize().height));
	Score->setScale(2);
	Score->setTag(1);
	HeaderSprite->addChild(Score);
}

int HelloWorld::Check_Y(int _x,int _y)
{
	for (int y = _y + 1; y < 10; y++)
	{
		log("Check for %d,%d", _x, y);
		if (Board[_x][y])
		{
			return y;
		}
	}

	return -1; 
}

void HelloWorld::CreateBlock(int _x, int _y)
{
	block *newB;

	if (BombPoint == Vec2(_x, _y) && CreateBomb)
	{
		newB = new block(10, _x, _y);

		newB->setPosition(_x * 80 + 40, _y * 80 + 40);
		Layer_Play->addChild(newB);
		CreateBomb = false;
	}
	else
	{
		newB = new block(rand()%5, _x, _y);

		newB->setPosition(_x * 80 + 40, _y * 80 + 80 * 10 + 40);
		Layer_Play->addChild(newB);

		auto Act = MoveBy::create(0.3, Vec2(0, -800));
		newB->runAction(Act);
	}


	Board[_x][_y] = newB;
}
void HelloWorld::CreateBlock(int _x, int _y,int plus)
{
	block *newB;

	newB = new block(rand() % 5, _x, _y);

	newB->setPosition(_x * 80 + 40, _y * 80 + 80 * 10 + 40 + 200);
	Layer_Play->addChild(newB);

	auto Act = Sequence::create(DelayTime::create(0.2 * plus),MoveBy::create(0.2, Vec2(0, -1000)),NULL);
	newB->runAction(Act);

	Board[_x][_y] = newB;
}

void HelloWorld::CreateParticleAt(Vec2 _position,int _type)
{
	ParticleSystem *particle;

	if (_type == 0) //잼 일반 파괴
	{
		particle = ParticleSystemQuad::create("Particles/taken-gem.plist");
		particle->setDuration(0.5f);

		particle->setPosition(Vec2(_position));
	}
	else if (_type == 1) // 폭탄 생성시
	{
		log("BP %f %f", BombPoint.x, BombPoint.y);
		particle = ParticleFlower::create();;
		particle->setDuration(0.1f);

		auto texture = Director::getInstance()->getTextureCache()->addImage("crystals/resources-auto/bomb-light.png");
		particle->setTexture(texture);

		particle->setPosition(Vec2(_position));

		auto Act = Sequence::create(
			MoveTo::create(0.05, Vec2(Board[(int)BombPoint.x][(int)BombPoint.y]->getPosition())),
			NULL
		);
		particle->runAction(Act);

	}
	else if (_type == 2) //폭발 이팩트
	{
		particle = ParticleFlower::create();;
		particle->setDuration(0.05f);
		particle->setScaleX(2);
		particle->setScaleY(4);

		auto texture = Director::getInstance()->getTextureCache()->addImage("crystals/resources-auto/bomb-explo.png");
		particle->setTexture(texture);

		particle->setPosition(Vec2(_position));
	}
	else if (_type == 3) //폭발 이팩트
	{
		particle = ParticleSun::create();;
		particle->setDuration(0.05f);
		particle->setScaleX(4);
		particle->setScaleY(2);

		auto texture = Director::getInstance()->getTextureCache()->addImage("crystals/resources-auto/bomb-explo.png");
		particle->setTexture(texture);

		particle->setPosition(Vec2(_position));
	}

	particle->setAutoRemoveOnFinish(true);
	particle->setZOrder(200);

	this->addChild(particle);

}



void HelloWorld::BackgroundEffect_Main_Star()
{
	if (inGame == 1)
	{
		return;
	}

	ParticleSystem *particle;

	particle = ParticleSystemQuad::create("Particles/bg-stars.plist");
	particle->setPosition(Vec2(rand()%(int)winSize.width, rand() % (int)winSize.height));
	particle->setZOrder(1);
	particle->setDuration(6);
	particle->setAutoRemoveOnFinish(true);
	particle->setScale(1 + rand()%4);

	auto Act = Sequence::create(
		DelayTime::create(1.5 - (rand() % 15) * 0.1),
		CallFunc::create(CC_CALLBACK_0(HelloWorld::BackgroundEffect_Main_Star, this)),
		MoveBy::create(2,particle->getPosition() + Vec2(100 - rand()%200, 100 - rand()%200)),
		FadeOut::create(1.5 + (rand()%20) * 0.1),
		RemoveSelf::create(),
		NULL);

	particle->runAction(Act);

	Layer_Title->addChild(particle);
}
void HelloWorld::BackgroundEffect_Main_JewelFall()
{
	if (inGame == 1)
	{
		return;
	}

	char _addr[100] = "crystals/resources-auto/%d.png";
	sprintf(_addr, _addr, rand()%5);

	auto Spr = Sprite::create(_addr);
	Spr->setPosition(Vec2(rand() % (int)winSize.width, winSize.height + 200));

	auto Act = Sequence::create(
		DelayTime::create(1.5 - (rand() % 15) * 0.1),
		CallFunc::create(CC_CALLBACK_0(HelloWorld::BackgroundEffect_Main_JewelFall, this)),
		MoveBy::create(4 - (rand()%20) * 0.1, Vec2(100 - rand()%200, -winSize.height - 600)),
		RemoveSelf::create(),
		NULL);

	Spr->setScale(0.17 * (rand() % 3) + 0.5);
	if ((rand() % 3) != 0)
	{
		ParticleSystem *particle;

		particle = ParticleSystemQuad::create("Particles/falling-gem.plist");
		particle->setPosition(Vec2(40, 40));
		particle->setAnchorPoint(Vec2(0.5, 0.5));
		particle->setZOrder(1);

		Spr->addChild(particle);
	}

	Spr->runAction(Act);
	Spr->setZOrder(2);

	Layer_Title->addChild(Spr);
}

void HelloWorld::BackgroundEffect_Game_Light()
{
	if (inGame == 0)
	{
		return;
	}

	log("K");

	auto Spr = Sprite::create("gamescene/shimmer/resources-auto/bg-shimmer-1.png");
	Spr->setPosition(Vec2(winSize.width / 4 + rand() % (int)winSize.width / 2, winSize.height / 4 + rand() % (int)winSize.height / 2));
	Spr->setScale(2);
	Spr->setOpacity(200);

	auto Seq = Sequence::create(
		DelayTime::create(0.5 + rand() % 4),
		RotateBy::create(16, 360),
		CallFunc::create(CC_CALLBACK_0(HelloWorld::BackgroundEffect_Game_Light, this)),
		RemoveSelf::create(),
		NULL);

	Spr->runAction(Seq);
	Layer_Play->addChild(Spr);

	auto Spr2 = Sprite::create("gamescene/shimmer/resources-auto/bg-shimmer-1.png");
	Spr2->setPosition(Vec2(winSize.width / 4 + rand() % (int)winSize.width/2, winSize.height / 4 + rand() % (int)winSize.height/2));
	Spr2->setScale(2);
	Spr2->setOpacity(200);

	auto Seq2 = Sequence::create(
		DelayTime::create(0.5 + rand()%4),
		RotateBy::create(16, 360),
		RemoveSelf::create(),
		NULL);

	Spr2->runAction(Seq2);
	Layer_Play->addChild(Spr2);
}
void HelloWorld::BackgroundEffect_Game_Star()
{
	if (inGame == 0)
	{
		return;
	}

	int x = rand() % 9;
	int y = rand() % 11;

	auto Spr = Sprite::create("crystals/resources-auto/sparkle.png");
	Spr->setPosition(Vec2(x * 80,y * 80));

	auto Seq = Sequence::create(
		DelayTime::create(1.5 - (rand()%15) * 0.1),
		CallFunc::create(CC_CALLBACK_0(HelloWorld::BackgroundEffect_Game_Star, this)),
		DelayTime::create(2),
		RemoveSelf::create(),
		NULL);

	auto Spawn = Spawn::create(
		RotateBy::create(2,360),
		FadeOut::create(2),
		Seq,
		NULL);

	Spr->runAction(Spawn);
	Spr->setZOrder(1);

	Layer_Play->addChild(Spr);

}