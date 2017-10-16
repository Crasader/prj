#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#if (CC_TARGET_PLATFORM == CC_PLATFORM_WIN32)
#pragma execution_character_set("utf-8")
#endif

#include "pugixml/pugixml.hpp"
#include "cocos2d.h"
#include "Bullet.h"
#include "Enemy.h"

class HelloWorld : public cocos2d::Scene
{
public:
    static cocos2d::Scene* createScene();

    virtual bool init();
    
    CREATE_FUNC(HelloWorld);

	void StageLoader(int number);
	void StageReader(pugi::xml_node node);

	pugi::xml_document xmlDoc;

	void PlayerSet();
	
	void CloudControl();
	void CloudCallBack();
	void CreateMenu();
	void ExitClick(Ref *pSender);
	void ExplosionShow(cocos2d::Vec2 Position);
	void createBullet(cocos2d::Vec2 position, int type);

	int xmlPosTrans(std::string str,int type);
	//void CreateEnemyLoop();
	void GameOver();
	int isGameOver = 0;

	virtual void onEnter();
	virtual bool onTouchBegan(cocos2d::Touch *touch, cocos2d::Event *evet);
	virtual void onTouchMoved(cocos2d::Touch *touch, cocos2d::Event *evet);
	virtual void onTouchEnded(cocos2d::Touch *touch, cocos2d::Event *evet);

	void Update(float time);
	void PlayerMove();
	void EnemyMove();
	void ShotMove();

	void PlayerFire(float time);

	cocos2d::Size winSize;
	float degreeA;
	
	cocos2d::Sprite *Player;
	cocos2d::Sprite *pCircleBase;
	cocos2d::Sprite *pCircleArrow;
	cocos2d::EventListenerTouchOneByOne *listener;
	cocos2d::LabelTTF *touchText;

	bool bOnTouch = false;
	bool bDistance = false;
	bool bFirstTouch = false;
};


#endif // __HELLOWORLD_SCENE_H__

