#pragma once
#ifndef __ENEMY_LARGE_H__
#define __ENEMY_LARGE_H__

//include Parent
#include "Enemy.h"

//Forward Declarations
class Scene;
class Ship;

//A similar pattern to Capcom's 1943's Large Planes
//This Enemy moves towards the player and when it has reached it's original position it moves back off the screen
class Enemy_Large : public Enemy
{
public:
	//Constructor and Destructor
	Enemy_Large(Scene* a_scene, int m_instanceID, EnemyFactory* a_factory) : Enemy(a_scene, m_instanceID, a_factory) {};

	void Update();
private:
	//store initial player position
	Vector2D m_targetPos;

	//object specific variables
	bool Initialised = false;
	bool m_TurnPos;
};
#endif