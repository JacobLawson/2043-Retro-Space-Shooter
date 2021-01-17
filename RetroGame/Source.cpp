#include "PlayerBomb.h"
#include "Enemy.h"
#include "BulletManager.h"
#include "Scene.h"
#include "Reticle.h"

void PlayerBomb::Update()
{
	Reticle* Target = p_scene->GetPlayerReticle();
	//Get Bullet Manager
	BulletManager* bulletManager = p_scene->GetBulletManager();
	//Check that bullet is on screen
	if (m_position.GetY() < 0.0f)
	{
		bulletManager->DestroyBullet(m_instanceID);
	}
	else
	{
		MoveTowardsSmooth(Target->GetPosition(), 64.0f);
	}
}