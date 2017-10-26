#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#if (CC_TARGET_PLATFORM == CC_PLATFORM_WIN32)
#pragma execution_character_set("utf-8")
#endif

#include "cocos2d.h"
#include "block.h"

class HelloWorld : public cocos2d::Scene
{
public:
    static cocos2d::Scene* createScene();

    virtual bool init();
    
    CREATE_FUNC(HelloWorld);

	cocos2d::Size winSize;

	virtual void onEnter();
	virtual bool onTouchBegan(cocos2d::Touch *touch, cocos2d::Event *evet);
	cocos2d::EventListenerTouchOneByOne *listener;

	//Title
	cocos2d::LayerColor *Layer_Title;
	void CreateTitle();
	void doClick_Play();
	void doClick_About();

	void BackgroundEffect_Main_Star();
	void BackgroundEffect_Main_JewelFall();

	//Play
	block *Board[8][10]; 
	cocos2d::ProgressTimer *TimerRemain;

	cocos2d::Vector<cocos2d::Sprite*> HelpGroup;
	cocos2d::LayerColor *Layer_Play;
	cocos2d::Sprite *HeaderSprite;

	void CreatePlay();
	void RefreshBoard();
	void doClick_Stop();

	int Check_Y(int _x, int _y);
	void CreateBoard();
	void CreateBlock(int, int);
	void CreateBlock(int, int, int);
	void CreateParticleAt(cocos2d::Vec2,int);
	void StopAction();
	void RemoveCheck(int type,int, int);
	void CreateHelp();
	void HelpSchedule(float f);
	void Timer(float f);

	cocos2d::Vector<block*> SearchFloodGroup(int type, int _x, int _y);

	void BackgroundEffect_Game_Light();
	void BackgroundEffect_Game_Star();
};

#endif // __HELLOWORLD_SCENE_H__
