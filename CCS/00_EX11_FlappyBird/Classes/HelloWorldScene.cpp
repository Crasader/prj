#include "HelloWorldScene.h"
//#include "SimpleAudioEngine.h"

USING_NS_CC;
#define TouchVelocity 30
#define GroundSpeed 150

float BlockSpeed = 5;
int Random = 100;
int Score = 0;

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

	srand((int)time(nullptr));
	winSize = Director::getInstance()->getWinSize();

	auto backgroundSpr = Sprite::create("Images/bg.png");
	backgroundSpr->setPosition(Vec2(0,0));
	backgroundSpr->setAnchorPoint(Vec2(0, 0));
	this->addChild(backgroundSpr,0);

	//auto backgroundSpr2 = Sprite::create("Images/ground.png");
	//backgroundSpr2->setPosition(Vec2(0, -200));
	//backgroundSpr2->setAnchorPoint(Vec2(0, 0));
	//this->addChild(backgroundSpr2,3);

	Dummy = Sprite::create("Images/bird2.png");
	Dummy->setPosition(winSize.width / 2, winSize.height / 2);

	auto Act = RepeatForever::create(Sequence::create
	(MoveBy::create(0.5, Vec2(0, 30)), MoveBy::create(0.5, Vec2(0, -30)), NULL));
	Dummy->runAction(Act);
	this->addChild(Dummy,5);

	char hs[100];
	sprintf(hs, "%d", Score);
	TTFConfig ScoreTextFontConfig("fonts/Marker Felt.ttf", 60);
	ScoreText = Label::createWithTTF(ScoreTextFontConfig, hs);
	ScoreText->setPosition(Vec2(winSize.width/2, winSize.height/2 + 500));
	this->addChild(ScoreText,10);

	this->createBox2dWorld(true);
	GroundControl();

    return true;
}

void HelloWorld::GroundControl()
{
	GroundCallBack();
	auto Clouds = Sprite::create("Images/ground.png");
	Clouds->setPosition(Vec2(0, -200));
	Clouds->setAnchorPoint(Vec2(0, 0));
	Clouds->setZOrder(3);
	this->addChild(Clouds);

	auto CloudSeq = Sequence::create(
		MoveBy::create(640 / GroundSpeed, Vec2(-640, 0)),
		CallFunc::create(CC_CALLBACK_0(HelloWorld::GroundCallBack, this)),
		RemoveSelf::create(),
		NULL
	);
	Clouds->runAction(CloudSeq);
}
void HelloWorld::GroundCallBack()
{
	auto Clouds2 = Sprite::create("Images/ground.png");
	Clouds2->setPosition(Vec2(640, -200));
	Clouds2->setAnchorPoint(Vec2(0, 0));
	Clouds2->setZOrder(3);
	this->addChild(Clouds2);

	auto CloudSeq2 = Sequence::create(
		MoveBy::create(1280 / GroundSpeed, Vec2(-1280, 0)),
		Place::create(Vec2(640, -200)),
		NULL
	);
	auto CloudRep2 = RepeatForever::create(CloudSeq2);

	Clouds2->runAction(CloudRep2);
}

void HelloWorld::onEnter()
{
	Scene::onEnter();

	// 싱글터치모드로 터치리스너 등록
	auto listener = EventListenerTouchOneByOne::create();
	listener->setSwallowTouches(true);
	listener->onTouchBegan = CC_CALLBACK_2(HelloWorld::onTouchBegan, this);

	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);
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
void HelloWorld::onExit()
{
	_eventDispatcher->removeAllEventListeners();
	Scene::onExit();
}

bool HelloWorld::createBox2dWorld(bool debug)
{
	b2Vec2 gravity = b2Vec2(0.0f, -40); // 중력의 방향을 결정한다.
	_world = new b2World(gravity);

	_world->SetAllowSleeping(true); // 휴식중 멈출지 여부. 켜라
	_world->SetContinuousPhysics(true); //지속적 물리작용 여부
	
	if (debug)
	{
		m_debugDraw = new GLESDebugDraw(PTM_RATIO);
		_world->SetDebugDraw(m_debugDraw);

		uint32 flags = 0;
		flags += b2Draw::e_shapeBit;

		m_debugDraw->SetFlags(flags);
	}

	_world->SetContactListener((b2ContactListener *)this);


	//가장자리 생성

	b2BodyDef groundBodyDef;
	groundBodyDef.position.Set(0, 0);
	b2Body *groundBody = _world->CreateBody(&groundBodyDef);


	//경계면을 그릴 수 있는 객체 생성
	b2EdgeShape groundEdge;
	b2FixtureDef boxShapeDef;
	boxShapeDef.shape = &groundEdge;

	//아래
	groundEdge.Set(b2Vec2(0, 100 / PTM_RATIO), b2Vec2(winSize.width / PTM_RATIO, 100 / PTM_RATIO));
	groundBody->CreateFixture(&boxShapeDef);

	//위
	groundEdge.Set(b2Vec2(0, winSize.height * 1.5 / PTM_RATIO),
		b2Vec2(winSize.width / PTM_RATIO, winSize.height * 1.5 / PTM_RATIO));
	groundBody->CreateFixture(&boxShapeDef);

	return true;
}

