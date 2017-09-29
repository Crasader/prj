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

	cocos2d::Sprite *pMan;
	cocos2d::Sprite *pCircleBase;
	cocos2d::Sprite *pCircleArrow;
	cocos2d::EventListenerTouchOneByOne *listener;

	virtual void onEnter();
	virtual void onExit();
	virtual bool onTouchBegan(cocos2d::Touch *touch, cocos2d::Event *evet);
	virtual void onTouchMoved(cocos2d::Touch *touch, cocos2d::Event *evet);
	virtual void onTouchEnded(cocos2d::Touch *touch, cocos2d::Event *evet);
	virtual void onTouchCancelled(cocos2d::Touch *touch,cocos2d::Event *evet);

	void callEveryFrame(float a);
	cocos2d::Vec2 touchPoint;
};

#endif // __HELLOWORLD_SCENE_H__
