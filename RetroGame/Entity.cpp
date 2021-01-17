#define _USE_MATH_DEFINES
//includes for header and forward declarations
#include "Includes/Entity.h"
#include "Includes/Scene.h"
#include <math.h>

void Entity::CommonConstructor(Scene* a_scene)
{
	//initialise pointers to the scene required for all entites to use
	p_scene = a_scene;
	
	//transformation variables
	m_position = { 0.0f, 0.0f };
	m_forwardDirection = { 0.0f, 0.0f };
	m_rotation = 0.0f;

	//Entity variables
	m_health = 1;
	m_scoreValue = 100;
}

void Entity::CommonDestructor()
{
	//lose pointers
	p_scene = nullptr;
	m_sprite = nullptr;
}

void Entity::MoveTowards(Vector2D a_position, float a_speed)
{
	//Gets the difference between the entites and another point and moves the position towards the other point.
	//this does not consider rotations
	Vector2D vectorDif = a_position - m_position;
	if (vectorDif.GetX() < 0.0f)
	{
		vectorDif.SetX(-1.0f);
	}
	else
	{
		vectorDif.SetX(1.0f);
	}
	if (vectorDif.GetY() < 0.0f)
	{
		vectorDif.SetY(-1.0f);
	}
	else
	{
		vectorDif.SetY(1);
	}
	//actually move
	m_position.SetX(m_position.GetX() + ((a_speed * p_scene->DeltaTime()) * vectorDif.GetX()));
	m_position.SetY(m_position.GetY() + ((a_speed * p_scene->DeltaTime()) * vectorDif.GetY()));
}

void Entity::MoveTowardsSmooth(Vector2D a_position, float a_speed)
{
	//Move towards point taking rotation into consideration
	//rotate towards the point 
	rotateTowards(a_position, 1.0f);
	float rotationOffeset = m_rotation;

	//move in direction of rotation
	m_forwardDirection.SetX(cos(-rotationOffeset));
	m_forwardDirection.SetY(sin(-rotationOffeset));

	m_position += (m_forwardDirection * a_speed);
}

void Entity::rotateTowards(Vector2D a_position, float a_speed)
{
	m_rotation = atan2((-a_position.GetY()) - (-m_position.GetY()), a_position.GetX() - m_position.GetX());
};

//check collision between two positions
bool Entity::BoxCollision(Vector2D a_position, Vector2D a_otherPosition)
{
	int myX = a_position.GetX();
	int myY = a_position.GetY();
	int theirX = a_otherPosition.GetX();
	int theirY = a_otherPosition.GetY();

	if (myX < theirX + m_spriteWidth &&
		myX + m_spriteWidth > theirX&&
		myY < theirY + m_spriteHeight &&
		myY + m_spriteHeight > theirY)
	{
		return true;
	}
	else
	{
		return false;
	}
}

//Check if enemy is out of bounds
bool Entity::OutOfBounds(float x1, float x2, float y1, float y2)
{
	if (m_position.GetX() < x1 || m_position.GetX() > x2 ||
		m_position.GetY() < y1 || m_position.GetY() > y2)
	{
		return true;
	}
	return false;
}

//Set the sprite of the entity
//use it's own function to easily control origins of sprites
void Entity::SetSprite(olc::Sprite* a_sprite, bool a_centerOrigin, float a_originX, float a_originY)
{
	m_sprite = a_sprite;
	m_spriteWidth = m_sprite->width;
	m_spriteHeight = m_sprite->height;
	if (a_centerOrigin == true)
	{
		m_spriteOriginX = m_spriteWidth * 0.5f;
		m_spriteOriginY = m_spriteHeight * 0.5f;
	}
	else
	{

		m_spriteOriginX = a_originX;
		m_spriteOriginY = a_originY;
	}
}