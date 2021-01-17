//include forward declarations and header
#include "BulletManager.h"
#include "Includes/Scene.h"
#include "Includes/Bullet.h"
#include "Includes/PlayerBomb.h"
#include "Includes/Poweup_Homing.h"
#include "EnemyBullet.h"
#include "Includes/BulletDriftEnemy.h"

BulletManager::BulletManager()
{
	//set the max number of bullets allowed (worked out based on how well olc PGE could handle)
	m_bulletCap = 32;
	//resize the vector to hold max number of bullets
	m_bulletInstances.resize(m_bulletCap);
	//fill vector with nullptr ready to be filled
	for (int i = 0; i < m_bulletCap; i++)
	{
		m_bulletInstances[i] = nullptr;
	}
}

void BulletManager::Update()
{
	//Update all the bullet in the game currently
	for (int i = 0; i < m_bulletCap; i++)
	{
		if (m_bulletInstances[i] != nullptr)
		{
			m_bulletInstances[i]->Update();
		}
	}
}

void BulletManager::Draw()
{
	//Draw all the bullet in the game currently
	for (int i = 0; i < m_bulletCap; i++)
	{
		if (m_bulletInstances[i] != nullptr)
		{
			m_bulletInstances[i]->Draw();
		}
	}
}

void BulletManager::CreateBullet(BulletType a_Instance, Scene* a_Scene, Vector2D a_Position)
{
	//Based what Bullet type is passed into the fucntion, intiialise that specific bullet and adjust size of vector with count
	switch (a_Instance)
	{
	case PlayerBullet:
	{
		//if there is free space in vector not above the bullet cap then create the bullet
		for (int i = 0; i < m_bulletCap; i++)
		{
			if (m_bulletInstances[i] == nullptr)
			{
				m_bulletInstances[i] = new Bullet(a_Scene, i);
				m_bulletInstances[i]->SetPosition(a_Position);
				break;
			}
		}
		break;
	}
	case Bomb:
	{
		for (int i = 0; i < m_bulletCap; i++)
		{
			if (m_bulletInstances[i] == nullptr)
			{
				m_bulletInstances[i] = new PlayerBomb(a_Scene, i);
				m_bulletInstances[i]->SetPosition(a_Position);
				break;
			}
		}
		break;
	}
	case PlayerHoming:
	{
		for (int i = 0; i < m_bulletCap; i++)
		{
			if (m_bulletInstances[i] == nullptr)
			{
				m_bulletInstances[i] = new Powerup_Homing(a_Scene, i);
				m_bulletInstances[i]->SetPosition(a_Position);
				break;
			}
		}
		break;
	}
	case EnemyBulletDown:
	{
		for (int i = 0; i < m_bulletCap; i++)
		{
			if (m_bulletInstances[i] == nullptr)
			{
				m_bulletInstances[i] = new BulletEnemy(a_Scene, i);
				m_bulletInstances[i]->SetPosition(a_Position);
				m_bulletInstances[i]->SetDirection(false);
				break;
			}
		}
		break;
	}
	case EnemyBulletUp:
	{
		for (int i = 0; i < m_bulletCap; i++)
		{
			if (m_bulletInstances[i] == nullptr)
			{
				m_bulletInstances[i] = new BulletEnemy(a_Scene, i);
				m_bulletInstances[i]->SetPosition(a_Position);
				m_bulletInstances[i]->SetDirection(true);
				break;
			}
		}
		break;
	}
	case EnemyDrift:
	{
		for (int i = 0; i < m_bulletCap; i++)
		{
			if (m_bulletInstances[i] == nullptr)
			{
				m_bulletInstances[i] = new BulletEnemyDrift(a_Scene, i);
				m_bulletInstances[i]->SetPosition(a_Position);
				break;
			}
		}
		break;
	}
	default:
	{
		break;
	}
	}
	//get updated vectors bullet count
	m_numberOfInstance = CountBullets();
}

void BulletManager::DestroyBullet(int a_InstanceID)
{
	//remove the Bullet from the passed in index and adjust the vector to make room for more new bullets to be created
	delete m_bulletInstances[a_InstanceID];
	m_bulletInstances[a_InstanceID] = nullptr;
	for (int i = a_InstanceID; i < m_bulletCap - 1; i++)
	{
		if (m_bulletInstances[i] == nullptr && m_bulletInstances[i + 1] != nullptr)
		{
			m_bulletInstances[i] = m_bulletInstances[i + 1];
			m_bulletInstances[i]->SetInstanceID(i);
			m_bulletInstances[i + 1] = nullptr;
		}
	}
	//get updated vectors bullet count
	m_numberOfInstance = CountBullets();
}

int BulletManager::CountBullets()
{
	int bulletCounter = 0;
	//count and return how many indexes of the vector are not nullptr
	for (int i = 0; i < m_bulletCap; i++)
	{
		if (m_bulletInstances[i] != nullptr)
		{
			bulletCounter++;
		}
	}
	return bulletCounter;
}