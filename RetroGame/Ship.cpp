//This file's header
#include "Ship.h"

//Includes
#include "Includes/Scene.h"
#include "Includes/EnemyFactory.h"
#include "BulletManager.h"
#include "Includes/Bullet.h"

// Namespaces
using namespace olc;

Ship::Ship()
{
	// Load our sprite
	m_sprite = new Sprite("Resources/PlayerShip1.png");
	m_spriteWidth = m_sprite->width;
	m_spriteHeight = m_sprite->height;
	m_spriteOriginX = m_spriteWidth * 0.5f;
	m_spriteOriginY = m_spriteHeight * 0.5f;
	m_rotation = 32.0f;

	// Set the position vector
	m_position = { 100.0f, 100.0f };

	m_powerupHoming = false;
}

void Ship::Update(Scene* pScene)
{
	// Handle input and only allow movement when player is on screen
	if (pScene->GetKey(Key::W).bHeld && m_position.GetY() > 0.0f)
	{
		m_position.SetY(m_position.GetY() - (32.0f * pScene->DeltaTime()));
	}
	if (pScene->GetKey(Key::A).bHeld && m_position.GetX() > 0.0f)
	{
		m_position.SetX(m_position.GetX() - (32.0f * pScene->DeltaTime()));
	}
	if (pScene->GetKey(Key::S).bHeld && m_position.GetY() < 250.0f)
	{
		m_position.SetY(m_position.GetY() + (32.0f * pScene->DeltaTime()));
	}
	if (pScene->GetKey(Key::D).bHeld && m_position.GetX() < 260.0f)
	{
		m_position.SetX(m_position.GetX() + (32.0f * pScene->DeltaTime()));
	}
	BulletManager* bulletManager = pScene->GetBulletManager();
	m_bulletOffset = m_position + (Vector2D{ -m_spriteOriginX + 12.0f, -m_spriteOriginY - 5.0f });
	if (pScene->GetKey(Key::SPACE).bPressed)
	{		
		bulletManager->CreateBullet(PlayerBullet, pScene, m_bulletOffset);
		if (m_powerupHoming == true)
		{
			bulletManager->CreateBullet(PlayerHoming, pScene, m_bulletOffset);
		}
	}
	if (pScene->GetKey(Key::SHIFT).bPressed)
	{
		bulletManager->CreateBullet(Bomb, pScene, m_bulletOffset);
	}
}

void Ship::Draw(Scene* pScene)
{
	//Draw Player Sprite
	m_transform = new GFX2D::Transform2D;
	m_transform->Translate(-m_spriteOriginX, -m_spriteOriginY);
	m_transform->Translate(m_position.GetX(), m_position.GetY());
	olc::GFX2D::DrawSprite(m_sprite, *m_transform);
}

void Ship::Collision(Scene* pScene)
{
	//Check for collisions with enemies and enemy bullets
	EnemyFactory* enemyFactory = pScene->GetEnemyFactory();
	int instancesToCheck = enemyFactory->getEnemyCount();
	for (int i = 0; i < instancesToCheck; i++)
	{
		if (enemyFactory->getEnemies(i) != nullptr)
		{
			Enemy* enemyToCheck = enemyFactory->getEnemies(i);
			collided = BoxCollision(m_position, enemyToCheck->GetPosition());
			if (collided == true)
			{
				pScene->SetLivesCount(pScene->GetLivesCount() - 1);
				pScene->PlayerDeath();
				instancesToCheck = 0;
			}
			else
			{
				BulletManager* bulletManager = pScene->GetBulletManager();
				instancesToCheck = bulletManager->getBulletCount();

				for (int i = 0; i < instancesToCheck; i++)
				{
					if (bulletManager->getBullet(i) != nullptr)
					{
						Bullet* BulletToCheck = bulletManager->getBullet(i);
						if (BulletToCheck->GetBulletType() > 1)
						{
							collided = BoxCollision(m_position, BulletToCheck->GetPosition());
							if (collided == true)
							{
								bulletManager->DestroyBullet(i);
								pScene->SetLivesCount(pScene->GetLivesCount() - 1);
								pScene->PlayerDeath();
								instancesToCheck = 0;
							}
						}
					}
				}
			}
		}
	}
}
