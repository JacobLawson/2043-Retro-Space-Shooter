#pragma once
#ifndef __LIFE_METER_ICON_H__
#define __LIFE_METER_ICON_H__

// Includes
#include "olcPixelGameEngine.h"
#include "olcPGEX_Graphics2D.h"
#include "Vector2D.h"

//This class defines the icons used to draw lives during gameplay
class LifeIcon {
public:
	//Constructor and Destructor
	LifeIcon();
	~LifeIcon();

	void Update();
	void Draw();

	void SetPosition(Vector2D a_position) { m_position = a_position; };
private:
	//Object specific variables
	olc::Sprite* m_sprite;
	Vector2D m_position;
	olc::GFX2D::Transform2D* m_transform;
};


#endif // !__LIFE_METER_ICON_H__
