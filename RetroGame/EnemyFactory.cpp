//Include Header and forward declarations of enemys that can be created
#include "Includes/EnemyFactory.h"
#include "Includes/Enemy.h"
#include "Includes/Enemy_Upwards.h"
#include "Includes/Enemy_SweepLeft.h"
#include "Includes/Enemy_SweepRight.h"
#include "Includes/EnemyFighter_Downwards.h"
#include "Includes/EnemyFighter_Upwards.h"
#include "Includes/Enemy_Missile.h"
#include "Includes/Enemy_Large.h"
#include "Includes/Powerup.h"
#include "Includes/Turret.h"

EnemyFactory::EnemyFactory()
{
	//Pointer to be passed into enemies
	factorypointer = this;
	//set the max number of Enemies allowed (worked out based on how well olc PGE could handle)
	m_enemyCap = 32;
	//resize the vector to hold max number of Enemmies
	m_enemyInstances.resize(m_enemyCap);
	//fill vector with nullptr ready to be filled with actual Enemies
	for (int i = 1; i < m_enemyCap; i++)
	{
		m_enemyInstances[i] = nullptr;
	}
}

void EnemyFactory::Update()
{
	//Update all enemies in game
	for (int i = 1; i < m_enemyCap; i++)
	{
		if (m_enemyInstances[i] != nullptr)
		{
			m_enemyInstances[i]->Update();
		}
	}
}

void EnemyFactory::Draw()
{
	//Draw all enemies in game
	for (int i = 1; i < m_enemyCap; i++)
	{
		if (m_enemyInstances[i] != nullptr)
		{
			m_enemyInstances[i]->Draw();
		}
	}
}

void EnemyFactory::CreateEnemy(EnemyType a_Instance, Scene* a_Scene, Vector2D a_Position)
{
	//Based what enemy type is passed into the fucntion, intiialise that specific Enemy and adjust size of vector with count
	switch (a_Instance)
	{
	case Parent:
	{
		//if there is free space in vector not above the Enemy cap then create the Enemy
		for (int i = 1; i < m_enemyCap; i++)
		{
			if (m_enemyInstances[i] == nullptr)
			{ 
				m_enemyInstances[i] = new Enemy(a_Scene, i, factorypointer);
				m_enemyInstances[i]->SetPosition(a_Position);
				break;
			}
		}
		break;
	}
	case Upwards:
	{
		for (int i = 1; i < m_enemyCap; i++)
		{
			if (m_enemyInstances[i] == nullptr)
			{
				m_enemyInstances[i] = new EnemyUpwards(a_Scene, i, factorypointer);
				m_enemyInstances[i]->SetPosition(a_Position);
				break;
			}
		}
		break;
	}
	case CrosserL:
		for (int i = 1; i < m_enemyCap; i++)
		{
			if (m_enemyInstances[i] == nullptr)
			{
				m_enemyInstances[i] = new EnemySweep_Left(a_Scene, i, factorypointer);
				m_enemyInstances[i]->SetPosition(a_Position);
				break;
			}
		}
		break;
	case CrosserR:
		for (int i = 1; i < m_enemyCap; i++)
		{
			if (m_enemyInstances[i] == nullptr)
			{
				m_enemyInstances[i] = new EnemySweep_Right(a_Scene, i, factorypointer);
				m_enemyInstances[i]->SetPosition(a_Position);
				break;
			}
		}
		break;
	case FighterD:
		for (int i = 1; i < m_enemyCap; i++)
		{
			if (m_enemyInstances[i] == nullptr)
			{
				m_enemyInstances[i] = new EnemyFighter_Downwards(a_Scene, i, factorypointer);
				m_enemyInstances[i]->SetPosition(a_Position);
				break;
			}
		}
		break;
	case FighterU:
		for (int i = 1; i < m_enemyCap; i++)
		{
			if (m_enemyInstances[i] == nullptr)
			{
				m_enemyInstances[i] = new EnemyFighter_Upwards(a_Scene, i, factorypointer);
				m_enemyInstances[i]->SetPosition(a_Position);
				break;
			}
		}
		break;
	case Missile:
		for (int i = 1; i < m_enemyCap; i++)
		{
			if (m_enemyInstances[i] == nullptr)
			{
				m_enemyInstances[i] = new Enemy_Missile(a_Scene, i, factorypointer);
				m_enemyInstances[i]->SetPosition(a_Position);
				break;
			}
		}
		break;
	case Scatter:
		for (int i = 1; i < m_enemyCap; i++)
		{
			if (m_enemyInstances[i] == nullptr)
			{
				m_enemyInstances[i] = new Enemy_Large(a_Scene, i, factorypointer);
				m_enemyInstances[i]->SetPosition(a_Position);
				break;
			}
		}
		break;
	case PlayerPowerup:
		for (int i = 1; i < m_enemyCap; i++)
		{
			if (m_enemyInstances[i] == nullptr)
			{
				m_enemyInstances[i] = new Powerup(a_Scene, i, factorypointer);
				m_enemyInstances[i]->SetPosition(a_Position);
				break;
			}
		}
		break;
	case GroundTurret:
		for (int i = 1; i < m_enemyCap; i++)
		{
			if (m_enemyInstances[i] == nullptr)
			{
				m_enemyInstances[i] = new Turret(a_Scene, i, factorypointer);
				m_enemyInstances[i]->SetPosition(a_Position);
				break;
			}
		}
		break;
	default:
	{
		break;
	}
	}
	//get updated vectors Enemy count
	m_numberOfInstance = CountEnemies();
}

void EnemyFactory::DestroyEnemy(int a_InstanceID)
 {
	//remove the enemy from the passed in index and adjust the vector to make room for more new bullets to be created
 	delete m_enemyInstances[a_InstanceID];
	m_enemyInstances[a_InstanceID] = nullptr;
	for (int i = a_InstanceID; i < m_enemyCap-1; i++)
	{
		if (m_enemyInstances[i] == nullptr && m_enemyInstances[i + 1] != nullptr)
		{
			m_enemyInstances[i] = m_enemyInstances[i + 1];
			m_enemyInstances[i]->SetInstanceID(i);
			m_enemyInstances[i + 1] = nullptr;
		}
	}
	//get updated vectors Enemy count
	m_numberOfInstance = CountEnemies();
}

int EnemyFactory::CountEnemies()
{
	int EnemyCounter = 0;
	//count and return how many indexes of the vector are not nullptr
	for (int i = 0; i < m_enemyCap; i++)
	{
		if (m_enemyInstances[i] != nullptr)
		{
			EnemyCounter++;
		}
	}
	return EnemyCounter;
}