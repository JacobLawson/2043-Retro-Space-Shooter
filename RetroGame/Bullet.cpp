// Includes
#include "Bullet.h"
#include "Enemy.h"
#include "Includes/EnemyFactory.h"
#include "BulletManager.h"
#include "Includes/Scene.h"

using namespace olc;

Bullet::Bullet(Scene* a_Scene, int m_instanceID)
{
	m_BulletType = 3;	//Default bullet type kills nothing so that it prevents destroying objects that created it
	p_scene = a_Scene;  //Get pointer to screen
	//Set Sprite
	SetSprite(new olc::Sprite("Resources/Bullet.png"));
}

Bullet::~Bullet()
{
	p_enemyFactory = nullptr;
}

void Bullet::Update()
{
	//Update the bullet type so that it kills enemies in the air only
	m_BulletType = 0;
	//Get Bullet Manager
	BulletManager* bulletManager = p_scene->GetBulletManager();
	//Check that bullet is on screen
	if (m_position.GetY() < 0.0f)
	{
		bulletManager->DestroyBullet(m_instanceID);
	}
	else
	{
		//Move
		m_position.SetY(m_position.GetY() - (64.0f * p_scene->DeltaTime()));
	}
}

void Bullet::Draw()
{
	//Draw the sprite via Transform
	m_transform = new GFX2D::Transform2D;
	m_transform->Translate(m_position.GetX(), m_position.GetY());
	olc::GFX2D::DrawSprite(m_sprite, *m_transform);
}