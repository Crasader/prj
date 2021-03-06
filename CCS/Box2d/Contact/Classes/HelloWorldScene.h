﻿#ifndef __HELLOWORLD_SCENE_H__
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

	CREATE_FUNC(HelloWorld);

	bool createBox2dWorld(bool Debug);
	~HelloWorld();
	virtual void draw(cocos2d::Renderer* renderer, const cocos2d::Mat4& transform, uint32_t flags) override;

	virtual void onEnter();
	virtual void onExit();
	virtual bool onTouchBegan(Touch *touch, Event *event);
	virtual void onTouchMoved(Touch *touch, Event *event);
	virtual void onTouchEnded(Touch *touch, Event *event);
	void tick(float f);

	b2Body* addNewSpriteAtPosition(Vec2 point, Size size, b2BodyType bodytype,
		const char* spriteName, int type);
	b2Body* getBodyAtTab(Vec2 p);

	Size winSize;
	Texture2D *texture;
	b2World* _world;

	GLESDebugDraw* m_debugDraw;

	bool bDrag;
	b2Body *dragBody;
	b2MouseJoint *mouseJoint;
	b2Body *gbody;

	void SetBox2dWorld();


	int num;

	void BeginContact(b2Contact* contact);
	void PreSolve(b2Contact* contact, const b2Manifold* oldManifold);
	void PostSolve(b2Contact* contact, const b2ContactImpulse* impulse);
	void EndContact(b2Contact* contact);

protected:
	void onDraw(const cocos2d::Mat4& transform, uint32_t flags);
	cocos2d::CustomCommand _customCmd;

};

#endif // __HELLOWORLD_SCENE_H__
