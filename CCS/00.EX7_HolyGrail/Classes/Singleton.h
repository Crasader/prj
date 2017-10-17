#ifndef __SINGLETON_H__
#define __SINGLETON_H__

#include "cocos2d.h"
#include "Monster.h"
#include "Item.h"
#include <iostream>

class Singleton
{
public:
	static Singleton* getInstance();
	cocos2d::Vector<Monster*> Monsters;
	cocos2d::Vector<Item*> Items;

private:
	Singleton() {};
	static Singleton* m_pInstance;
};

#endif