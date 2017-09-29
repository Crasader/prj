#include "HelloWorldScene.h"
//#include "SimpleAudioEngine.h"

USING_NS_CC;

#define Source "Assets/BB_Source_TITLE"

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

	BackGroundBasic(this);

    return true;
}


void HelloWorld::StartAction_BackGrounds(Ref *pSender)
{
	Sprite *TopBackLight = (Sprite *)getChildByTag(0);
	
	auto ActionFade = Sequence::create(
		FadeOut::create(4),
		FadeIn::create(0.5),
		NULL
	);
	TopBackLight->runAction(RepeatForever::create(ActionFade));

	Sprite *BackLight = (Sprite *)getChildByTag(1);

	ActionFade = Sequence::create(
		FadeOut::create(4),
		DelayTime::create(2),
		FadeIn::create(4),
		NULL
	);
	BackLight->runAction(RepeatForever::create(ActionFade));
}
void HelloWorld::StartAction_Titles(Ref *pSender)
{
	Sprite *TitleBase = (Sprite *)getChildByTag(10);

	auto Action = Sequence::create(
		MoveBy::create(2, Vec3(0, 20, 0)),
		MoveBy::create(2, Vec3(0, -20, 0)),
		NULL
	);
	TitleBase->runAction(RepeatForever::create(Action));


	Sprite *TitleBright = (Sprite *)getChildByTag(10)->getChildByTag(11);

	 Action = Sequence::create(
		FadeOut::create(1.5),
		FadeIn::create(1.5),
		NULL
	);
	TitleBright->runAction(RepeatForever::create(Action));
}
void HelloWorld::StartAction_MainButtons(Ref *pSender)
{
	Sprite *Surround = (Sprite *)getChildByTag(20)->getChildByTag(21);

	auto Action = Sequence::create(
		FadeOut::create(1),
		FadeIn::create(1),
		NULL
	);
	Surround->runAction(RepeatForever::create(Action));
}
void HelloWorld::StartAction_StarSpins(Ref *pSender)
{
	Sprite *Star = (Sprite *)getChildByTag(30);

	auto Action = Sequence::create(
		RotateBy::create(2.5,360,360),
		NULL
	);
	Star->runAction(RepeatForever::create(Action));

	Star = (Sprite *)getChildByTag(31);

	 Action = Sequence::create(
		RotateBy::create(1.5, 360, 360),
		NULL
	);
	Star->runAction(RepeatForever::create(Action));

	Star = (Sprite *)getChildByTag(32);

	Action = Sequence::create(
		RotateBy::create(1.5, 360, 360),
		NULL
	);
	Star->runAction(RepeatForever::create(Action));


	Star = (Sprite *)getChildByTag(33);

	Action = Sequence::create(
		FadeOut::create(1),
		FadeIn::create(1),
		DelayTime::create(1),
		NULL
	);
	Star->runAction(RepeatForever::create(Action));
}
void HelloWorld::StartAction_NoMoreBubbles(Ref *pSender)
{
	Sprite *Bubble = (Sprite *)getChildByTag(50);

	auto Action = Sequence::create(
		Place::create(Vec2(500, -500)),
		MoveTo::create(4, Vec2(500, 1500)),
		NULL
	);
	Bubble->runAction(RepeatForever::create(Action));

	Bubble = (Sprite *)getChildByTag(51);

	 Action = Sequence::create(
		Place::create(Vec2(500, -500)),
		MoveTo::create(6, Vec2(500, 1500)),
		NULL
	);
	Bubble->runAction(RepeatForever::create(Action));

	Bubble = (Sprite *)getChildByTag(52);

	Action = Sequence::create(
		Place::create(Vec2(500, -500)),
		MoveTo::create(7, Vec2(500, 1500)),
		NULL
	);
	Bubble->runAction(RepeatForever::create(Action));

	Bubble = (Sprite *)getChildByTag(53);

	Action = Sequence::create(
		Place::create(Vec2(500, -500)),
		MoveTo::create(5, Vec2(500, 1500)),
		NULL
	);
	Bubble->runAction(RepeatForever::create(Action));
}
void HelloWorld::StartAction_FishHere(Ref *pSender)
{
	Sprite *Fish = (Sprite *)getChildByTag(40);

	auto Action = Sequence::create(
		Place::create(Vec2(-400, 460)),
		MoveTo::create(16, Vec2(800, 460)),
		NULL
	);
	Fish->runAction(RepeatForever::create(Action));

	Fish = (Sprite *)getChildByTag(41);

	 Action = Sequence::create(
		Place::create(Vec2(800, 500)),
		MoveTo::create(12, Vec2(-400, 500)),
		NULL
	);
	Fish->runAction(RepeatForever::create(Action));
}
void HelloWorld::StartAction_Create(Ref *pSender)
{
	Sprite *Bub = (Sprite *)getChildByTag(100)->getChildByTag(101);

	auto Action = Sequence::create(
		RotateBy::create(1, 360, 360),
		NULL
	);
	Bub->runAction(RepeatForever::create(Action));
}

