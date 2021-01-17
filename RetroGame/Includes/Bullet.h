#pragma once
#ifndef __BULLET_H__
#define __BULLET_H__

// Includes
#include "olcPixelGameEngine.h"
#include "olcPGEX_Graphics2D.h"
#include "Vector2D.h"
#include "Entity.h"

//Forward declarations to reference classes used
class Scene;
class Enemy;
class EnemyFactory;

//Bullet is a parent for all bullets but retains functionality by default as the main player weapon
//it's functions can be overided if necessary to fullfil different bullet types as they are virtual
class Bullet : public Entity
{
public:
	//Destructor and constructor
	Bullet(Scene* a_Scene, int m_instanceID);
	~Bullet();

	//Functions
	virtual void Update();
	virtual void Draw();


	//Getters and Setters
	void SetInstanceID(int a_InstanceID) { m_instanceID = a_InstanceID; }
	int GetBulletType() { return m_BulletType; }

	//This is only relevent to enemy bullets which can be fired both upwards and downwards
	void SetDirection(bool a_moveUpwards) { m_moveUpwards = a_moveUpwards; }

protected:
	//pointers
	EnemyFactory* p_enemyFactory;

	//Object Specific
	int m_instanceID;	//the instance ID is what ID the bullet manager gives the object to keep track of it for collisions and other checks
	int m_BulletType;	//important so that bullets know what they can and can't kill 0 = kills enemies but not ground turrets, 1 = kills ground enemies, 2 = kills player not enemies
	bool m_moveUpwards;	//decides the direction of the basic enemy bullet (see EnemyBullet.h for more)
	
};
#endif // !__BULLET_H__