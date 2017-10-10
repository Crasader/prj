#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#if (CC_TARGET_PLATFORM == CC_PLATFORM_WIN32)
#pragma execution_character_set("utf-8")
#endif

#include "cocos2d.h"
#include "Card.h"

using namespace cocos2d;

class HelloWorld : public cocos2d::Scene
{
public:
    static cocos2d::Scene* createScene();

    virtual bool init();

	Vector<Card*> Cards;
	LabelTTF * ScoreLabel;

    CREATE_FUNC(HelloWorld);

	float transYpos(float a);
	void swap(Card *a, Card *b);
	void swapALL();
	void Check(int i, bool b);

	cocos2d::EventListenerTouchOneByOne *listener;
	virtual void onEnter();
	bool onTouchBegan(Touch *touch, Event *evet);
};

#endif // __HELLOWORLD_SCENE_H__
