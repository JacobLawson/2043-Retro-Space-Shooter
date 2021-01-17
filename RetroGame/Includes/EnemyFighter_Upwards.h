#pragma once
#ifndef __ENEMYFIGHTER_UPWARDS_H__
#define __ENEMYFIGHTER_UPWARDS_H__

//include Parent
#include "Enemy.h"

//Forward Declaration
class Scene;
class BulletManager;

//Enemy moves Up from Bottom of screen firing a projectile every few moments
class EnemyFighter_Upwards : public Enemy
{
public:
	//Constructor and Destructor
	EnemyFighter_Upwards(Scene* a_scene, int m_instanceID, EnemyFactory* a_factory) : Enemy(a_scene, m_instanceID, a_factory) {};
	
	void Update();
private:
	//object specific variables
	float m_shootTimer;
	bool m_initialised;
};
#endif