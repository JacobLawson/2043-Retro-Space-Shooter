#pragma once
#ifndef __BULLET_ENEMY__
#define __BULLET_ENEMY__

//Includes
#include "olcPixelGameEngine.h"
#include "Includes/olcPGEX_Graphics2D.h"
#include "Vector2D.h"
#include "Entity.h"
#include "Bullet.h"

//Enemy bullet, can be fired in two directions
class BulletEnemy : public Bullet
{
public:
	//Constructor and Destructor
	BulletEnemy(Scene* a_scene, int m_instanceID) : Bullet(a_scene, m_instanceID) {};

	void Update();
};
#endif