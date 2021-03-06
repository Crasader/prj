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

	float _soundVolume;

	int audioId1;
	int audioId2;

	void preloadALL(Ref *pSender);
	void uncacheALL(Ref *pSender);

	void upVolume(Ref *pSender);
	void downVolume(Ref *pSender);

	void playSound1(Ref *pSender);
	void playSound2(Ref *pSender);

	void pauseSound1(Ref *pSender);
	void pauseSound2(Ref *pSender);
	void resumeSound1(Ref *pSender);
	void resumeSound2(Ref *pSender);
	void stopSound1(Ref *pSender);
	void stopSound2(Ref *pSender);

	void bgmPlayFinishedCallBack(int audioId, const std::
		string & filepath);

	~HelloWorld();
};

#endif // __HELLOWORLD_SCENE_H__
