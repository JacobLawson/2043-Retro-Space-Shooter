//inclides for forward declarations
#include "Includes/BulletDriftEnemy.h"
#include "Includes/Scene.h"
#include "Includes/Ship.h"
#include "BulletManager.h"

void BulletEnemyDrift::Update()
{
	//Run normal constructor once
	if (Initialised == false)
	{
		//Set the Sprite
		SetSprite(new olc::Sprite("Resources/EnemyProjectile.png"), true);
		//Get the initial position of the player
		p_target = p_scene->GetPlayerShip();
		m_targetPos = p_target->GetPosition();
		//Set enemy bullet to collide with player
		m_BulletType = 2;
		//End initialsisation
		Initialised = true;
	}

	//Get Bullet Manager
	BulletManager* bulletManager = p_scene->GetBulletManager();
	//Check that bullet is on screen
	if (m_position.GetY() < 0.0f || m_position.GetY() > 250.0f)
	{
		bulletManager->DestroyBullet(m_instanceID);
	}
	else
	{
		//check if it has reached target position
		bool collision = BoxCollision(m_position, m_targetPos);
		if (collision == false)
		{
			//move towards target vector with rotation
			MoveTowardsSmooth(m_targetPos, 48.0f * p_scene->DeltaTime());
		}
		else
		{
			//destroy bullet
			bulletManager->DestroyBullet(m_instanceID);
		}

	}
}

void BulletEnemyDrift::Draw()
{
	//Draw transformation (with rotations)
	if (m_position.GetY() < 240.0f)
	{
		m_transform = new olc::GFX2D::Transform2D;
		m_transform->Translate(-m_spriteOriginX, -m_spriteOriginY);
		m_transform->Translate(m_position.GetX(), m_position.GetY());
		olc::GFX2D::DrawSprite(m_sprite, *m_transform);
	}
}
