//includes
#include "Includes\Powerup.h"
#include "BulletManager.h"
#include "Includes/Scene.h"
#include "Includes/Bullet.h"
#include "Includes/Ship.h"

void Powerup::Update()
{
	//Set the Sprite
	SetSprite(new olc::Sprite("Resources/PowerShip.png"));
	//Move the powerup down the screen
	m_position.SetY(m_position.GetY() + (32.0f * p_scene->DeltaTime()));
	Collision();
	Death();
}

//Same as the collision for the parent except it grants the homing attack to the player
void Powerup::Collision()
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
					p_Ship->SetPowerUp(true);
					i = instancesToCheck;
				}
			}
		}
	}
}
