#include "HelloWorldScene.h"
#include "SimpleAudioEngine.h"


#define _SWAPNUMB 100
#define NofC 20

#define EFFECT_DING "Sounds/ding.wav"
#define EFFECT_RESULT "Sounds/result.wav"
#define EFFECT_DEL "Sounds/del_block.wav"
#define EFFECT_ERR "Sounds/error.wav"

int Number_CurrentTouched = -1;
int Type_CurrentTouched = -1;
int Score = 0;
int Try = 0;
bool canTouchThis = true;

USING_NS_CC;
using namespace CocosDenshion;

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

	auto wlayer = LayerColor::create(Color4B::BLACK);
	this->addChild(wlayer);

	/////////////////////////////

	Cards.clear();

	for (int i = 0; i < 20; i++)
	{
		char name[20];
		sprintf(name, "Images/card%02d.png", (i / 2) + 1);

		auto back = Sprite::create(name);
		back->setAnchorPoint(Vec2(0, 0));
		back->setZOrder(0);
		back->setPosition(Vec2(85 * (i % 4), transYpos(85 * (i / 4))));

		Card *spr = new Card((i/2)+1,i, back);
		spr->setTexture("Images/box_normal.png");
		spr->setAnchorPoint(Vec2(0, 0));
		spr->setPosition(Vec2(85 * (i % 4), transYpos(85 * (i / 4))));
		spr->setScale(1);
		spr->setTag(i);
		spr->setZOrder(300);

		this->addChild(spr);
		this->addChild(back);

		Cards.pushBack(spr);
	}


	char name[20];
	sprintf(name, "%2d / 20\n%d Try",0,0);

	ScoreLabel = LabelTTF::create(name, "Arial", 24);
	ScoreLabel->setAnchorPoint(Vec2(1, 1));
	ScoreLabel->setPosition(Point(450, 500));
	ScoreLabel->setColor(Color3B(255, 255, 255));
	ScoreLabel->setOpacity(255);
	this->addChild(ScoreLabel);

	swapALL();

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
bool HelloWorld::onTouchBegan(cocos2d::Touch *touch, cocos2d::Event *evet)
{
	if (!canTouchThis)
	{
		return false;
	}

	auto touchPoint = touch->getLocation();
	bool bTouch = false;
	int i;

	for (i = 0; i < 20; i++)
	{
		if (bTouch = Cards.at(i)->getBoundingBox().containsPoint(touchPoint))
			break;
	}
	if (bTouch && Number_CurrentTouched != i && Cards.at(i)->_isGone != true)
	{
		log("Touched : %d", i);
		Cards.at(i)->setVisible(false);

		if (Number_CurrentTouched != -1)
		{
			canTouchThis = false;

			if (Type_CurrentTouched == Cards.at(i)->_type)
			{
				log("MATCH");
				SimpleAudioEngine::getInstance()->playEffect(EFFECT_DING);

				//터치 막고 & 잠시 뒤에
				auto Act = Sequence::create(
					DelayTime::create(0.5),
					CallFunc::create(CC_CALLBACK_0(HelloWorld::Check, this, i, true)),
					NULL);
				this->runAction(Act);
			}
			else
			{
				log("NOT MATCH");

				//터치 막고 & 잠시 뒤에
				auto Act = Sequence::create(
					DelayTime::create(0.5),
					CallFunc::create(CC_CALLBACK_0(HelloWorld::Check, this, i, false)),
					NULL);
				this->runAction(Act);
			}
		}
		else
		{
			Number_CurrentTouched = i;
			Type_CurrentTouched = Cards.at(i)->_type;
		}
	}

	return true;
}
float HelloWorld::transYpos(float a)
{
	return this->getContentSize().height - 85 - a;
}

void HelloWorld::swapALL()
{
	for (int i = 0; i < _SWAPNUMB; i++)
	{
		swap(Cards.at(rand() % 20), Cards.at(rand() % 20));
	}
}

void HelloWorld::swap(Card *a, Card *b)
{
	Vec2 temp;

	temp = (a->getPosition());
	a->setPosition(b->getPosition());
	b->setPosition(temp);

	a->_Back->setPosition(a->getPosition());
	b->_Back->setPosition(b->getPosition());
}

void HelloWorld::Check(int i,bool isMatch)
{
	Sequence *CardAct;
	Try++;

	if (isMatch)
	{
		Cards.at(Number_CurrentTouched)->_Back->setVisible(false);
		Cards.at(Number_CurrentTouched)->_isGone = true;
		Cards.at(i)->_Back->setVisible(false);
		Cards.at(i)->_isGone = true;

		Number_CurrentTouched = -1;
		Type_CurrentTouched = -1;

		Score += 2;

		if (Score == NofC)
		{
			//Clear
			log("CLEAR!");
			SimpleAudioEngine::getInstance()->playEffect(EFFECT_DEL);
			SimpleAudioEngine::getInstance()->playEffect(EFFECT_RESULT);


			auto pLabel = LabelTTF::create("Clear!", "Arial", 64);
			pLabel->setPosition(Point(225, 250));
			pLabel->setColor(Color3B(255, 255, 255));
			pLabel->setOpacity(255);
			this->addChild(pLabel);
		}
		else
		{
			SimpleAudioEngine::getInstance()->playEffect(EFFECT_DEL);
		}
	}
	else
	{
		Cards.at(Number_CurrentTouched)->setVisible(true);
		Cards.at(i)->setVisible(true);

		Number_CurrentTouched = -1;
		Type_CurrentTouched = -1;

		SimpleAudioEngine::getInstance()->playEffect(EFFECT_ERR);
	}


	char name[20];
	sprintf(name, "%2d / 20\n%d Try", Score, Try);

	this->removeChild(ScoreLabel);
	ScoreLabel = LabelTTF::create(name, "Arial", 24);
	ScoreLabel->setAnchorPoint(Vec2(1, 1));
	ScoreLabel->setPosition(Point(450, 500));
	ScoreLabel->setColor(Color3B(255, 255, 255));
	ScoreLabel->setOpacity(255);
	this->addChild(ScoreLabel);

	canTouchThis = true;
}
