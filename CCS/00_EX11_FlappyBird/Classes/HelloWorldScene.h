#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#if (CC_TARGET_PLATFORM == CC_PLATFORM_WIN32)
#pragma execution_character_set("utf-8")
#endif

#include "cocos2d.h"
#include "Box2D/Box2D.h"
#include <GLES-Render.h>

#define PTM_RATIO 32

using namespace cocos2d;

class HelloWorld : public cocos2d::Scene
	, public b2ContactListener
{
public:
	static cocos2d::Scene* createScene();
	virtual bool init();
	~HelloWorld();
	virtual void onEnter();
	virtual void onExit();

	CREATE_FUNC(HelloWorld);

	Sprite* Dummy;
	b2Body* Player;
	Label *ScoreText;

	Size winSize;
	bool IsTouched;
	bool IsStarted;

	void tick(float f);
	void Blocks(float f);

	b2World* _world;
	bool createBox2dWorld(bool Debug);
	void addNewSpriteAtPosition(Vec2 location,int type);
	bool onTouchBegan(Touch* touch, Event* event);

	GLESDebugDraw* m_debugDraw;
	virtual void draw(cocos2d::Renderer* renderer, const cocos2d::Mat4& transform, uint32_t flags) override;

	void BeginContact(b2Contact* contact);
	void PreSolve(b2Contact* contact, const b2Manifold* oldManifold);
	void EndContact(b2Contact* contact);

	void GroundCallBack();
	void GroundControl();

	std::vector<b2Body*> delVec;

protected:
	void onDraw(const cocos2d::Mat4& transform, uint32_t flags);
	cocos2d::CustomCommand _customCmd;
};

#endif // __HELLOWORLD_SCENE_H__
