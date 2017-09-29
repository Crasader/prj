#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#if (CC_TARGET_PLATFORM == CC_PLATFORM_WIN32)
#pragma execution_character_set("utf-8")
#endif

#include "cocos2d.h"

class HelloWorld : public cocos2d::Scene
{
public:
    static cocos2d::Scene* createScene();

    virtual bool init();
    
    CREATE_FUNC(HelloWorld);

	void BackGroundBasic(Ref *pSender);
	void StartAction_BackGrounds(Ref *pSender);
	void StartAction_Titles(Ref *pSender);
	void StartAction_MainButtons(Ref *pSender);
	void StartAction_StarSpins(Ref *pSender);
	void StartAction_NoMoreBubbles(Ref *pSender);
	void StartAction_FishHere(Ref *pSender);
	void StartAction_Create(Ref *pSender);
};

#endif // __HELLOWORLD_SCENE_H__
