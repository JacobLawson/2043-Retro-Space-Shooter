#pragma once
#ifndef __ENEMY_FACTORY__
#define __ENEMY_FACTORY__

// Includes
#include <string>
#include <iostream>
#include <vector>

#include "olcPixelGameEngine.h"
#include "olcPGEX_Graphics2D.h"
#include "Vector2D.h"
#include "enemy.h"

//use enum to easily keep track of different Enemy types instead of raw integers
static enum EnemyType
{
	Parent,
	Upwards,
	Downwards,
	CrosserL,
	CrosserR,
	FighterD,
	FighterU,
	Missile,
	Scatter,
	PlayerPowerup,
	GroundTurret
};

//Forward Declaraton
class Scene;

//The Enemy Factory manages the Creation, Deletion and tracking of all bullet entities currently in the game
class EnemyFactory
{
public:
	//Destructor and constructor
	EnemyFactory();
	~EnemyFactory() {};

	//Functions
	void Update();
	void Draw();
	void CreateEnemy(EnemyType a_Instance, Scene* a_Scene, Vector2D a_Position);
	void DestroyEnemy(int a_InstanceID);
	int CountEnemies();

	//Getters and Setters
	int getEnemyCap() { return m_enemyCap; } //get the limit for enemys spawned
	int getEnemyCount() { return m_numberOfInstance; } //Find out how many enemies currently exist in game
	Enemy* getEnemies(int a_InstanceID) { return m_enemyInstances[a_InstanceID]; } //Get a specific instance of an enemy


private:
	//get pointer of self to give to pass into the spawned enemies
	EnemyFactory* factorypointer;
	//Vector allows all children of the Enemy class to be stored in one place as a refernece making it very easy to keep track of objects and call parent functions on them
	std::vector<Enemy*> m_enemyInstances;

	//class specific
	int m_enemyCap;
	int m_numberOfInstance;
};
#endif