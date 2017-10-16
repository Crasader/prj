#include "Bullet.h"
#include "HelloWorldScene.h"
#include "Singleton.h"

Bullet::Bullet(cocos2d::Scene *scene,cocos2d::Vec2 position, int type)
{
	_scene = scene;
	std::string _addr = SetType(type);
	this->setTexture(_addr);

	this->setAnchorPoint(cocos2d::Vec2(0.5, 0.5));
	this->setZOrder(11);
	this->setPosition(position);

	Singleton::getInstance()->bullets.pushBack(this);
	_scene->addChild(this);
}

void Bullet::Move()
{
	cocos2d::Vec2 move;
	_life--;

	if (getPosition().x + _Speed * MovePosition.x > 640 ||
		getPosition().x + _Speed * MovePosition.x < -320)
	{
		_life = 0;
	}
	if (getPosition().y + _Speed * MovePosition.y > 960 ||
		getPosition().y + _Speed * MovePosition.y < -160)
	{
		_life = 0;
	}

	setPosition(cocos2d::Vec2(
		getPosition().x + _Speed * MovePosition.x,
		getPosition().y + _Speed * MovePosition.y));

	if (_type == 0)
	{
		_Speed -= 0.3;
	}
}

std::string Bullet::SetType(int SetType)
{
	_type = SetType; 
	std::string _addr = "Images/1945/";

	// type : players

	if (_type == 0)
	{
		_isPlayers = 1;
		_life = 15;
		_Speed = 8;

		_Angle = 70 + rand() % 40;
		_addr += "missile";
	}

	// type : enemys

	if (_type == 1)
	{
		_isPlayers = 0;
		_life = -1;
		_Speed = 3;
		
		_Angle = 270;
		_addr += "enemyMissile_01";
		this->setScale(2);
	}

	MovePosition.x = sinf(CC_DEGREES_TO_RADIANS(90 - _Angle));
	MovePosition.y = cosf(CC_DEGREES_TO_RADIANS(90 - _Angle));

	_addr += ".png";
	return _addr;
}

void Bullet::Destroy()
{
	Singleton::getInstance()->bullets.eraseObject(this);
	_scene->removeChild(this);

	free(this);
}