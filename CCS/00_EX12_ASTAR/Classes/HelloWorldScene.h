#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#if (CC_TARGET_PLATFORM == CC_PLATFORM_WIN32)
#pragma execution_character_set("utf-8")
#endif

#include "cocos2d.h"
#include "block.h"
#include "AstarNode.h"

using namespace cocos2d;

class HelloWorld : public cocos2d::Scene
{
public:
    static cocos2d::Scene* createScene();

    virtual bool init();
    
    CREATE_FUNC(HelloWorld);

	cocos2d::Size winSize;

	//

	cocos2d::EventListenerTouchOneByOne *listener;

	bool onTouchBegan(cocos2d::Touch *touch, cocos2d::Event *event);
	void onTouchMoved(cocos2d::Touch *touch, cocos2d::Event *event);
	void onEnter();

	Vector<AstarNode*> Nodes;
	Vector<AstarNode*> Open;
	Vector<AstarNode*> Close;
	Vector<MoveTo*> MoveVec;

	Vector<Vec2*> *Path;

	block *StartBlock;
	block *GoalBlock;
	Sprite *Player;

	void StartFind();
	void StartMove(AstarNode *End);
	void RunAction(float f);
	void CreateMenu();
	void NodeClear();

	MenuItemFont *StartMenuItem;
	bool ChangeStartSelected;
	MenuItemFont *EndMenuItem;
	bool ChangeEndSelected;
	MenuItemFont *BlockMenuItem;

	void SetStart();
	void SetEnd();
	void SetBlock();
	void RemoveWall();

	int FindMinNodeNumb();
};

#endif // __HELLOWORLD_SCENE_H__