void HelloWorld::BackGroundBasic(Ref *pSender)
{
	char str[200];


	///////////////
	//BackGrounds//
	///////////////

	auto Background = Sprite::create("Images/Background.png");
	Background->setAnchorPoint(Vec2(0, 0));
	this->addChild(Background);

	sprintf(str, "%s/Bubble_Effect/Lighting_Background.png", Source);
	auto Background2 = Sprite::create(str);
	Background2->setAnchorPoint(Vec2(0, -2));
	Background2->setPosition(Vec2(0, 30));
	Background2->setTag(0);
	this->addChild(Background2);

	sprintf(str, "%s/Flash_Effect/All_Light.png", Source);
	auto Flashing = Sprite::create(str);
	Flashing->setAnchorPoint(Vec2(0,0));
	Flashing->setPosition(Vec2(0, 30));
	Flashing->setTag(1);
	this->addChild(Flashing);

	StartAction_BackGrounds(this);

	///////////////
	//MainButtons//
	///////////////

	sprintf(str, "%s/Bubble_Button/inv.png", Source);
	auto Base_Re = Sprite::create(str);
	Base_Re->setTag(20);
	Base_Re->setPosition(Vec2(380, 240));
	Base_Re->setZOrder(120);
	
	this->addChild(Base_Re);

	sprintf(str, "%s/Bubble_Button/Play_Button/Play_Button_01.png", Source);
	auto ButtonBase_Re = Sprite::create(str);
	ButtonBase_Re->setPosition(Vec2(140, 195));
	Base_Re->addChild(ButtonBase_Re);

	//CLICK IMG CHANGE to Vibration_OFF.png
	sprintf(str, "%s/Bubble_Button/Setting_Button/Vibration_ON.png", Source);
	auto Setting_Button = Sprite::create(str);
	Setting_Button->setPosition(Vec2(270, 70));
	Base_Re->addChild(Setting_Button);

	//ACTION!
	sprintf(str, "%s/Bubble_Button/Base.png", Source);
	auto Base = Sprite::create(str);
	Base->setPosition(Vec2(170, 170));
	Base->setTag(21);
	Base_Re->addChild(Base);

	StartAction_MainButtons(this);


	///////////////
	// Game Logo //
	///////////////

	sprintf(str, "%s/Bubble_Button/inv.png", Source);
	auto TitleBase = Sprite::create(str);
	TitleBase->setPosition(Vec2(520, 880));
	TitleBase->setAnchorPoint(Vec2(0.5f, 0.5f));
	TitleBase->setZOrder(120);
	TitleBase->setTag(10);

	this->addChild(TitleBase);

	sprintf(str, "%s/Game_Logo/Bubble_Logo.png", Source);
	auto TitleLogo = Sprite::create(str);
	TitleLogo->setZOrder(120);
	TitleBase->addChild(TitleLogo);

	sprintf(str, "%s/Flash_Effect/Logo_Light.png", Source);
	auto TitleLogo_Light = Sprite::create(str);
	TitleLogo_Light->setZOrder(100);
	TitleLogo_Light->setTag(11);
	TitleBase->addChild(TitleLogo_Light);

	StartAction_Titles(this);

	///////////////
	// CreateBtn //
	///////////////

	sprintf(str, "%s/Bubble_Button/inv.png", Source);
	auto Create_Button_Base = Sprite::create(str);
	Create_Button_Base->setPosition(Vec2(795, 195));
	Create_Button_Base->setAnchorPoint(Vec2(0.5f,0.5f));
	Create_Button_Base->setZOrder(120);
	Create_Button_Base->setTag(100);

	this->addChild(Create_Button_Base);

	sprintf(str, "%s/Bubble_Button/Create_Button/Create_Button_01.png", Source);
	auto Create_Button = Sprite::create(str);
	Create_Button->setScale(1);

	Create_Button_Base->addChild(Create_Button);

	//Action..Spin?
	sprintf(str, "%s/Bubble_Button/Create_Button/Create_base.png", Source);
	auto Create_Button_Bubble = Sprite::create(str);
	Create_Button_Bubble->setScale(1);
	Create_Button_Bubble->setTag(101);

	Create_Button_Base->addChild(Create_Button_Bubble);

	StartAction_Create(this);


	///////////////
	// SpinStars //
	///////////////

	sprintf(str, "%s/Background_Effect/Blue_Star.png", Source);
	auto Spin_Blue_Star = Sprite::create(str);
	Spin_Blue_Star->setPosition(Vec2(100, 160));
	Spin_Blue_Star->setAnchorPoint(Vec2(0.5f, 0.5f));
	Spin_Blue_Star->setScale(1.25);
	Spin_Blue_Star->setTag(30);

	this->addChild(Spin_Blue_Star);

	sprintf(str, "%s/Background_Effect/Gold_Star.png", Source);
	auto Spin_Gold_Star = Sprite::create(str);
	Spin_Gold_Star->setPosition(Vec2(320, 50));
	Spin_Gold_Star->setAnchorPoint(Vec2(0.5f, 0.5f));
	Spin_Gold_Star->setScale(1.25);
	Spin_Gold_Star->setColor(Color3B(150, 150, 150));
	Spin_Gold_Star->setTag(31);

	this->addChild(Spin_Gold_Star);

	sprintf(str, "%s/Background_Effect/Purple_Star.png", Source);
	auto Spin_Purple_Star = Sprite::create(str);
	Spin_Purple_Star->setPosition(Vec2(600, 90));
	Spin_Purple_Star->setAnchorPoint(Vec2(0.5f, 0.5f));
	Spin_Purple_Star->setScale(1);
	Spin_Purple_Star->setTag(32);

	this->addChild(Spin_Purple_Star);

	sprintf(str, "%s/Flash_Effect/Lighting.png", Source);
	auto Shinig_Stars = Sprite::create(str);
	Shinig_Stars->setPosition(Vec2(360, 100));
	Shinig_Stars->setAnchorPoint(Vec2(0.5f, 0.5f));
	Shinig_Stars->setScale(1);
	Shinig_Stars->setTag(33);

	this->addChild(Shinig_Stars);

	StartAction_StarSpins(this);

	///////////////
	// BackFishs //
	///////////////

	sprintf(str, "%s/Fish_Effect/Fish_001.png", Source);
	auto FishLow = Sprite::create(str);
	FishLow->setPosition(Vec2(50, 450));
	FishLow->setAnchorPoint(Vec2(0.5f, 0.5f));
	FishLow->setScale(1);
	FishLow->setOpacity(150);
	FishLow->setTag(40);

	this->addChild(FishLow);

	sprintf(str, "%s/Fish_Effect/Fish_002.png", Source);
	auto FishHigh = Sprite::create(str);
	FishHigh->setPosition(Vec2(560, 470));
	FishHigh->setAnchorPoint(Vec2(0.5f, 0.5f));
	FishHigh->setScale(1);
	FishHigh->setOpacity(150);
	FishHigh->setTag(41);

	this->addChild(FishHigh);

	StartAction_FishHere(this);

	///////////////
	// BubBubble //
	///////////////

	sprintf(str, "%s/Bubble_Effect/Title_Bubble_001.png", Source);
	auto Bubble01 = Sprite::create(str);
	Bubble01->setPosition(Vec2(500, 500));
	Bubble01->setScale(1);
	Bubble01->setTag(50);

	this->addChild(Bubble01);

	sprintf(str, "%s/Bubble_Effect/Title_Bubble_002.png", Source);
	auto Bubble02 = Sprite::create(str);
	Bubble02->setPosition(Vec2(500, 500));
	Bubble02->setScale(1);
	Bubble02->setTag(51);

	this->addChild(Bubble02);

	sprintf(str, "%s/Bubble_Effect/Title_Bubble_003.png", Source);
	auto Bubble03 = Sprite::create(str);
	Bubble03->setPosition(Vec2(500, 500));
	Bubble03->setScale(1);
	Bubble03->setTag(52);

	this->addChild(Bubble03);

	sprintf(str, "%s/Bubble_Effect/Title_Bubble_004.png", Source);
	auto Bubble04 = Sprite::create(str);
	Bubble04->setPosition(Vec2(500, 500));
	Bubble04->setScale(1);
	Bubble04->setTag(53);

	this->addChild(Bubble04);

	StartAction_NoMoreBubbles(this);
}