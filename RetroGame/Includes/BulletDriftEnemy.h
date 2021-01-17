#pragma once
#ifndef __BULLET_DRIFT_ENEMY__
#define __BULLET_DRIFT_ENEMY__

//includes
#include "olcPixelGameEngine.h"
#include "Includes/olcPGEX_Graphics2D.h"
#include "Vector2D.h"
#include "Entity.h"
#include "Bullet.h"

//Forward declarations to reference classes used
class Ship;

//This Bullet type moves towards the position the player WAS at when the bullet was spawned. it does not home in on the player
class BulletEnemyDrift : public Bullet
{
public:
	//Constructor and Destructor
	BulletEnemyDrift(Scene* a_scene, int m_instanceID) : Bullet(a_scene, m_instanceID) {};

	//Overided Parent Functions
	void Update();
	void Draw();
private:
	//Pointer to player Ship
	Ship* p_target;

	//Object Specific
	Vector2D m_targetPos;		//player original position
	bool Initialised = false;	//Allows constructor code to be ran once in update as children cannot use their own constructors
};

#endif