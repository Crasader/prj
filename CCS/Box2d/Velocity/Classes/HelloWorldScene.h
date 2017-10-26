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
{
public:
	static cocos2d::Scene* createScene();
	b2Body* body0;
	b2WheelJoint* m_spring1;
	b2WheelJoint* m_spring2;
	virtual bool init();

	CREATE_FUNC(HelloWorld);

	bool createBox2dWorld(bool Debug);
	~HelloWorld();
	virtual void draw(cocos2d::Renderer* renderer, const cocos2d::Mat4& transform, uint32_t flags) override;

	virtual void onEnter();
	virtual void onExit();
	virtual void onTouchMoved(Touch *touch, Event *event);
	void tick(float f);


	Size winSize;
	Texture2D *texture;
	b2World* _world;

	GLESDebugDraw* m_debugDraw;

	bool bDrag;
	b2Body *dragBody;
	b2MouseJoint *mouseJoint;
	b2Body *gbody;

	void SetBox2dWorld();

	b2Body* myBall;
	float  playerVelocity;
	bool   playerIsFlying;

	b2Body* addNewSprite(Vec2 point, Size size, b2BodyType bodytype,
		const char* spriteName, int type);
	b2Body* getBodyAtTab(Point p);
	void addNewSpriteAtPosition(Vec2 location);
	bool onTouchBegan(Touch* touch, Event* event);
	void onTouchEnded(Touch* touch, Event* event);

protected:
	void onDraw(const cocos2d::Mat4& transform, uint32_t flags);
	cocos2d::CustomCommand _customCmd;

};

#endif // __HELLOWORLD_SCENE_H__
