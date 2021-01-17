#pragma once
#ifndef SCENE_H
#define SCENE_H

// Includes
#include "olcPixelGameEngine.h"
#include "olcPGEX_Graphics2D.h"
#include <sstream>

// Forward declarations
class Decal;
class Ship;
class Bullet;
class Enemy;
class EnemyFactory;
class BulletManager;
class VerticalScroller;
class TileData;
class Reticle;
class LifeIcon;

//The scene controls everything in the game from the state of the game to updating the objects and drawing. 
class Scene : public olc::PixelGameEngine
{
public:
	//Enumerator for the game state. switched based on state to run different parts of the game
	enum GameStates 
	{
		SPLASHSCREEN,
		TITLESCREEN,
		HIGHSCORE,
		OPTIONS,
		GAMEPLAY,
		MAPSCREEN
	};

	//an enumerator for switching background colours. used for creating the different level themes
	enum Colours
	{
		cBLACK,
		cBLUE,
		cGREEN,
		cGREY,
		cRED
	};

	//Constructor
	Scene();

	//Scene controlling fuctions
	bool OnUserCreate() override;						//Ran at start
	bool OnUserUpdate(float fElapsedTime) override;		//Ran every frame
	void RedrawScene();									//Redraws and clears the screen
	void UpdateBackground(Colours a_colour);			//Changes the background colour


	//State Specific Methods - Each state has an update and draw function
	void TitleScreenUpdate();
	void TitleScreenDraw();
	void HighScoreUpdate();
	void HighScoreDraw();
	void OptionsUpdate();
	void OptionsDraw();
	void GameplayUpdate();
	void GameplayDraw();
	void MapUpdate();
	void MapDraw();


	//Getters and setters
	//Get pointers to objects
	EnemyFactory* GetEnemyFactory() { return enemyFactory; }
 	BulletManager* GetBulletManager() { return bulletManager; }
	Ship* GetPlayerShip() { return playerShip; }
	Reticle* GetPlayerReticle() { return playerReticle; }

	//Get the scene width and height (very useful for drawing menus)
	int GetSceneWidth() { return m_screenWidth; }
	int GetSceneHeight() { return m_screenHeight; }

	//Gameplay getters and setters for lives and scores
	int GetLivesCount() { return m_playerLives; }
	void SetLivesCount(int a_lives) { m_playerLives = a_lives; }
	void SetScore(int a_newScore) { m_playerScore = a_newScore; }
	void UpdateScore(int a_scoreIncrease) { m_playerScore += a_scoreIncrease; }

	void PlayerDeath();	//Handle what happens when the player dies in game
	void ClearGameplayObjects(); //destroy all gameplay objects
	void BubbleSort();	//sort the highscore table

	//Get the delta time
	float DeltaTime() { return deltaTime; }

private:
	//Enum variables for switch statements
	GameStates m_state;
	Colours bgColour;

	//Screen size
	int m_screenWidth;
	int m_screenHeight;
	
	//State controls
	bool m_stateInitialised;
	bool m_quit;

	//Menus
	int playerProgress;
	int MenuIndex;
	int m_opitionIndex;
	int m_maxIndex;

	//Lives
	int m_playerLives;
	std::vector<LifeIcon*> m_currentLifeIcons;
	int m_highscores[5];

	//Menu pointers
	Decal* p_MenuSelect;
	
	//Map screen pointers
	Decal* p_MapEarth;
	Decal* p_MapSpaceFleet;
	Decal* p_MapMoon;
	Decal* p_MapMars;
	std::string m_CurrentMissionString;

	//Gameplay ponters
	Ship* playerShip;
	Reticle* playerReticle;
	Bullet* bullet;
	BulletManager* bulletManager;
	EnemyFactory* enemyFactory;
	VerticalScroller* verticalScroller;
	TileData* tileData;
	olc::Sprite* sprite;

	//other variables
	int stageHeight = 30;
	int windowWidth = 256/16;
	int windowHeight = 240/16;
	int screenTop = stageHeight - windowHeight;
	int screenBottom = stageHeight;
	float m_gameplayTimer;
	float deltaTime;

	int m_playerScore;

	int TileMap1;

	TileData* tileDataArray[30][16];
	
	float m_transitionTimer;
	bool m_mapTransition;

	const char* m_levelFile;

	bool done;
};

#endif //!SCENE_H
