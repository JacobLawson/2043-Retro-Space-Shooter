//includes for header and forward declarations
#include "LifeMeterIcon.h"
#include "Scene.h"
LifeIcon::LifeIcon()
{
	//Set Sprite
	m_sprite = new olc::Sprite("Resources/Life.png");
}

void LifeIcon::Draw()
{
	//Draw Sprite
	m_transform = new olc::GFX2D::Transform2D;
	m_transform->Translate(m_position.GetX(), m_position.GetY());
	olc::GFX2D::DrawSprite(m_sprite, *m_transform);
}
