#pragma once
#ifndef __ENEMY_H__
#define __ENEMY_H__

// Includes
#include "olcPixelGameEngine.h"
#include "olcPGEX_Graphics2D.h"
#include "Vector2D.h"
#include "Entity.h"

//Forward Declarations of classes used
class Scene;
class EnemyFactory;
class BulletManager;
class Ship;

//Parent enemy class. retains basic functionality as a basic enemy that moves down the screen
class Enemy : public Entity
{
public:
	//constructor and Destructor
	Enemy(Scene* a_Scene, int m_instanceID, EnemyFactory* a_factory);

	//function for setting up enemy wide variabes in all children
	void EnemyParent(Scene* a_scene, int a_instanceID, EnemyFactory* a_factory);

	virtual void Update();
	void Draw();
	//what to do on collision
	virtual void Collision();
	//how to react to losing health
	void Death();

	//Getters and Setters
	int GetInstanceID() { return m_instanceID; }
	void SetInstanceID(int a_InstanceID) { m_instanceID = a_InstanceID; }

protected:
	//Pointers to objects used
	EnemyFactory* p_enemyFactory;
	BulletManager* p_bulletManager;
	Ship* p_Ship;

	//Animation frames
	olc::Sprite* m_currentFrame;

	//Enemy instance for Enemy Factory to keep track of
	int m_instanceID;


};
#endif