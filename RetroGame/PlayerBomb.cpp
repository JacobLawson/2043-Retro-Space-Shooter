//includes for header and forward declarations
#include "PlayerBomb.h"
#include "Enemy.h"
#include "BulletManager.h"
#include "Scene.h"
#include "Reticle.h"

void PlayerBomb::Update()
{
	//Run normal constructor once
	if (Initialised == false)
	{
		//Set the bomb to collide with ground enemies only
		m_BulletType = 1;
		//Set Sprite
		SetSprite(new olc::Sprite("Resources/Bomb.png"), true);
		//Get reticle Position
		p_target = p_scene->GetPlayerReticle();
		m_targetPos = p_target->GetPosition();
		//End initialisation
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
		//if it hasn't collided with reticle it can still move towards it
		bool collision = BoxCollision(m_position, m_targetPos);
		if (collision == false)
		{
			MoveTowardsSmooth(m_targetPos, 48.0f * p_scene->DeltaTime());
		}
		else
		{
			bulletManager->DestroyBullet(m_instanceID);
		}

	}
}

void PlayerBomb::Draw()
{
	//Check bomb is still on screen
	if (m_position.GetY() < 240.0f)
	{
		//Draw Sprite
		m_transform = new olc::GFX2D::Transform2D;
		m_transform->Translate(-m_spriteOriginX, -m_spriteOriginY);
		m_transform->Rotate(m_rotation);
		m_transform->Translate(m_position.GetX(), m_position.GetY());
		olc::GFX2D::DrawSprite(m_sprite, *m_transform);
	}
}
