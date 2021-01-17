#pragma once
#ifndef __BULLET_MANAGER__
#define __BULLET_MANAGER__

#include "olcPixelGameEngine.h"
#include "Includes/olcPGEX_Graphics2D.h"
#include "Vector2D.h"

//Forward Declaraton
class Scene;
class Bullet;
class PlayerBomb;

//use enum to easily keep track of different bullet types instead of raw integers
static enum BulletType
{
	PlayerBullet,
	EnemyBulletDown,
	EnemyBulletUp,
	Bomb,
	PlayerHoming,
	EnemyDrift
};

//The Bullet Manager manages the Creation, Deletion and tracking of all bullet entities currently in the game
class BulletManager
{
public:
	//Destructor and constructor
	BulletManager();
	~BulletManager() {};

	//Functions
	void Update();
	void Draw();
	void CreateBullet(BulletType a_Instance, Scene* a_Scene, Vector2D a_Position);
	void DestroyBullet(int a_InstanceID);
	int CountBullets();

	//Getters and Setters
	int getBulletCap() { return m_bulletCap; }	//get the limit for enemy projectiles
	int getBulletCount() { return m_numberOfInstance; }	//Find out how many bullets currently exist in game
	Bullet* getBullet(int a_InstanceID) { return m_bulletInstances[a_InstanceID]; }	//Get a specific instance of a bullet

private:
	//Vector allows all children of the Bullet class to be stored in one place as a refernece making it very easy to keep track of objects and call parent functions on them
	std::vector<Bullet*> m_bulletInstances;	

	//class specific
	int m_bulletCap;	
	int m_numberOfInstance;
};
#endif // !__BULLET_MANAGER__