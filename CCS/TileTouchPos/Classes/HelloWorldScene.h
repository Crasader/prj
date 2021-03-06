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

	virtual void onEnter();
	virtual void onExit();

	bool onTouchBegan(cocos2d::Touch *touch, cocos2d::Event *event);
	cocos2d::Vec2 touchToXY(cocos2d::Vec2 touch);

	cocos2d::TMXTiledMap *map;
};

#endif // __HELLOWORLD_SCENE_H__
