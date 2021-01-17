#pragma once
#ifndef __ENTITY_H__
#define __ENTITY_H__

#define OLC_PGEX_GRAPHICS2D

// Includes
#include "olcPixelGameEngine.h"
#include "olcPGEX_Graphics2D.h"
#include "Vector2D.h"

class Scene;

//This class defines all entities within the game and contains functions, methods and variables that can or are used by all entites in the game
class Entity
{
public:
	//Entities should not be Constructed and used as they are therefore instead they allow for children to call a common Constructor and destructor
	void CommonConstructor(Scene* a_scene);
	void CommonDestructor();
	//Functions
	void MoveTowards(Vector2D a_position, float a_speed);						//Moves the object without taking rotation into account
	void MoveTowardsSmooth(Vector2D a_position, float a_speed);					//Moves the object to towards a position while taking rotation into account
	void rotateTowards(Vector2D a_position, float a_speed);						//rotates an object towards a vector position
	virtual bool BoxCollision(Vector2D a_position, Vector2D a_otherPosition);	//Handles collision between entities
	bool OutOfBounds(float x1, float x2, float y1, float y2);					//Checks if an entity is out of bounds

	//Getters and Setters
	olc::Sprite* GetSprite() { return m_sprite; }
	Vector2D& GetPosition() { return m_position; }
	int GetHealth() { return m_health; }

	void SetSprite(olc::Sprite* a_sprite, bool a_centerOrigin = false, float a_originX = 0.0f, float a_originY = 0.0f);	//Allows entity sprites to be set quickly and also allows for custom origin points
 	void SetPosition(Vector2D a_position) { m_position = a_position; }
	void SetHealth(int a_health) { m_health = a_health; }

protected:
	//Pointers
	Scene* p_scene;
	olc::Sprite* m_sprite;
	olc::GFX2D::Transform2D* m_transform;
	
	//transoformation variables
	Vector2D m_position;
	Vector2D m_forwardDirection;
	float m_rotation;

	//Sprite Variables
	int m_spriteWidth;
	int m_spriteHeight;
	float m_spriteOriginX;
	float m_spriteOriginY;
	bool collided;

	//Entity Variables
	int m_health;
	int m_scoreValue;
};
#endif