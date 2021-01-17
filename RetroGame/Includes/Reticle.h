#ifndef __RETICLE_H__
#define __RETICLE_H__

// Includes
#include "olcPixelGameEngine.h"
#include "olcPGEX_Graphics2D.h"
#include "Vector2D.h"
#include "Entity.h"

// Forward declarations
class Scene;
class Ship;

//The Reticle can be independently moved and player bombs will move towards it in order to target ground turrets
class Reticle : public Entity
{
public:
	// Constructor / Destructor
	Reticle(Scene* a_scene, Ship* a_Ship);
	~Reticle() {}

	// Functions
	void Update(Scene* pScene);
	void Draw(Scene* pScene);

private:
	//pointer to player Ship
	Ship* p_Ship;
};

#endif //!SHIP_H
