#ifndef __SINGLETON_H__
#define __SINGLETON_H__

#include "cocos2d.h"
#include "Bullet.h"
#include "Enemy.h"
#include <iostream>

class Singleton
{
public:
	static Singleton* getInstance();
	cocos2d::Vector<Bullet*> bullets;
	cocos2d::Vector<Enemy*> enemys;

private:
	Singleton() {};
	static Singleton* m_pInstance;
};

#endif