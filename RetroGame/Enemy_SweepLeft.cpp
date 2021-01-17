//Include Header and forward declaration
#include "Includes\Enemy_SweepLeft.h"
#include "Includes/Scene.h"

void EnemySweep_Left::Update()
{
	SetSprite(new olc::Sprite("Resources/Enemy.png"),true);
	//Move towards bottom Left of screen
	MoveTowardsSmooth({ 0.0f, (float)p_scene->GetSceneHeight() + 16 }, 64.0f * p_scene->DeltaTime());
	Collision();
	Death();
}
