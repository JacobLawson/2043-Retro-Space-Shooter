#pragma once
#ifndef __ENEMY_UPWARDS_H__
#define __ENEMY_UPWARDS_H__

//include Parent
#include "Enemy.h"

//Forward Declaration
class Scene;

//Enemy that simply moves up from bottom of screen, is spawned by the lower scroll pos
class EnemyUpwards : public Enemy
{
public:
	//Constructor and Destructor
	EnemyUpwards(Scene* a_scene, int m_instanceID, EnemyFactory* a_factory) : Enemy(a_scene, m_instanceID, a_factory) {};
	void Update();
};
#endif