#pragma once
#ifndef __POWERUP_H__
#define __POWERUP_H__

//include Parent
#include "Enemy.h"

//Forward Declaration
class Scene;

//This enemy upon destruction grants the player a homing attack
class Powerup : public Enemy
{
public:
	//Constructor and Destructor
	Powerup(Scene* a_scene, int m_instanceID, EnemyFactory* a_factory) : Enemy(a_scene, m_instanceID, a_factory) {};

	//overided enemy functions
	void Update();
	void Collision();	//overided to give player power up
};
#endif