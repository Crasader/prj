#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#if (CC_TARGET_PLATFORM == CC_PLATFORM_WIN32)
#pragma execution_character_set("utf-8")
#endif

#include "cocos2d.h"
#include "ControlManager.h"
#include "Entity.h"
#include "Joystick.h"

class HelloWorld : public cocos2d::Layer
{
public:
    static cocos2d::Scene* createScene();

    virtual bool init();
    
    CREATE_FUNC(HelloWorld);

	Joystick *joystick;
	cocos2d::Sprite *pMan;
	void tick(float dt);

	virtual void onTouchesBegan(const std::vector<Touch *>&touches, Event *event);
	virtual void onTouchesMoved(const std::vector<Touch *>&touches, Event *event);
	virtual void onTouchesEnded(const std::vector<Touch *>&touches, Event *event);
};

#endif // __HELLOWORLD_SCENE_H__
