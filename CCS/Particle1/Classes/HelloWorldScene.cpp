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

	auto wlayer = LayerColor::create(Color4B(255, 255, 255, 0));
	this->addChild(wlayer);

	/////////////////////////////

	this->doParticles();

    return true;
}

void HelloWorld::doParticles()
{
	//ParticleSystem * particleTest = ParticleFire::create();
	//ParticleSystem * particleTest = ParticleGalaxy::create();
	//ParticleSystem * particleTest = ParticleSmoke::create();
	//ParticleSystem * particleTest = ParticleFlower::create();
	//ParticleSystem * particleTest = ParticleFireworks::create();
	ParticleSystem * particleTest = ParticleExplosion::create();

	auto texture = Director::getInstance()->getTextureCache()->addImage("Images/snow.png");
	particleTest->setTexture(texture);

	if (particleTest != NULL)
	{
		particleTest->setScale(1.0);
		particleTest->setPosition(Vec2(240, 160));
		this->addChild(particleTest);
	}
}