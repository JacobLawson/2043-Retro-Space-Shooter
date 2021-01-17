#include "Includes/Ship.h"
// Includes
#include "Includes/EnemyFactory.h"
#include "BulletManager.h"
#include "Includes/Scene.h"
#include "Includes/Enemy.h"
#include "Bullet.h"


// Namespaces
using namespace olc;

Enemy::Enemy(Scene* a_Scene, int m_instanceID, EnemyFactory* a_factory)
{
	//Initialise Entity wide Variables
	CommonConstructor(a_Scene);
	//Initialise Enemy wide variables
	EnemyParent(p_scene, m_instanceID, a_factory);
}

void Enemy::EnemyParent(Scene* a_scene, int a_instanceID, EnemyFactory* a_factory)
{
	//Set enemy relevent pointers
	p_enemyFactory = a_factory;
	p_bulletManager = a_scene->GetBulletManager();
	p_Ship = a_scene->GetPlayerShip();
	//Set Sprite
	SetSprite(new Sprite("Resources/NormalEnemy.png"));
	//Set the instance ID as passed in on creation
	m_instanceID = a_instanceID;
}

void Enemy::Update()
{
	//Move The Enemy Downwards
	m_position.SetY(m_position.GetY() + (32.0f * p_scene->DeltaTime()));
	//Handle collisions with bullets
	Collision();
	//Handle Enemy Deletion when Dead
	Death();
}

void Enemy::Draw()
{
	m_transform = new GFX2D::Transform2D;
	m_transform->Translate(-m_spriteOriginX, -m_spriteOriginY);
	m_transform->Rotate(m_rotation);
	m_transform->Translate(m_position.GetX(), m_position.GetY());
	olc::GFX2D::DrawSprite(m_sprite, *m_transform);
}

void Enemy::Collision()
{
	int instancesToCheck = p_bulletManager->getBulletCount();

	for (int i = 0; i < instancesToCheck; i++)
	{
		if (p_bulletManager->getBullet(i) != nullptr)
		{
			Bullet* BulletToCheck = p_bulletManager->getBullet(i);
			if (BulletToCheck->GetBulletType() < 1)
			{
				collided = BoxCollision(m_position, BulletToCheck->GetPosition());
				if (collided == true)
				{
					p_bulletManager->DestroyBullet(i);
					m_health -= 1;
					i = instancesToCheck;
				}
			}		
		}
	}
}

void Enemy::Death()
{
	//Handle Enemy Deletion when Dead
	if (m_health <= 0)
	{
		p_scene->UpdateScore(m_scoreValue);
		p_enemyFactory->DestroyEnemy(m_instanceID);
	}
	else if (m_position.GetY() > 256 || m_position.GetY() < -16)
	{
		p_enemyFactory->DestroyEnemy(m_instanceID);
	}
}
