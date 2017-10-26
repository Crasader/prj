#include "HelloWorldScene.h"
#include "MyBodyParser.h"
//#include "SimpleAudioEngine.h"

USING_NS_CC;

Scene* HelloWorld::createScene()
{
    return HelloWorld::create();
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    if ( !Scene::init() )
    {
        return false;
    }

	/////////////////////////////

	winSize = Director::getInstance()->getWinSize();


	texture = Director::getInstance()->getTextureCache()->addImage("blocks.png");


	if (this->createBox2dWorld(true))
	{
		this->schedule(schedule_selector(HelloWorld::tick));
	}

    return true;
}

bool HelloWorld::createBox2dWorld(bool debug)
{
	b2Vec2 gravity = b2Vec2(0.0f, -30.0f); // 중력의 방향을 결정한다.
	_world = new b2World(gravity);

	_world->SetAllowSleeping(true); // 휴식중 멈출지 여부. 켜라
	_world->SetContinuousPhysics(true); //지속적 물리작용 여부
	
	if (debug)
	{
		//적색 : 현재 물리 운동 중 <-> 회색

		m_debugDraw = new GLESDebugDraw(PTM_RATIO);
		_world->SetDebugDraw(m_debugDraw);

		uint32 flags = 0;
		flags += b2Draw::e_shapeBit;
		//flags += b2Draw::e_jointBit;
		//flags += b2Draw::e_aabbBit;
		//flags += b2Draw::e_pairBit;
		//flags += b2Draw::e_centerOfMassBit;

		m_debugDraw->SetFlags(flags);
	}


	//가장자리 생성

	b2BodyDef groundBodyDef;
	groundBodyDef.position.Set(0, 0);
	b2Body *groundBody = _world->CreateBody(&groundBodyDef);


	//경계면을 그릴 수 있는 객체 생성
	b2EdgeShape groundEdge;
	b2FixtureDef boxShapeDef;
	boxShapeDef.shape = &groundEdge;

	//아래
	groundEdge.Set(b2Vec2(0, 0), b2Vec2(winSize.width / PTM_RATIO, 0));
	groundBody->CreateFixture(&boxShapeDef);

	//왼쪽
	groundEdge.Set(b2Vec2(0, 0), b2Vec2(0, winSize.height / PTM_RATIO));
	groundBody->CreateFixture(&boxShapeDef);

	//위
	groundEdge.Set(b2Vec2(0, winSize.height / PTM_RATIO),
		b2Vec2(winSize.width / PTM_RATIO, winSize.height / PTM_RATIO));
	groundBody->CreateFixture(&boxShapeDef);

	//오른쪽
	groundEdge.Set(b2Vec2(winSize.width / PTM_RATIO, winSize.height / PTM_RATIO),
		b2Vec2(winSize.width / PTM_RATIO, 0));
	groundBody->CreateFixture(&boxShapeDef);


	Sprite * pSprite1 = Sprite::createWithTexture(texture, Rect(0, 0, 64, 64));
	pSprite1->setPosition(Vec2(winSize.width / 2, winSize.height / 2));
	this->addChild(pSprite1);

	b2BodyDef bodyDef1;
	bodyDef1.type = b2_staticBody;
	bodyDef1.position.Set(winSize.width / 2 / PTM_RATIO, winSize.height / 2 / PTM_RATIO);
	bodyDef1.userData = pSprite1;
	b2Body *body1 = _world->CreateBody(&bodyDef1);

	b2PolygonShape staticBox;
	staticBox.SetAsBox((pSprite1->getContentSize().width / 2) / PTM_RATIO,
		(pSprite1->getContentSize().height / 2) / PTM_RATIO);

	b2FixtureDef fixtureDef1;
	fixtureDef1.shape = &staticBox;
	fixtureDef1.density = 1.0f;

	body1->CreateFixture(&fixtureDef1);

	//

	Sprite * pSprite2 = Sprite::createWithTexture(texture, Rect(0, 0, 64, 32));
	pSprite2->setPosition(Vec2(0,100));
	this->addChild(pSprite2);

	bodyDef2.type = b2_kinematicBody;
	bodyDef2.position.Set(0,100.0f/PTM_RATIO);
	bodyDef2.linearVelocity = b2Vec2(1.0f, 0);
	bodyDef2.userData = pSprite2;
	b2Body *body2 = _world->CreateBody(&bodyDef2);

	b2PolygonShape kinematicBox;
	kinematicBox.SetAsBox((pSprite2->getContentSize().width/2)/PTM_RATIO,
		(pSprite2->getContentSize().height / 2) / PTM_RATIO);

	b2FixtureDef fixtureDef2;
	fixtureDef2.shape = &kinematicBox;
	fixtureDef2.density = 1.0f;

	body2->CreateFixture(&fixtureDef2);

	return true;
}

HelloWorld::~HelloWorld()
{
	delete _world;
	_world = NULL;
}


