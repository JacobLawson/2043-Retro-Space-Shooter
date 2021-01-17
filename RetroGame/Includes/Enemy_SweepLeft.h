#pragma once
#ifndef __ENEMY_SWEEP_LEFT_H__
#define __ENEMY_SWEEP_LEFT_H__

//include Parent
#include "Enemy.h"

//Forward Declaration of scene
class Scene;

//Enemy Moves across screen from top left to bottom right
class EnemySweep_Left : public Enemy
{
public:
	//Constructor and Destructor
	EnemySweep_Left(Scene* a_scene, int m_instanceID, EnemyFactory* a_factory) : Enemy(a_scene, m_instanceID, a_factory) {};
	void Update();
};
#endif