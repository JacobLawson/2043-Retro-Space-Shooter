#include "Includes\Decal.h"

Decal::Decal(Scene* a_Scene)
{
	//initialise the object
	CommonConstructor(a_Scene);
}

Decal::~Decal()
{
}

void Decal::Draw(Scene* pScene)
{ 
	//Draw scalable sprite
	m_transform = new olc::GFX2D::Transform2D;
	m_transform->Scale(m_xScale, m_yScale);
	m_transform->Translate(m_position.GetX(), m_position.GetY());
	olc::GFX2D::DrawSprite(m_sprite, *m_transform);
}
