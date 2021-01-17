#pragma once
#ifndef __TURRET_H__
#define __TURRET_H__

//include Parent
#include "Enemy.h"

//Forward Declarations
class Scene;
class Ship;
class BulletManager;

//Turrets are the only included ground enemy and can only be killed with bombs fired with the shift key
class Turret : public Enemy
{
public:
	//Constructor and Destructor
	Turret(Scene* a_scene, int m_instanceID, EnemyFactory* a_factory) : Enemy(a_scene, m_instanceID, a_factory) {};

	//functions
	void Update();
	void Collision(); //overided so that the enemy can only collide with bombs (bullet type 1)
private:
	//pointers
	Ship* p_target; //poiter to player so it may rotate towards them
	BulletManager* p_bulletManager;
	//object specific
	float m_shootTimer;
	bool m_initialised;

};
#endif