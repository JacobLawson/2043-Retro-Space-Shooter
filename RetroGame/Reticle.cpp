#include "Includes\Reticle.h"
#include "Includes/Scene.h"
#include "Ship.h"

Reticle::Reticle(Scene* a_scene, Ship* a_Ship)
{
	//Set Ship
	p_Ship = a_Ship;
	//Set sprite
	SetSprite(new olc::Sprite("Resources/Reticle.png"));
	CommonConstructor(a_scene);
	//Set the inital position
	SetPosition(Vector2D{ p_Ship->GetPosition().GetX(), p_Ship->GetPosition().GetY() - 48.0f });
}

void Reticle::Update(Scene* pScene)
{
	//Handle Movement, this takes both the players position and the reticles position into account so it will move when player moves but is independent of it too
	if (pScene->GetKey(olc::Key::UP).bHeld && m_position.GetY() > 0.0f)
	{
		m_position.SetY(m_position.GetY() - (48.0f * pScene->DeltaTime()));
	}
	else if (pScene->GetKey(olc::Key::W).bHeld && m_position.GetY() > 0.0f)
	{
		m_position.SetY(m_position.GetY() - (32.0f * pScene->DeltaTime()));
	}
	if (pScene->GetKey(olc::Key::LEFT).bHeld && m_position.GetX() > 0.0f)
	{
		m_position.SetX(m_position.GetX() - (48.0f * pScene->DeltaTime()));
	}
	else if (pScene->GetKey(olc::Key::A).bHeld && m_position.GetX() > 0.0f)
	{
		m_position.SetX(m_position.GetX() - (32.0f * pScene->DeltaTime()));
	}
	if (pScene->GetKey(olc::Key::RIGHT).bHeld && m_position.GetX() < 256.0f)
	{
		m_position.SetX(m_position.GetX() + (48.0f * pScene->DeltaTime()));
	}
	else if (pScene->GetKey(olc::Key::D).bHeld && m_position.GetX() < 256.0f)
	{
		m_position.SetX(m_position.GetX() + (32.0f * pScene->DeltaTime()));
	}
	
	//Make sure Reticle cannot go bellow the player
	Vector2D playerPosition = p_Ship->GetPosition();
	if (m_position.GetY() < playerPosition.GetY() - 48.0f)
	{
		if (pScene->GetKey(olc::Key::DOWN).bHeld)
		{
			m_position.SetY(m_position.GetY() + (48.0f * pScene->DeltaTime()));
		}
		else if (pScene->GetKey(olc::Key::S).bHeld)
		{
			m_position.SetY(m_position.GetY() + (32.0f * pScene->DeltaTime()));
		}
	}
}

void Reticle::Draw(Scene* pScene)
{
	//Draw Reticle
	m_transform = new olc::GFX2D::Transform2D;
	m_transform->Translate(-m_spriteOriginX, -m_spriteOriginY);
	m_transform->Translate(m_position.GetX(), m_position.GetY());

	olc::GFX2D::DrawSprite(m_sprite, *m_transform);
}
