#include "Includes\Enemy_Missile.h"
#include "Includes/Scene.h"
#include "Includes/Ship.h"

void Enemy_Missile::Update()
{
	//Run normal constructor once
	if (m_initialsed == false)
	{
		//Set sprite
		SetSprite(new olc::Sprite("Resources/Rocket.png"), true);
		//end initialisation
		m_initialsed = true;
	}

	//Move towards player constantly
	MoveTowardsSmooth(p_Ship->GetPosition(), 48.0f * p_scene->DeltaTime());
	//Handle collisions
	Collision();
	//Handle Death
	Death();
}