void HelloWorld::tick(float dt)
{
	int velocityIterations = 8;
	int positionIterations = 3;

	// Step : 물리 세계를 시뮬레이션한다.
	_world->Step(dt, velocityIterations, positionIterations);

	for (int i = delVec.size() - 1; i >= 0; i--)
	{
		Sprite *spr = (Sprite *)delVec.at(i)->GetUserData();
		delVec.at(i)->SetUserData(NULL);
		this->removeChild(spr);
		_world->DestroyBody(delVec.at(i));
	}
	delVec.clear();


	// 만들어진 객체 만큼 루프를 돌리면서 바디에 붙인 스프라이트를 여기서 제어한다.
	for (b2Body* b = _world->GetBodyList(); b; b = b->GetNext())
	{
		if (b->GetUserData() != nullptr) {
			Sprite* spriteData = (Sprite *)b->GetUserData();

			spriteData->setPosition(Vec2(b->GetPosition().x * PTM_RATIO,
				b->GetPosition().y * PTM_RATIO));
		}
	}

	if (IsTouched)
	{
		IsTouched = false;

		Sprite *pSprite = (Sprite*)Player->GetUserData();
		pSprite->setRotation(-30);
		pSprite->stopAllActions();

		auto Act = Sequence::create(DelayTime::create(0.5),RotateTo::create(0.2, 90),NULL);
		pSprite->runAction(Act);
		
		Player->SetLinearVelocity(b2Vec2(0, TouchVelocity));
	}

	if (Player->GetLinearVelocity().y > 0)
	{
		Player->ApplyLinearImpulse(b2Vec2(0, -3),
			Player->GetWorldCenter(),
			true);

		if (Player->GetLinearVelocity().y < 0)
		{
			Player->SetLinearVelocity(b2Vec2(0, 0));
		}
	}
}

bool HelloWorld::onTouchBegan(Touch* touch, Event* event)
{
	if (!IsStarted)
	{
		IsStarted = true;
		addNewSpriteAtPosition(Vec2(Dummy->getPosition()), 0);
		this->removeChild(Dummy);
		this->schedule(schedule_selector(HelloWorld::tick));
		this->schedule(schedule_selector(HelloWorld::Blocks),2.5);
	}
	IsTouched = true;

	return true;
}

void HelloWorld::Blocks(float f)
{
	Random = rand()%740 - 250;
	log("%d", Random);

	addNewSpriteAtPosition(Vec2(winSize.width + 150, Random), 1);
	addNewSpriteAtPosition(Vec2(winSize.width + 150, winSize.height + Random - 150), 2);
	addNewSpriteAtPosition(Vec2(winSize.width + 150, winSize.height + Random + -750), 3);
}

