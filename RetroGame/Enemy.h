#pragma once
#ifndef __ENEMY_H__
#define __ENEMY_H__

// Includes
#include "olcPixelGameEngine.h"
#include "Includes/olcPGEX_Graphics2D.h"
#include "Vector2D.h"
#include "Includes/Entity.h"

class Scene;
class Ship;

class Enemy : public Entity
{
public:
	//Destructor and constructor
	Enemy(Scene* a_Scene, int m_instanceID);
	~Enemy() {};

	//Functions
	void EnemyParent();
	void Initialise();

	void Update();
	void Draw();
	void DespawnCheck();

	//Getters and Setters
	int GetInstanceID() { return m_instanceID; }
	void SetInstanceID(int a_InstanceID) { m_instanceID = a_InstanceID; }

protected:
	//Animation frames
	olc::Sprite* m_currentFrame;

	int m_instanceID;
	Ship* p_Ship;
};


#endif