void HelloWorld::onDraw(const Mat4 &transform, uint32_t flags)
{
	Director* director = Director::getInstance();
	CCASSERT(nullptr != director, "Director is null when seting matrix stack");
	director->pushMatrix(MATRIX_STACK_TYPE::MATRIX_STACK_MODELVIEW);
	director->loadMatrix(MATRIX_STACK_TYPE::MATRIX_STACK_MODELVIEW, transform);

	GL::enableVertexAttribs(cocos2d::GL::VERTEX_ATTRIB_FLAG_POSITION);
	_world->DrawDebugData();
	CHECK_GL_ERROR_DEBUG();

	director->popMatrix(MATRIX_STACK_TYPE::MATRIX_STACK_MODELVIEW);
}
void HelloWorld::draw(Renderer *renderer, const Mat4 &transform, uint32_t flags)
{
	ccGLEnableVertexAttribs(kCCVertexAttrib_Position);
	kmGLPushMatrix();
	_world->DrawDebugData();
	kmGLPopMatrix();

	Scene::draw(renderer, transform, flags);

	_customCmd.init(_globalZOrder, transform, flags);
	_customCmd.func = CC_CALLBACK_0(HelloWorld::onDraw, this, transform, flags);
	renderer->addCommand(&_customCmd);

}




void HelloWorld::tick(float dt)
{
	//물리적 위치를 이용해 그래픽 위치를 갱신

	//권장값. 클수록 정확해지나 성능이 떨어짐
	int velocityIterations = 8; // 충돌을 반복적으로 계산
	int positionIterations = 3; // 조인트 분리와 겹침 현상을 줄이기 위한 반복 계산

								//Step :: 물리 세계 시뮬레이션
	_world->Step(dt, velocityIterations, positionIterations);

	//모든 물리객체는 링크드 리스트에 저장, 참조할 수 있게 구현됨
	//만들어진 객체만큼 루프를 돌리며 바디에 붙인 스프라이트의 제어를 한다
	for (b2Body *b = _world->GetBodyList(); b; b = b->GetNext())
	{
		if (b->GetUserData() != NULL)
		{
			Sprite * spriteData = (Sprite*)b->GetUserData();
			spriteData->setPosition(Vec2(b->GetPosition().x * PTM_RATIO,
				b->GetPosition().y * PTM_RATIO));
			spriteData->setRotation(-1 * CC_RADIANS_TO_DEGREES(b->GetAngle()));

		}
		if (b->GetType() == b2_kinematicBody)
		{

			b2Vec2 v = b->GetPosition();
			if (v.x*PTM_RATIO > winSize.width) {
				// 왼쪽으로 이동
				b->SetLinearVelocity(b2Vec2(-1.0f, 0));
			}
			else if (v.x < 0) {
				// 오른쪽으로 이동
				b->SetLinearVelocity(b2Vec2(1.0f, 0));
			}
		}
	}

}

void HelloWorld::onEnter()
{
	Scene::onEnter();

	auto listener = EventListenerTouchOneByOne::create();

	listener->setSwallowTouches(true);

	listener->onTouchBegan = CC_CALLBACK_2(HelloWorld::onTouchBegan, this);

	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);
}

void HelloWorld::onExit()
{
	_eventDispatcher->removeAllEventListeners();
	Scene::onExit();
}


bool HelloWorld::onTouchBegan(Touch *touch, Event *event)
{
	auto touchPoint = touch->getLocation();

	addNewSpriteAtPosition(touchPoint);
	return true;
}

void HelloWorld::addNewSpriteAtPosition(Vec2 location)
{
	int nNum = rand() % 3;

	/////// 바디데프 생성
	b2BodyDef bodyDef;
	bodyDef.type = b2_dynamicBody;
	bodyDef.position.Set(location.x / PTM_RATIO, location.y / PTM_RATIO);

	//bodyDef.userData = pSprite;
	bodyDef.userData = NULL;

	//월드에 바디데프로 바디 생성
	b2Body *body = _world->CreateBody(&bodyDef);

	if (nNum == 0)
	{
		b2PolygonShape dynamicBox;
		dynamicBox.SetAsBox(0.8f, 0.8f);

		b2FixtureDef fixtureDef;
		fixtureDef.shape = &dynamicBox;
		fixtureDef.density = 1.0f;
		fixtureDef.friction = 0.3f;
		fixtureDef.restitution = 0.0f;

		body->CreateFixture(&fixtureDef);
	}
	else if (nNum == 1)
	{
		b2PolygonShape dynamicBox;
		b2Vec2 tri[3];

		tri[0] = b2Vec2(-0.5, 0.0);
		tri[1] = b2Vec2(0.5, 0.0);
		tri[2] = b2Vec2(0.0, 1);

		dynamicBox.Set(tri, 3);

		b2FixtureDef fixtureDef;
		fixtureDef.shape = &dynamicBox;
		fixtureDef.density = 1.0f;
		fixtureDef.friction = 0.3f;
		fixtureDef.restitution = 1.0f;

		body->CreateFixture(&fixtureDef);
	}
	else
	{
		b2CircleShape dynamicCircle;
		dynamicCircle.m_radius = 1.0;

		b2FixtureDef fixtureDef;
		fixtureDef.shape = &dynamicCircle;
		fixtureDef.density = 1.0f;
		fixtureDef.friction = 0.3f;
		fixtureDef.restitution = 1.0f;

		body->CreateFixture(&fixtureDef);
	}

}