void HelloWorld::addNewSpriteAtPosition(Vec2 location,int type)
{
	if (type == 0)
	{
		b2BodyDef bodyDef;
		bodyDef.type = b2_dynamicBody;
		bodyDef.position.Set(location.x / PTM_RATIO, location.y / PTM_RATIO);

		Sprite* sprite = Sprite::create("Images/bird2.png");
		sprite->setPosition(location);
		this->addChild(sprite,5);
		bodyDef.userData = sprite;

		Player = _world->CreateBody(&bodyDef);

		b2CircleShape circle;
		circle.m_radius = 0.9f;

		b2FixtureDef fixtureDef;
		fixtureDef.shape = &circle;
		fixtureDef.density = 1.0f;
		fixtureDef.friction = 0;
		fixtureDef.restitution = 0;

		Player->CreateFixture(&fixtureDef);
	}
	else if(type == 1)
	{
		// 바디데프 만들고 속성들을 지정한다.
		b2BodyDef bodyDef2;
		bodyDef2.type = b2_kinematicBody;
		bodyDef2.position.Set(location.x / PTM_RATIO, location.y / PTM_RATIO);
		bodyDef2.linearVelocity = b2Vec2(-BlockSpeed, 0);

		Sprite* sprite = Sprite::create("Images/holdback1.png");
		sprite->setPosition(location);
		this->addChild(sprite,2);
		sprite->setTag(100);
		
		bodyDef2.userData = sprite;

		b2Body* body2 = _world->CreateBody(&bodyDef2);

		// 바디에 적용할 물리 속성용 바디의 모양을 만든다.
		b2PolygonShape kinematicBox;
		// 바디의 크기 지정 - 상자의 크기에서 가운데 위치를 지정한다.
		kinematicBox.SetAsBox(130 / 2.0 / (PTM_RATIO * 1.0),
			800 / 2.0 / (PTM_RATIO * 1.0));

		b2FixtureDef fixtureDef2;
		fixtureDef2.shape = &kinematicBox;
		fixtureDef2.density = 1.0f;

		body2->CreateFixture(&fixtureDef2);
	}
	else if (type == 2)
	{
		// 바디데프 만들고 속성들을 지정한다.
		b2BodyDef bodyDef2;
		bodyDef2.type = b2_kinematicBody;
		bodyDef2.position.Set(location.x / PTM_RATIO, location.y / PTM_RATIO);
		bodyDef2.linearVelocity = b2Vec2(-BlockSpeed, 0);

		Sprite* sprite = Sprite::create("Images/holdback2.png");
		sprite->setPosition(location);
		this->addChild(sprite,2);
		bodyDef2.userData = sprite;
		sprite->setTag(101);

		b2Body* body2 = _world->CreateBody(&bodyDef2);

		// 바디에 적용할 물리 속성용 바디의 모양을 만든다.
		b2PolygonShape kinematicBox;
		// 바디의 크기 지정 - 상자의 크기에서 가운데 위치를 지정한다.
		kinematicBox.SetAsBox(130 / 2.0 / (PTM_RATIO * 1.0),
			830 / 2.0 / (PTM_RATIO * 1.0));

		b2FixtureDef fixtureDef2;
		fixtureDef2.shape = &kinematicBox;
		fixtureDef2.density = 1.0f;

		body2->CreateFixture(&fixtureDef2);
	}

	else if (type == 3)
	{
		// 바디데프 만들고 속성들을 지정한다.
		b2BodyDef bodyDef2;
		bodyDef2.type = b2_kinematicBody;
		bodyDef2.position.Set(location.x / PTM_RATIO, location.y / PTM_RATIO);
		bodyDef2.linearVelocity = b2Vec2(-BlockSpeed, 0);

		Sprite* sprite = Sprite::create("Images/Inv.png");
		sprite->setPosition(location);
		this->addChild(sprite);
		bodyDef2.userData = sprite;
		sprite->setTag(103);

		b2Body* body2 = _world->CreateBody(&bodyDef2);

		// 바디에 적용할 물리 속성용 바디의 모양을 만든다.
		b2PolygonShape kinematicBox;
		// 바디의 크기 지정 - 상자의 크기에서 가운데 위치를 지정한다.
		kinematicBox.SetAsBox(10 / 2.0 / (PTM_RATIO * 1.0),
			400 / 2.0 / (PTM_RATIO * 1.0));

		b2FixtureDef fixtureDef2;
		fixtureDef2.shape = &kinematicBox;
		fixtureDef2.density = 1.0f;

		body2->CreateFixture(&fixtureDef2);
	}
}

void HelloWorld::BeginContact(b2Contact* contact)
{
	log("Contact : Begin");
}

void HelloWorld::PreSolve(b2Contact* contact, const b2Manifold* oldManifold)
{
	log("Contact : PreSolve");

	bool check = false;

	b2Fixture* fixA = contact->GetFixtureA();

	b2Body* bodyA = fixA->GetBody();

	Sprite *temp = (Sprite*)bodyA->GetUserData();
	if (temp && temp->getTag() == 103)
	{
		check = true;
		delVec.push_back(bodyA);
	}

	if (check)
	{
		contact->SetEnabled(false);

		Score++;
		this->removeChild(ScoreText);

		char hs[100];
		sprintf(hs, "%d", Score);
		TTFConfig ScoreTextFontConfig("fonts/Marker Felt.ttf", 60);
		ScoreText = Label::createWithTTF(ScoreTextFontConfig, hs);
		ScoreText->setPosition(Vec2(winSize.width / 2, winSize.height / 2 + 500));
		this->addChild(ScoreText, 10);
	}
	else
	{
		this->unschedule(schedule_selector(HelloWorld::tick));
		this->unschedule(schedule_selector(HelloWorld::Blocks));

		Sprite * pSprite = (Sprite *)Player->GetUserData();
		auto act = MoveTo::create(pSprite->getPosition().y / 400, Vec2(pSprite->getPosition().x, 100));
		pSprite->runAction(act);

		auto backgroundSpr2 = Sprite::create("Images/ground.png");
		backgroundSpr2->setPosition(Vec2(0, -200));
		backgroundSpr2->setAnchorPoint(Vec2(0, 0));
		this->addChild(backgroundSpr2,4);
	}
}

void HelloWorld::EndContact(b2Contact* contact)
{
	log("Contact : End");

}