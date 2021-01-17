//Include Header and forward declaration
#include "Includes/Enemy_Upwards.h"
#include "Includes/EnemyFactory.h"
#include "Includes/Scene.h"
#include "Includes/Ship.h"

void EnemyUpwards::Update()
{
	//Move The Enemy Upwards
	m_position.SetY(m_position.GetY() - (32.0f * p_scene->DeltaTime()));
	Collision();
	Death();
}