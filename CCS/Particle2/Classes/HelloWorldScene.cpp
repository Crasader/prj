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

	showParticle();

    return true;
}

void HelloWorld::showParticle()
{
	//ParticleSystem *particle = ParticleSystemQuad::create("Particles/Comet.plist");
	//ParticleSystem *particle = ParticleSystemQuad::create("Particles/BurstPipe.plist");
	//ParticleSystem *particle = ParticleSystemQuad::create("Particles/BoilingFoam.plist");
	//ParticleSystem *particle = ParticleSystemQuad::create("Particles/SpinningPeas.plist");
	//ParticleSystem *particle = ParticleSystemQuad::create("Particles/Upsidedown.plist");
	//ParticleSystem *particle = ParticleSystemQuad::create("Particles/TestPremultipliedAlpha.plist");
	//ParticleSystem *particle = ParticleSystemQuad::create("Particles/SpookyPeas.plist");
	//ParticleSystem *particle = ParticleSystemQuad::create("Particles/Spiral.plist");
	//ParticleSystem *particle = ParticleSystemQuad::create("Particles/Phoenix.plist");
	//ParticleSystem *particle = ParticleSystemQuad::create("Particles/LavaFlow.plist");
	//ParticleSystem *particle = ParticleSystemQuad::create("Particles/Flower.plist");
	particle->setPosition(Vec2(170,140));
	particle->setDuration(2.0f);
	particle->setAutoRemoveOnFinish(true);

	this->addChild(particle);

}