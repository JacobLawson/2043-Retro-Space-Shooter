//Include Header and forward declaration
#include "Includes/Enemy_SweepRight.h"
#include "Includes/Scene.h"

void EnemySweep_Right::Update()
{
	SetSprite(new olc::Sprite("Resources/Enemy.png"),true);
	//Move towards bottom Right of screen
	MoveTowardsSmooth({ (float)p_scene->GetSceneWidth()+16, (float)p_scene->GetSceneHeight()+16 }, 64.0f * p_scene->DeltaTime());
	Collision();
	Death();
}
