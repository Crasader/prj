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

	/////////////////////////////

	winSize = Director::getInstance()->getWinSize();

	texture = Director::getInstance()->getTextureCache()->addImage("ball.png");

	if (this->createBox2dWorld(true))
	{
		srand((int)time(nullptr));
		SetBox2dWorld();
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
		flags += b2Draw::e_jointBit;
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

	return true;
}

void HelloWorld::SetBox2dWorld()
{
	bDrag = false;
	gbody = this->addNewSpriteAtPosition(Vec2(0, 0), Size(0, 0), b2_staticBody, NULL, 0);
	
	b2WheelJointDef jd1;
	b2WheelJointDef jd2;

	body0 = this->addNewSpriteAtPosition(Vec2(340, 70), Size(100, 40), b2_dynamicBody, nullptr, 0);
	b2Body* body1 = this->addNewSpriteAtPosition(Vec2(310, 50), Size(30, 30),
		b2_dynamicBody, nullptr, 1);
	b2Body* body2 = this->addNewSpriteAtPosition(Vec2(370, 50), Size(30, 30),
		b2_dynamicBody, nullptr, 1);

	b2Vec2 axis(0.0f, 1.0f);

	jd1.Initialize(body0, body1, body1->GetPosition(), axis);
	jd1.motorSpeed = 1;
	jd1.maxMotorTorque = 20.0f;
	jd1.enableMotor = true;
	jd1.frequencyHz = 4.0f;
	//jd1.dampingRatio = 0.7f;

	jd2.Initialize(body0, body2, body2->GetPosition(), axis);
	jd2.motorSpeed = 60.0f;
	jd2.maxMotorTorque = 20.0f;
	jd2.enableMotor = true;
	jd2.frequencyHz = 4.0f;
	//jd2.dampingRatio = 1.0f;

	m_spring1 = (b2WheelJoint*)_world->CreateJoint(&jd1);
	m_spring2 = (b2WheelJoint*)_world->CreateJoint(&jd2);
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

	int velocityIterations = 8;
	int positionIterations = 3;

	// Step : 물리 세계를 시뮬레이션한다.
	_world->Step(dt, velocityIterations, positionIterations);

	// 만들어진 객체 만큼 루프를 돌리면서 바디에 붙인 스프라이트를 여기서 제어한다.
	for (b2Body* b = _world->GetBodyList(); b; b = b->GetNext())
	{
		if (b->GetUserData() != nullptr) {
			Sprite* spriteData = (Sprite *)b->GetUserData();

			spriteData->setPosition(Vec2(b->GetPosition().x * PTM_RATIO,
				b->GetPosition().y * PTM_RATIO));
			spriteData->setRotation(-1 * CC_RADIANS_TO_DEGREES(b->GetAngle()));
		}
	}

	// 월드 안에서 좌우로 움직임을 제어한다. -- 추가 부분

	b2Vec2 p = body0->GetPosition();
	//log("%f..%f", p.x, p.y);
	if (p.x < 3)
	{
		m_spring1->SetMotorSpeed(-30.0f);
		m_spring2->SetMotorSpeed(-30.0f);
	}
	else if (p.x > 13) {
		m_spring1->SetMotorSpeed(30.0f);
		m_spring2->SetMotorSpeed(30.0f);
	}
}

void HelloWorld::onEnter()
{
	Scene::onEnter();

	auto listener = EventListenerTouchOneByOne::create();

	listener->setSwallowTouches(true);

	listener->onTouchBegan = CC_CALLBACK_2(HelloWorld::onTouchBegan, this);
	listener->onTouchMoved = CC_CALLBACK_2(HelloWorld::onTouchMoved, this);
	listener->onTouchEnded = CC_CALLBACK_2(HelloWorld::onTouchEnded, this);

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

	if (b2Body *b = this->getBodyAtTab(touchPoint))
	{
		dragBody = b;
		bDrag = true;

		b2MouseJointDef md;
		md.bodyA = gbody;
		md.bodyB = dragBody;
		md.target.Set(dragBody->GetPosition().x, dragBody->GetPosition().y);
		md.maxForce = 300.0 * dragBody->GetMass();

		mouseJoint = (b2MouseJoint *)_world->CreateJoint(&md);
	}

	return true;
}
void HelloWorld::onTouchMoved(Touch *touch, Event * event)
{
	Vec2 touchPoint = touch->getLocation();
	if (bDrag)
	{
		mouseJoint->SetTarget(b2Vec2(touchPoint.x / PTM_RATIO, touchPoint.y / PTM_RATIO));
	}
}

void HelloWorld::onTouchEnded(Touch *touch, Event *event)
{
	if (bDrag) 
	{
		_world->DestroyJoint(mouseJoint);
		mouseJoint = NULL;

		dragBody->SetAwake(true);
	}
	bDrag = false;
}

b2Body* HelloWorld::addNewSpriteAtPosition(Vec2 point,Size size,b2BodyType bodytype,
		const char* spriteName,int type)
{

	/////// 바디데프 생성
	b2BodyDef bodyDef;
	bodyDef.type = bodytype;
	bodyDef.position.Set(point.x / PTM_RATIO, point.y / PTM_RATIO);

	if (spriteName)
	{
		if (strcmp(spriteName, "test") == 0)
		{
			int idx = (CCRANDOM_0_1() > .5 ? 0 : 1);
			int idy = (CCRANDOM_0_1() > .5 ? 0 : 1);
			Sprite * sprite = Sprite::createWithTexture(texture, Rect(32 * idx, 32 * idy, 32, 32));
			sprite->setPosition(point);
			this->addChild(sprite);

			bodyDef.userData = sprite;
		}
		else
		{
			Sprite* sprite = Sprite::create(spriteName);
			sprite->setPosition(point);
			this ->addChild(sprite);
			bodyDef.userData = sprite;
		}
	}

	//bodyDef.userData = _world->CreateBody(&bodyDef);
	//bodyDef.userData = NULL;

	//월드에 바디데프로 바디 생성
	b2Body *body = _world->CreateBody(&bodyDef);

	//모양 고정
	b2FixtureDef fixtureDef;
	b2PolygonShape dynamicBox;
	b2CircleShape circle;

	if (type == 0)
	{
		dynamicBox.SetAsBox(size.width / 2 / PTM_RATIO, size.height / 2 / PTM_RATIO);
		fixtureDef.shape = &dynamicBox;
	}
	else
	{
		circle.m_radius = (size.width / 2) / PTM_RATIO;
		fixtureDef.shape = &circle;
	}

	fixtureDef.density = 1.0f; // 밀도
	fixtureDef.friction = 0.3f; // 0~1 마찰력
	fixtureDef.restitution = 0.5f; // 반발력 : 다른 물체에 닿았을 때 튕기는 정도

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

	return body;

}

b2Body* HelloWorld::getBodyAtTab(Vec2 p)
{
	b2Fixture *fix;
	for (b2Body *b = _world->GetBodyList(); b; b = b->GetNext())
	{
		if (b->GetUserData() != NULL)
		{
			if (b->GetType() == b2_staticBody) continue;
			fix = b->GetFixtureList();
			if (fix->TestPoint(b2Vec2(p.x / PTM_RATIO, p.y / PTM_RATIO)))
			{
				return b;
			}
		}
	}
	return NULL;
}


