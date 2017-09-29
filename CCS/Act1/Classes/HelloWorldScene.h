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
	cocos2d::Sprite *pWoman;

	int temp = 0;

	void doAction(Ref *pSender);
	void doAction_Move();
	void doAction_Jump();
	void doAction_Rotate();
	void doAction_Scale();
	void doAction_Tint();
	void doAction_Place();
	void doAction_Blink();
	void doAction_Show();
	void doAction_FadeInOut();
};

#endif // __HELLOWORLD_SCENE_H__
