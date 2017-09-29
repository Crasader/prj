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
	cocos2d::EventListenerTouchAllAtOnce *listener;

	virtual void onEnter();
	virtual void onExit();
	virtual bool onTouchesBegan(const std::vector<cocos2d::Touch*> &touches, cocos2d::Event *evet);
	virtual void onTouchesMoved(const std::vector<cocos2d::Touch*> &touches, cocos2d::Event *evet);
	virtual void onTouchesEnded(const std::vector<cocos2d::Touch*> &touches, cocos2d::Event *evet);
	virtual void onTouchesCancelled(const std::vector<cocos2d::Touch*> &touches, cocos2d::Event *evet);
};

#endif // __HELLOWORLD_SCENE_H__
