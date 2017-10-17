#ifndef __Enemy_h__
#define __Enemy_h__

#include "cocos2d.h"

class Enemy : public cocos2d::Sprite
{
public:
	int _RemoveBy = 0;

	cocos2d::Scene *_scene;
	float _MoveAngle, _SpriteAngle;
	float _Speed = 1;

	int _patternTimer = 60;
	int _currentTimer;
	int _phase = 0;

	int _RemainTime = 0;	//생성 후 지난시간
	bool _switch = false;

	int _life = 10;

	Enemy::Enemy(cocos2d::Scene *scene,cocos2d::Vec2 position, int type=0);

	void Move();
	std::string SetType(int SetType);
	void shot();
	void Destroy();

	cocos2d::Vec2 MovePosition;

	int _type;
};

#endif