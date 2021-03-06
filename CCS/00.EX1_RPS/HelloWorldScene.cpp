﻿#include "HelloWorldScene.h"
//#include "SimpleAudioEngine.h"

#include<stdlib.h>
#include<time.h>

int Ai_Pick();				//Ai 결정
int Judge(int Player, int Ai);		//결과 연산

int PlayerWinCount = 0;
int EnemyWinCount = 0;

int PlayerSelect = 0;
int EnemySelect = 0;
int Result = -1;

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
	srand((int)time(NULL)); 

	SetInitTexts(this);		//
	SetRPSMenu(this);		//한번만 그려짐

	SetCountNumbTexts(this);	//갱신마다 지워짐

	return true;
}
void HelloWorld::ResetALL(Ref *sender)
{
	for (int i = 0; i <= 5; i++)
	{
		removeChild(getChildByTag(i), true);
		//Tag 0~5까지 삭제
	}
}

void HelloWorld::SetInitTexts(Ref *sender)	//
{
	char Text[100];

	sprintf(Text, "Your Score : ", PlayerWinCount);
	auto PlayerWinCountText = LabelTTF::create(Text, "Arial", 20);
	PlayerWinCountText->setColor(Color3B::BLUE);
	PlayerWinCountText->setPosition(50, 290);
	PlayerWinCountText->setAnchorPoint(Vec2(0.0f, 1.0f));

	this->addChild(PlayerWinCountText);

	sprintf(Text, "Computer Score : ", EnemyWinCount);
	auto EnemyWinCountText = LabelTTF::create(Text, "Arial", 20);
	EnemyWinCountText->setColor(Color3B::BLUE);
	EnemyWinCountText->setPosition(430, 290);
	EnemyWinCountText->setAnchorPoint(Vec2(1.0f, 1.0f));

	this->addChild(EnemyWinCountText);
}
void HelloWorld::SetCountNumbTexts(Ref *sender)
{//점수 텍스트
	char Text[100];

	sprintf(Text, "%d", PlayerWinCount);
	auto PlayerWinCountText = LabelTTF::create(Text, "Arial", 20);
	PlayerWinCountText->setColor(Color3B::BLUE);
	PlayerWinCountText->setPosition(167, 289);
	PlayerWinCountText->setAnchorPoint(Vec2(0.0f, 1.0f));
	PlayerWinCountText->setTag(1);

	this->addChild(PlayerWinCountText);

	//

	sprintf(Text, "%d", EnemyWinCount);
	auto EnemyWinCountText = LabelTTF::create(Text, "Arial", 20);
	EnemyWinCountText->setColor(Color3B::BLUE);
	EnemyWinCountText->setPosition(432, 289);
	EnemyWinCountText->setAnchorPoint(Vec2(0.0f, 1.0f));
	EnemyWinCountText->setTag(2);

	this->addChild(EnemyWinCountText);

}
void HelloWorld::SetResultTexts(Ref *sender)
{//결과 출력
	SetCountNumbTexts(sender);
	char Text[100];

	char RText[3][50] = { "비겼습니다!","당신이 이겼습니다!","컴퓨터가 이겼습니다!" };
	auto ResultText = LabelTTF::create(RText[Result], "Arial", 25);
	ResultText->setColor(Color3B::RED);
	ResultText->setPosition(240, 260);
	ResultText->setAnchorPoint(Vec2(0.5f, 1.0f));
	ResultText->setTag(3);

	this->addChild(ResultText);

	///sprite///

	sprintf(Text, "Images/img%d.png", PlayerSelect);
	auto PlayerRPS = Sprite::create(Text);
	PlayerRPS->setPosition(50, 240);
	PlayerRPS->setAnchorPoint(Vec2(0.0f, 1.0f));
	PlayerRPS->setTag(4);
	PlayerRPS->setFlipX(true);

	this->addChild(PlayerRPS);

	sprintf(Text, "Images/img%d.png", EnemySelect);
	auto EnemyRPS = Sprite::create(Text);
	EnemyRPS->setPosition(430, 240);
	EnemyRPS->setAnchorPoint(Vec2(1.0f, 1.0f));
	EnemyRPS->setTag(5);
	EnemyRPS->setFlipX(false);

	this->addChild(EnemyRPS);
}
void HelloWorld::SetRPSMenu(Ref *sender)
{
	//RPS

	char RPS[3][20] = { "[ 가위 ]","[ 바위 ]","[  보  ]" };

	auto pMenu = Menu::create(NULL);
	for (int i = 0; i < 3; i++)
	{
		auto RPSItem = MenuItemFont::create(RPS[i], CC_CALLBACK_1(HelloWorld::doClick, this, 10 + i));
		RPSItem->setColor(Color3B::BLACK);
		RPSItem->setTag(10 + i);
		RPSItem->setPosition(Vec2(150 * i - 150, 0));
		pMenu->addChild(RPSItem);
	}

	auto RPSItem = MenuItemFont::create("[ 다시하기 ]", CC_CALLBACK_1(HelloWorld::doClick, this, 13));
	RPSItem->setColor(Color3B::BLACK);
	RPSItem->setTag(13);
	RPSItem->setPosition(Vec2(0, -50));
	pMenu->addChild(RPSItem);

	pMenu->setTag(20);
	pMenu->setPosition(Vec2(240, 90));
	this->addChild(pMenu);

}

void HelloWorld::doClick(Ref *sender, int Tag)
{
	if (Tag == 13)
	{
		ResetALL(sender);

		PlayerWinCount = 0;
		EnemyWinCount = 0;

		SetCountNumbTexts(sender);
	}
	else if (Tag >= 10 && Tag < 13)
	{
		ResetALL(sender);

		PlayerSelect = Tag - 9;
		EnemySelect = Ai_Pick();				//Ai 결정
		Result = Judge(PlayerSelect, EnemySelect);		//결과 연산

		if (Result == 1)
		{
			PlayerWinCount++;
		}
		else if (Result == 2)
		{
			EnemyWinCount++;
		}

		SetResultTexts(sender);
	}
}

int Ai_Pick()
{
	int pick;
	pick = rand() % 3 + 1;

	return pick;
}
int Judge(int Player, int Ai)
{
	int result;

	if (Player == Ai)	result = 0;	// 비김
	else
	{
		int temp = Player - Ai;
		if (temp == 1 || temp == -2)	//이김
		{
			result = 1;
		}
		else				//짐
			result = 2;
	}

	return result;
}
