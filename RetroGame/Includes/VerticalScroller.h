#pragma once
#ifndef __VERTICAL_SCROLLER__
#define __VERTICAL_SCROLLER__

//includes
#include "olcPixelGameEngine.h"
#include "olcPGEX_Graphics2D.h"

//Forward Declarations
class Scene;
class Ship;

//Vetical scroller that mimics the scrolling of a SHMUP game by working it's way through an array of enemies and slowly spawning them at the right time - sadly it could not handle tiles
class VerticalScroller
{
public:
	//Constructor and destructor
	VerticalScroller(Scene* a_Scene);
	~VerticalScroller();

	//functions
	bool LoadLevel(const char* a_filename);											//Load a level map from file
	void SetMapHeight(int a_mapHeight) { m_mapHeight = a_mapHeight; }				//Set the height of the map
	int GetMapHeight() { return m_mapHeight; }										//Get the height of the map
	void SetScrollSpeed(float a_scrollSpeed) { m_scrollSpeed = a_scrollSpeed; }		//Set the scroll speed of spwaning
	void SpawnEntityRow(bool UpperMarker);											//Get the current row of the array being checked and spawn entities on it
	float GetScrollPosition() { return m_upperScrollPos; }							//Get the upper position of the screen being scrolled

	void Update();
private:
	//Pointer to the scene
	Scene* m_scene;

	olc::Sprite* m_sprite;

	//map and tileset size pointers
	int* m_map;
	int* m_Tiles;

	//Scrolling variables
	float m_scrollSpeed;
	float m_upperScrollPos;
	float m_lowerScrollPos;
	int boom;

	//Width and height of the map divided by 16, the tile size I decided upon
	int m_mapWidth;
	int m_mapHeight;


};

#endif // !__VERTICAL_SCROLLER__
