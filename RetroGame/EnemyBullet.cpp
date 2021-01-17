//Include Header and forward declarations
#include "Includes/Scene.h"
#include "EnemyBullet.h"
#include "BulletManager.h"


void BulletEnemy::Update()
{
	m_BulletType = 2;
	SetSprite(new olc::Sprite("Resources/EnemyProjectile.png"));
	//Get Bullet Manager
	BulletManager* bulletManager = p_scene->GetBulletManager();
	//Check that bullet is on screen
	if (m_position.GetY() < 0.0f)
	{
		bulletManager->DestroyBullet(m_instanceID);
	}
	else
	{
		//Move in direction set by move upwards
		if (m_moveUpwards == true)
		{
			m_position.SetY(m_position.GetY() - (72.0f * p_scene->DeltaTime()));
		}
		else
		{
			m_position.SetY(m_position.GetY() + (72.0f * p_scene->DeltaTime()));
		}
	}
}
