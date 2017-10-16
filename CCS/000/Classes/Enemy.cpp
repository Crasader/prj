#include "Enemy.h"
#include "Bullet.h"
#include "HelloWorldScene.h"
#include "Singleton.h"

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

	if (getPosition().x + _Speed * MovePosition.x > 330 ||
		getPosition().x + _Speed * MovePosition.x < -10)
	{
		_life = -100;
	}
	if (getPosition().y + _Speed * MovePosition.y > 650 ||
		getPosition().y + _Speed * MovePosition.y < 150)
	{
		_life = -100;
	}

	setPosition(cocos2d::Vec2(
		getPosition().x + _Speed * MovePosition.x,
		getPosition().y + _Speed * MovePosition.y));

	if (_life == 0)
	{
		this->setVisible(false);
	}

	_currentTimer--;
	if (_currentTimer == 0)
	{
		shot();
	}
}

void Enemy::shot()
{
	Bullet *newB = new Bullet(_scene, getPosition(), 1);

	if (_type == 0)
	{
		if (_phase < 2)
		{
			_patternTimer = 10;
			_phase++;
		}
		else
		{
			_patternTimer = 280;
			_phase = 0;
		}
	}

	_currentTimer = _patternTimer;
}

std::string Enemy::SetType(int SetType)
{
	_type = SetType;
	std::string _addr = "Images/1945/";

	if (_type == 0)
	{
		_patternTimer = 40;
		_addr += "enemy_01";
		_Angle = 270;
		_life = 10;

		this->setRotation(-180);
	}

	_currentTimer = _patternTimer;

	MovePosition.x = sinf(CC_DEGREES_TO_RADIANS(90 - _Angle));
	MovePosition.y = cosf(CC_DEGREES_TO_RADIANS(90 - _Angle));

	_addr += ".png";
	return _addr;
}

void Enemy::Destroy()
{
	Singleton::getInstance()->enemys.eraseObject(this);
	_scene->removeChild(this);

	free(this);
}