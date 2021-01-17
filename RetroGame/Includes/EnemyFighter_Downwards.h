#pragma once
#ifndef __ENEMYFIGHTER_DOWNWARDS_H__
#define __ENEMYFIGHTER_DOWNWARDS_H__

//include Parent
#include "Enemy.h"

//Forward Declarations
class Scene;
class BulletManager;

//Enemy moves down from top of screen firing a projectile every few moments
class EnemyFighter_Downwards : public Enemy
{
public:
	//Constructor and Destructor
	EnemyFighter_Downwards(Scene* a_scene, int m_instanceID, EnemyFactory* a_factory) : Enemy(a_scene, m_instanceID, a_factory) {};

	void Update();
private:
	//object specific variables
	float m_shootTimer;
	bool m_initialised;
};
#endif