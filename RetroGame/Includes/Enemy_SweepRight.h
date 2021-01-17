#pragma once
#ifndef __ENEMY_SWEEP_RIGHT_H__
#define __ENEMY_SWEEP_RIGHT_H__

//include Parent
#include "Enemy.h"

//Forward Declaration of scene
class Scene;

//Enemy Moves across screen from top Right to bottom Left
class EnemySweep_Right : public Enemy
{
public:
	//Constructor and Destructor
	EnemySweep_Right(Scene* a_scene, int m_instanceID, EnemyFactory* a_factory) : Enemy(a_scene, m_instanceID, a_factory) {};
	void Update();
};
#endif