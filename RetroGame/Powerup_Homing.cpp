#include "Includes/Poweup_Homing.h"
#include "Enemy.h"
#include "Includes/EnemyFactory.h"
#include "BulletManager.h"
#include "Scene.h"
#include "Reticle.h"

void Powerup_Homing::Update()
{
	if (Initialised == false)
	{
		//Set the sprite
		SetSprite(new olc::Sprite("Resources/Homing.png"), true);

		//Get the first target available if one exists
		p_enemyFactory = p_scene->GetEnemyFactory();
		if (p_enemyFactory->getEnemyCount() > 0)
		{
			p_target = p_enemyFactory->getEnemies(1);
			m_targetPos = p_target->GetPosition();
		}
		else
		{
			//Just move bullet off screen
			m_targetPos = { (float)p_scene->GetSceneWidth() / 2, 0.0f };
		}
		//Set to kill enemies
		m_BulletType = 0;
		//End intitialise
		Initialised = true;
	}

	//Get Bullet Manager
	BulletManager* bulletManager = p_scene->GetBulletManager();
	//Check that bullet is on screen
	if (m_position.GetY() < 0.0f)
	{
		bulletManager->DestroyBullet(m_instanceID);
	}
	else
	{
		//Get the first target available if one exists
		if (p_enemyFactory->getEnemyCount() > 0)
		{
			p_target = p_enemyFactory->getEnemies(1);
			m_targetPos = p_target->GetPosition();
		}
		else
		{
			//Just move bullet off screen
			m_targetPos = { (float)p_scene->GetSceneWidth()/2, 0.0f };
		}
		
		//Check for collision with enemy
		bool collision = BoxCollision(m_position, m_targetPos);
		if (collision == false)
		{
			//Home in on target enemy
			MoveTowardsSmooth(m_targetPos, 48.0f * p_scene->DeltaTime());
		}
		else
		{
			bulletManager->DestroyBullet(m_instanceID);
		}
	}
}

void Powerup_Homing::Draw()
{
	//Draw the sprite
	if (m_position.GetY() < 240.0f)
	{
		m_transform = new olc::GFX2D::Transform2D;
		m_transform->Translate(-m_spriteOriginX, -m_spriteOriginY);
		m_transform->Rotate(m_rotation);
		m_transform->Translate(m_position.GetX(), m_position.GetY());
		olc::GFX2D::DrawSprite(m_sprite, *m_transform);
	}
}