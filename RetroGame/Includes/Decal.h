#pragma once
#ifndef __DECAL_H__
#define __DECAL_H__
#include "olcPixelGameEngine.h"
#include "olcPGEX_Graphics2D.h"
#include "Vector2D.h"
#include "Entity.h"

class Scene;
class EnemyFactory;
class BulletManager;
class Ship;

//Decals are the closest thing that I could work out for just drawing basic sprites to the screen and are not affiliated with OLC pixel Game engine 2 Decals
//Decals are just a base entity with some extra support for scaling. It saved making a class for every individual menu sprite
class Decal : public Entity
{
public:
	//Destructor and constructor
	Decal(Scene* a_Scene);
	~Decal();

	//functions
	void Update();
	void Draw(Scene* pScene);

	//Functions for on the fly sprite scaling
	float GetXScale() { return m_xScale; }
	void SetXScale(float a_xScale) { m_xScale = a_xScale; }
	float GetYScale() { return m_yScale; }
	void SetYScale(float a_yScale) { m_yScale = a_yScale; }

private:
	//Animation frames
	olc::Sprite* m_currentFrame;
	//scaling variables
	float m_xScale;
	float m_yScale;
};
#endif