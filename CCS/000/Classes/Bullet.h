#ifndef __Bullet_h__
#define __Bullet_h__

#include "cocos2d.h"

class Bullet : public cocos2d::Sprite
{
public:
	float _Speed = 1;
	bool _isPlayers = 0;
	int _life = -1;
	cocos2d::Scene *_scene;

	Bullet::Bullet(){};
	Bullet::Bullet(cocos2d::Scene *scene,cocos2d::Vec2 position, int type);
	
	void Move();
	void Destroy();
	std::string SetType(int SetType);

protected:
	cocos2d::Vec2 MovePosition;

	int _type;
	float _Angle;
};

#endif