//includes for header and forward declarations
#include "Includes\Enemy_Large.h"
#include "Includes/Scene.h"
#include "Includes/Ship.h"
#include "Includes/EnemyFactory.h"

void Enemy_Large::Update()
{
	//Run normal constructor once
	if (Initialised == false)
	{
		//get position of player
		m_targetPos = p_Ship->GetPosition();
		//Set the sprite
		SetSprite(new olc::Sprite("Resources/LargeEnemy.png"), true);

		//Variables for this object
		m_TurnPos = false;
		m_health = 15;
		//End initialisation
		Initialised = true;
	}
	
	//Check that Enemy is on screen
	if (m_position.GetY() > 240.0f)
	{
		p_enemyFactory->DestroyEnemy(m_instanceID);
	}
	else
	{
		//If the enemy hasn't reached it's first target then don't move to next
		if (m_TurnPos == false)
		{
			bool collision = BoxCollision(m_position, m_targetPos);
			if (collision == false)
			{
				//Move, check for collisions and handle death if it happens
				MoveTowardsSmooth(m_targetPos, 48.0f * p_scene->DeltaTime());
				Collision();
				Death();
			}
			else
			{
				//hit i's target now move off screen
				m_TurnPos = true;
			}
		}
		else
		{
			//move off screen
			MoveTowardsSmooth({ (float)p_scene->GetSceneWidth() / 2, 0.0f }, 48.0f * p_scene->DeltaTime());
			//still handle collisions and death if they happen
			Collision();
			Death();
			//when off screen delete this
			if (m_position.GetY() < 0.0f)
			{
				p_enemyFactory->DestroyEnemy(m_instanceID);
			}
		}
	}
}
