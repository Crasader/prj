#include "HelloWorldScene.h"
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

	auto wlayer = LayerColor::create(Color4B(255, 255, 255, 255));
	this->addChild(wlayer);

	/////////////////////////////

	winSize = Director::getInstance()->getWinSize();

	texture = Director::getInstance()->getTextureCache()->addImage("ball.png");

	//월드 생성 시작
	b2Vec2 gravity = b2Vec2(0.0f, -30.0f); // 중력의 방향을 결정한다.
	_world = new b2World(gravity);

	_world->SetAllowSleeping(true); // 휴식중 멈출지 여부. 켜라
	_world->SetContinuousPhysics(true); //지속적 물리작용 여부

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

	this->schedule(schedule_selector(HelloWorld::tick));

    return true;
}

HelloWorld::~HelloWorld()
{
	delete _world;
	_world = NULL;
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
	}
}

bool HelloWorld::onTouchBegan(Touch *touch, Event *event)
{
	auto touchPoint = touch->getLocation();

	addNewSpriteAtPosition(touchPoint);
	return true;
}

void HelloWorld::addNewSpriteAtPosition(Vec2 location)
{
	Sprite *pSprite = Sprite::createWithTexture(texture, Rect(0, 0, 90, 90));
	pSprite->setScale(0.4f);
	pSprite->setPosition(location);
	this->addChild(pSprite);

	/////// 바디데프 생성
	b2BodyDef bodyDef;
	bodyDef.type = b2_dynamicBody;
	bodyDef.position.Set(location.x / PTM_RATIO, location.y / PTM_RATIO);

	bodyDef.userData = pSprite;

	//월드에 바디데프로 바디 생성
	b2Body *body = _world->CreateBody(&bodyDef);

	//바디 모양 형성 - 원형
	b2CircleShape circle;
	circle.m_radius = 0.55f;

	//모양 고정
	b2FixtureDef fixtureDef;

	fixtureDef.shape = &circle; // 형태
	fixtureDef.density = 1.0f; // 밀도
	fixtureDef.friction = 0.2f; // 0~1 마찰력
	fixtureDef.restitution = 0.7f; // 반발력 : 다른 물체에 닿았을 때 튕기는 정도

	body->CreateFixture(&fixtureDef);


	////바디 모양 형성 - 박스
	//b2BodyDef bodyDef;
	//bodyDef.type = b2_dynamicBody;
	//bodyDef.position.Set(location.x / PTM_RATIO, location.y / PTM_RATIO);
	//b2Body *body = _world->CreateBody(&bodyDef);

	//b2PolygonShape dynamicBox;
	//dynamicBox.SetAsBox(.5f, .5f);

	//b2FixtureDef fixtureDef;
	//fixtureDef.shape = &dynamicBox;
	//fixtureDef.density = 1.0f;
	//fixtureDef.friction = 0.3f;
	//fixtureDef.restitution = 1.f;
	//body->CreateFixture(&fixtureDef);

	////바디 모양 형성 - 다각형
	//b2BodyDef bodyDef;
	//bodyDef.type = b2_dynamicBody;
	//bodyDef.position.Set(location.x / PTM_RATIO, location.y / PTM_RATIO);
	//b2Body *body = _world->CreateBody(&bodyDef);

	//b2PolygonShape dynamicBox;
	//b2Vec2 tri[3];	// 점 수

	//tri[0].x = -.5; // 점 설정
	//tri[0].y = 0.0;

	//tri[1].x = .5;
	//tri[1].y = 0.0;

	//tri[2].x = 0;
	//tri[2].y = 1.0;

	//dynamicBox.Set(tri, 3);

	//b2FixtureDef fixtureDef;
	//fixtureDef.shape = &dynamicBox;
	//fixtureDef.density = 1.0f;
	//fixtureDef.friction = 0.3f;
	//fixtureDef.restitution = 1.f;
	//body->CreateFixture(&fixtureDef);



}