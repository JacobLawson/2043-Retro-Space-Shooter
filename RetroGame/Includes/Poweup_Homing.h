#pragma once
#ifndef __PLAYER_HOMING_H__
#define __PLAYER_HOMING_H__

// Includes
#include "olcPixelGameEngine.h"
#include "olcPGEX_Graphics2D.h"
#include "Vector2D.h"
#include "Entity.h"
#include "Bullet.h"

//Forward Declarations
class Scene;
class Enemy;
class EnemyFactory;
class Reticle;

//Homes in on the first enemy in the enemy vector by getting their index
class Powerup_Homing : public Bullet
{
public:
	//Destructor and constructor
	Powerup_Homing(Scene* a_scene, int m_instanceID) : Bullet(a_scene, m_instanceID) {};
	~Powerup_Homing();

	//Functions
	void Update();
	void Draw();
	void Initialise();

private:
	//Pointer to Enemy
	Enemy* p_target;
	//pointer to enemy factory
	EnemyFactory* p_enemyFactory;

	Vector2D m_targetPos;	  //enmey position
	bool Initialised = false; //Allows constructor code to be ran once in update as children cannot use their own constructors
};

#endif // !__BULLET_H__
