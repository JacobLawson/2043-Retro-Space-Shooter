#ifndef SHIP_H
#define SHIP_H

// Includes
#include "olcPixelGameEngine.h"
#include "olcPGEX_Graphics2D.h"
#include "Vector2D.h"
#include "Entity.h"

// Forward declarations
class Scene;

//The player ship, controlled by player
class Ship : public Entity
{
public:
	// Constructor / Destructor
	Ship();
	~Ship() {}

	// Functions
	void Update(Scene* pScene);
	void Draw(Scene* pScene);
	void Collision(Scene* pScene);

	//Set whether or not the player should have homing attack
	void SetPowerUp(bool a_poweredUp) { m_powerupHoming = a_poweredUp; }

private:
	// Variables
	bool m_powerupHoming;
	Vector2D m_bulletOffset; //Where to spawn bullets
};
#endif //!SHIP_H
