//includes for header and forward declarations
#include "Includes\EnemyFighter_Upwards.h"
#include "Includes/Scene.h"
#include "BulletManager.h"

void EnemyFighter_Upwards::Update()
{
	//Run normal constructor once
	if (m_initialised == false)
	{
		//Set the sprite
		SetSprite(new olc::Sprite("Resources/ShooterUp.png"));
		//Variables for this object
		m_shootTimer = 0.0f;
		m_health = 3;
		//End initialisation
		m_initialised = true;
	}
	//Move The Enemy Downwards
	m_position.SetY(m_position.GetY() - (32.0f * p_scene->DeltaTime()));
	//fire
	if (m_shootTimer > 2.0f)
	{
		p_bulletManager->CreateBullet(EnemyBulletUp, p_scene, m_position);
		m_shootTimer = 0.0f;
	}
	m_shootTimer += 1.0f * p_scene->DeltaTime();

	Collision();
	Death();
}
