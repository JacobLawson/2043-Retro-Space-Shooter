#include "Includes\Turret.h"
#include "Includes/Scene.h"
#include "Includes/Ship.h"
#include "BulletManager.h"
#include "EnemyBullet.h"

void Turret::Update()
{
	if (m_initialised == false)
	{
		//Set the sprite
		SetSprite(new olc::Sprite("Resources/TankTurret.png"), true);
		//Get position of player
		p_target = p_scene->GetPlayerShip();
		//object specific
		m_shootTimer = 0.0f;
		m_health = 1;
		m_initialised = true;
	}
	//Face player
	Vector2D targetpos = p_target->GetPosition();
	rotateTowards(targetpos, 1.0f);
	//Move The Enemy Downwards
	m_position.SetY(m_position.GetY() + (32.0f * p_scene->DeltaTime()));
	//fire
	if (m_shootTimer > 2.0f)
	{
		p_bulletManager->CreateBullet(EnemyDrift, p_scene, m_position);
		//reset shoot timer
		m_shootTimer = 0.0f;
	}
	m_shootTimer += 1.0f * p_scene->DeltaTime();

	Collision();
	Death();
}

//Same as parent but it only collides with the bomb
void Turret::Collision()
{
	p_bulletManager = p_scene->GetBulletManager();
	int instancesToCheck = p_bulletManager->getBulletCount();

	for (int i = 0; i < instancesToCheck; i++)
	{
		if (p_bulletManager->getBullet(i) != nullptr)
		{
			Bullet* BulletToCheck = p_bulletManager->getBullet(i);
			//Check for the bomb bullet type
			if (BulletToCheck->GetBulletType() == 1)
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
