#pragma once
#ifndef __PLAYER_BOMB_H__
#define __PLAYER_BOMB_H__

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

//The bomb is used to attack ground turrets and moves towards the reticles initial poistion
class PlayerBomb : public Bullet
{
public:
	//Destructor and constructor
	PlayerBomb(Scene* a_scene, int m_instanceID) : Bullet(a_scene, m_instanceID) {};
	~PlayerBomb();

	//Functions
	void Update();
	void Draw();
private:
	//Pointer to player Reticle
	Reticle* p_target;

	Vector2D m_targetPos;	  //player original position
	bool Initialised = false; //Allows constructor code to be ran once in update as children cannot use their own constructors
};

#endif // !__BULLET_H__
