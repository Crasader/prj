#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#if (CC_TARGET_PLATFORM == CC_PLATFORM_WIN32)
#pragma execution_character_set("utf-8")
#endif

#include "cocos2d.h"
#include "Monster.h"
#include "Item.h"

class HelloWorld : public cocos2d::Scene
{
public:
    static cocos2d::Scene* createScene();

    virtual bool init();
    
    CREATE_FUNC(HelloWorld);

	cocos2d::Layer *layer;
	cocos2d::Size winSize;
	cocos2d::TMXTiledMap *tMap;
	cocos2d::TMXLayer* metainfo;

	cocos2d::Vector<cocos2d::RepeatForever*> PlayerAnimation;
	cocos2d::Vector<cocos2d::RepeatForever*> MonstersAnimation;
	cocos2d::RepeatForever* DemonAnimation;
	cocos2d::RepeatForever* JellyAnimation;
	cocos2d::RepeatForever* WolfAnimation;


	cocos2d::SpriteFrameCache *cache;
	cocos2d::Sprite *Player;
	cocos2d::Sprite *itemSlot;
	cocos2d::Sprite *ReStart;
	cocos2d::Sprite *Black;
	cocos2d::LabelTTF *StageText;

	void setAnimations();
	void setPlayerPosition(cocos2d::Vec2 p);
	void LoadStage(int);
	void CreateMenu();
	void ItemUpdate(int type);
	void Reset();
	void Clear();

	cocos2d::Vec2 tileCoordForPosition(cocos2d::Vec2 position);

	cocos2d::Vector<cocos2d::RepeatForever*> createMultiAnimation(char *name, int NoS, int NoIdx, int NoD);
	cocos2d::RepeatForever* createSingleAnimation(char *name, int NumOfSprites, int NoD);

	virtual void onEnter();
	virtual bool onTouchBegan(cocos2d::Touch *touch, cocos2d::Event *event);
	virtual void onTouchEnded(cocos2d::Touch *touch, cocos2d::Event *event);
};

#endif // __HELLOWORLD_SCENE_H__
