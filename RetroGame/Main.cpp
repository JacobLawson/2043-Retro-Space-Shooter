#define OLC_PGE_APPLICATION
//includes for header and forward declarations
#include "olcPixelGameEngine.h"
#include "Includes/olcPGEX_Graphics2D.h"
#include "Scene.h"

int main()
{
	// Entry point for our game
	Scene retroGameScene;
	if (retroGameScene.Construct(256, 240, 2, 2))
	{
		retroGameScene.Start();
	}

	return 0;
}