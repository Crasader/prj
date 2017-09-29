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

	cocos2d::Sprite * pBall;
	cocos2d::Sprite * pMan;
	cocos2d::Sprite * pWomen1;
	cocos2d::Sprite * pWomen2;

	void doAction(Ref *pSender);
	void doAction_Ease();
	void doAction_Elastic();
	void doAction_Bounce();
	void doAction_Speed();
};

#endif // __HELLOWORLD_SCENE_H__
