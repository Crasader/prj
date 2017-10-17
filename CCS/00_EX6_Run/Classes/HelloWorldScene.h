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

	cocos2d::Size winSize;
	cocos2d::TMXTiledMap *tMap;
	cocos2d::TMXTiledMap *tMap2;
	cocos2d::TMXLayer* metainfo;

	cocos2d::Layer *layer;
	cocos2d::Sprite *Nyan;
	void moveBackground(float t);
	cocos2d::Vec2 tileCoordForPosition(cocos2d::Vec2 position);

};

#endif // __HELLOWORLD_SCENE_H__
