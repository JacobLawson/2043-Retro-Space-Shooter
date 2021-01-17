#pragma once
#ifndef __ENEMY_MISSILE_H__
#define __ENEMY_MISSILE_H__

//include Parent
#include "Enemy.h"

//forward Declaration
class Scene;

//This Enemy Follows the player constantly until killded
class Enemy_Missile : public Enemy
{
public:
	//Constructor and Destructor
	Enemy_Missile(Scene* a_scene, int m_instanceID, EnemyFactory* a_factory) : Enemy(a_scene, m_instanceID, a_factory) {};
	void Update();
private:
	//Allows constructor code to be ran once in update as children cannot use their own constructors
	bool m_initialsed;
};
#endif