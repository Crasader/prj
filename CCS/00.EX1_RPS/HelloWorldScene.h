﻿#ifndef __HELLOWORLD_SCENE_H__
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

	//

	void SetInitTexts(Ref *sender);
	void SetResultTexts(Ref *sender);
	void SetCountNumbTexts(Ref *sender);

	void doClick(Ref *sender,int Tag);
	void SetRPSMenu(Ref *sender);
	void ResetALL(Ref *sender);

};

#endif // __HELLOWORLD_SCENE_H__
