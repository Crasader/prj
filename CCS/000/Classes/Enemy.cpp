#include "Enemy.h"
#include "Bullet.h"
#include "HelloWorldScene.h"
#include "Singleton.h"

#define winSize cocos2d::Director::getInstance()->getWinSize()

Enemy::Enemy(cocos2d::Scene *scene, cocos2d::Vec2 position, int type)
{
	_scene = scene;
	std::string _addr = SetType(type);
	this->setTexture(_addr);

	this->setAnchorPoint(cocos2d::Vec2(0.5, 0.5));
	this->setZOrder(10);
	this->setPosition(position);

	Singleton::getInstance()->enemys.pushBack(this);
	scene->addChild(this);
}

void Enemy::Move()
{
	cocos2d::Vec2 move;
	_RemainTime++;
	_currentTimer--;

	if(_type == 1)
	{
		if (getPosition().x < 100 && _switch == false)
		{	
			auto act = cocos2d::RotateTo::create(0.5, 90 - 270);
			this->runAction(act);
			_switch = true;
		}
		else if (getPosition().x < 50)
		{
			_phase = 1;
			_MoveAngle = 0;
			_SpriteAngle = 270;
			_currentTimer = 0;
		}
	}
	else if (_type == 2)
	{
		if (getPosition().x > winSize.width - 100 && _switch == false)
		{
			auto act = cocos2d::RotateTo::create(0.5, 90 - 270);
			this->runAction(act);
			_switch = true;
		}
		else if (getPosition().x > winSize.width - 50)
		{
			_phase = 1;
			_MoveAngle = 180;
			_SpriteAngle = 270;
			_currentTimer = 0;
		}
	}

	//°øÅë
	MovePosition.x = sinf(CC_DEGREES_TO_RADIANS(90 - _MoveAngle));
	MovePosition.y = cosf(CC_DEGREES_TO_RADIANS(90 - _MoveAngle));

	setPosition(cocos2d::Vec2(
		getPosition().x + _Speed * MovePosition.x,
		getPosition().y + _Speed * MovePosition.y));

	if (getPosition().x + _Speed * MovePosition.x > 330 ||
		getPosition().x + _Speed * MovePosition.x < -10)
	{
		_RemoveBy = 1;
		_life = -100;
	}
	if (getPosition().y + _Speed * MovePosition.y > 650 ||
		getPosition().y + _Speed * MovePosition.y < 150)
	{
		_RemoveBy = 1;
		_life = -100;
	}

	if (_currentTimer == 0)
	{
		shot();
	}


}

void Enemy::shot()
{

	if (_type >= 0)
	{
		if (_type == 0)
		{
			Bullet *newB = new Bullet(_scene, getPosition(), 1);
			_currentTimer = _patternTimer;
		}

		else if (_phase >= 1 && _phase < 3)
		{
			Bullet *newB = new Bullet(_scene, getPosition(), 1);
			_phase++;
			_currentTimer = 15;
		}
		else if (_phase == 3)
		{
			Bullet *newB = new Bullet(_scene, getPosition(), 1);
			_phase = 1;
			_currentTimer = _patternTimer;
		}
	}

}

std::string Enemy::SetType(int SetType)
{
	_type = SetType;
	std::string _addr = "Images/1945/";

	if (_type >= 0)
	{//ÀÜ¸÷ 1 °øÅë
		_patternTimer = 40;
		_addr += "enemy_01";
		_life = 10;

		if (_type == 0)
		{
			_MoveAngle = 270;
			_SpriteAngle = 270;
			_phase = 1;
			_patternTimer += 20;
			_Speed = 2;
		}
		else if (_type == 1)
		{
			_MoveAngle = 240;
			_SpriteAngle = 240;
			_Speed = 3;
		}
		else if (_type == 2)
		{
			_MoveAngle = 300;
			_SpriteAngle = 300;
			_Speed = 3;
		}
		else if (_type == 4)
		{
			this->setColor(cocos2d::Color3B(255, 0, 0));
			_MoveAngle = 300;
			_SpriteAngle = 300;
			_Speed = 3;
			_type = 2;
		}

		this->setRotation(90 - _SpriteAngle);
	}

	_currentTimer = _patternTimer;

	_addr += ".png";
	return _addr;
}

void Enemy::Destroy()
{
	Singleton::getInstance()->enemys.eraseObject(this);
	_scene->removeChild(this);

	free(this);
}