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

	cocos2d::Sprite *Runner;

	void callEveryFrame(float a);

	virtual void onEnter();
	virtual bool onTouchBegan(cocos2d::Touch *touch, cocos2d::Event *evet);

	cocos2d::RepeatForever *RunAni;
	/*cocos2d::RepeatForever *JumpAni;*/

};

#endif // __HELLOWORLD_SCENE_H__
